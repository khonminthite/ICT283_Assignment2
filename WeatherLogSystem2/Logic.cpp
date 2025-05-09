/**
 * @file Logic.cpp
 * @author Khon Min Thite
 * @brief .cpp file for LogicHelper
 * @version 0.1
 * @date 29-2-2024
 *
 * @version 0.2
 * @date 6-3-2024
 * Change LoadDataFileCSV function to return boolean.
 * True when invalid data
 * False when no invalid data
 * Added Checks for AverageWindSpeedMonth and AverageAirTemperatureMonth function to make sure value is positive before counting it
 * Added check for ConvertWindMStoKMH to be more than 0 to convert else it will return 0
 */

#include "Logic.h"

void Logic::LoadMultiDataFileCSV(ifstream& inputFile, map<int, map<int, map<int, Bst<Weather>>>>& windLog)
{
    string fileName;
    ifstream dataFile;

    //While there is still a line to read in input file
    while(getline(inputFile,fileName))
    {
        //Check if line is not empty/blank
        if(fileName != "")
        {
            //Open the file using the line
            dataFile.open("data/" + fileName);
            if(dataFile.is_open())
            {
                cout << "Loading file: " + fileName << endl;
                if(LoadDataFileCSV(dataFile,windLog) == false)
                {
                    cout << "Error loading data file: " + fileName << endl;
                }
                else
                {
                    cout << "Loaded data file: " + fileName << endl;
                }
                dataFile.close();
            }
            else
            {
                cout << "Error while opening file: " + fileName << endl;
            }
        }
    }
}

bool Logic::LoadDataFileCSV(ifstream& inputFile, map<int, map<int, map<int, Bst<Weather>>>>& windLog)
{
    unsigned int recordCount = 0;
    Validator validateHelp;
    string line, column;
    istringstream row, dateTime, date, time;
    string dateField, timeField;
    string day, month, year;
    string hour, minute;
    Date tempDate;
    Time tempTime;
    Weather tempLog;
    bool re = true;

    // Get and ignore CSV header
    getline(inputFile, line);
    int columnIndices[4] = {-1, -1, -1, -1};

    istringstream headerStream(line);
    string columnName;
    int columnIndex = 0;
    while (getline(headerStream, columnName, ','))
    {
        if (columnName == "WAST") columnIndices[0] = columnIndex;
        else if (columnName == "S") columnIndices[1] = columnIndex;
        else if (columnName == "SR") columnIndices[2] = columnIndex;
        else if (columnName == "T") columnIndices[3] = columnIndex;
        columnIndex++;
    }

    // Loops for each row of record in file
    while (getline(inputFile, line))
    {
        if (line.find_first_not_of(',') == std::string::npos)
        {
            // Handle the line of commas here
            cout << "Warning: Line of commas detected at row " << recordCount + 2 << endl;
            continue;
        }
        if (line != "")
        {
            row.str(line);
            row.clear(); // Clear the stream flags
            string WAST, S, SR, T;
            int index = 0;
            while (getline(row, column, ','))
            {
                if (index == columnIndices[0]) WAST = column;
                else if (index == columnIndices[1]) S = column;
                else if (index == columnIndices[2]) SR = column;
                else if (index == columnIndices[3]) T = column;
                index++;
            }

            // Process WAST column to extract date and time
            dateTime.str(WAST);
            getline(dateTime, dateField, ' ');    // Date part of WAST
            getline(dateTime, timeField, ' ');    // Time part of WAST
            dateTime.clear();

            // Split Date into day, month, and year
            date.str(dateField);
            getline(date, day, '/');    // Day part of date
            getline(date, month, '/'); // Month part of date
            getline(date, year, '/');   // Year part of date
            date.clear();

            // Remove leading zeros and validate date
            day = RemoveLeadingZeros(day);
            month = RemoveLeadingZeros(month);
            year = RemoveLeadingZeros(year);
            if (!validateHelp.IsValidDate(stoi(day), stoi(month), stoi(year)))
            {
                cout << "Error: Invalid date(WAST) detected at row " << recordCount + 2 << endl;
                re = false;
            }
            else
            {
                tempDate.SetDay(stoi(day));
                tempDate.SetMonth(stoi(month));
                tempDate.SetYear(stoi(year));
                tempLog.SetDate(tempDate);
            }

            // Split Time into hour and minute
            time.str(timeField);
            getline(time, hour, ':');   // Hour part of time
            getline(time, minute, ':'); // Minute part of time
            time.clear();

            // Remove leading zeros and validate time
            hour = RemoveLeadingZeros(hour);
            minute = RemoveLeadingZeros(minute);
            if (!validateHelp.IsValid24HourTime(stoi(hour), stoi(minute)))
            {
                cout << "Error: Invalid time(WAST) detected at row: " << recordCount + 2 << endl;
                re = false;
            }
            else
            {
                tempTime.SetHour(stoi(hour));
                tempTime.SetMinute(stoi(minute));
                tempLog.SetTime(tempTime);
            }

            if (validateHelp.IsNumber(S))
            {
                tempLog.SetWindSpeed(stof(S));
            }
            else
            {
                cout << "Error: Invalid Wind Speed(S) detected at row: " << recordCount + 2 << endl;
                re = false;
            }

            if (validateHelp.IsNumber(SR))
            {
                tempLog.SetSolarRadiation(stof(SR));
            }
            else
            {
                cout << "Error: Invalid Solar Radiation(SR) detected at row: " << recordCount + 2 << endl;
                re = false;
            }

            if (validateHelp.IsNumber(T))
            {
                tempLog.SetAirTemp(stof(T));
            }
            else
            {
                cout << "Error: Invalid Ambient Air Temperature(T) detected at row: " << recordCount + 2 << endl;
                re = false;
            }

            // Insert the Weather object into the map
            try
            {
                InsertWeatherToMap(windLog, tempLog);
            }
            catch(const exception& e)
            {
                cerr << e.what() << '\n';
                cout << "Failed to load" << endl;
                re = false;
                break; // Break the loop if an exception is caught
            }

            row.clear();
            recordCount++;
        }
    }
    return re;
}

void Logic::InsertWeatherToMap(map<int, map<int, map<int, Bst<Weather>>>>& windLog, Weather& tempLog)
{
    int logYear = tempLog.GetDate().GetYear();
    int logMonth = tempLog.GetDate().GetMonth();
    int logDay = tempLog.GetDate().GetDay();

    // Check if year exists in windLog
    if(windLog.find(logYear) == windLog.end())
    {
        // Year does not exist, create new maps for month and day
        map<int, map<int, Bst<Weather>>> month;
        map<int, Bst<Weather>> day;
        Bst<Weather> tempBst;
        tempBst.Insert(tempLog);
        day[logDay] = tempBst;
        month[logMonth] = day;
        windLog[logYear] = month;
    }
    else
    {
        // Year exists, check if month exists
        if(windLog[logYear].find(logMonth) == windLog[logYear].end())
        {
            // Month does not exist, create new map for day
            map<int, Bst<Weather>> day;
            Bst<Weather> tempBst;
            tempBst.Insert(tempLog);
            day[logDay] = tempBst;
            windLog[logYear][logMonth] = day;
        }
        else
        {
            // Month exists, check if day exists
            if(windLog[logYear][logMonth].find(logDay) == windLog[logYear][logMonth].end())
            {
                // Day does not exist, create new BST
                Bst<Weather> tempBst;
                tempBst.Insert(tempLog);
                windLog[logYear][logMonth][logDay] = tempBst;
            }
            else
            {
                // Day exists, insert directly
                windLog[logYear][logMonth][logDay].Insert(tempLog);
            }
        }
    }
}

string Logic::RemoveLeadingZeros(string input)
{
    return input.erase(0, min(input.find_first_not_of('0'), input.size() - 1));
}

float Logic::AverageWindSpeedMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year)
{
    BstWeatherHelper BWH;
    float totalWindSpeed = 0.0;
    int count = 0;

    //Check if data of that year exist
    if(windLog.count(year) > 0)
    {
        //Check if data of that year and month exist
        if(windLog.at(year).count(month) > 0)
        {
            //Loops through the month map for each day
            //Get BST <Weather> of each day and get count and total wind speed of each day
            map<int, Bst<Weather>>::const_iterator it;
            for (it = windLog.at(year).at(month).begin(); it != windLog.at(year).at(month).end(); ++it)
            {
                totalWindSpeed += it->second.GetSumValueFloat(&BWH.GetWeatherWindSpeed);
                count += it->second.TreeNodeCount();
            }
        }
        else //No data of that date exist
        {
            return -1;
        }
    }
    else //No data of that date exist
    {
        return -1;
    }
    return totalWindSpeed/count;
}

float Logic::StandardDeviationWindSpeed(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year)
{
    float totalWindSpeed = 0.0;
    Vector<float> windSpeeds;

    // Check if data of that year exist
    if(windLog.count(year) > 0)
    {
        // Check if data of that year and month exist
        if(windLog.at(year).count(month) > 0)
        {
            // Loop through the month map for each day
            for (const auto& dayEntry : windLog.at(year).at(month))
            {
                dayEntry.second.InOrderTraversalFloat([&](Weather& w)
                {
                    windSpeeds.push_back(w.GetWindSpeed());
                    return w.GetWindSpeed();
                });
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

    // Calculate mean
    for (float windSpeed : windSpeeds)
    {
        totalWindSpeed += windSpeed;
    }
    float mean = totalWindSpeed / windSpeeds.size();

    // Calculate variance
    float variance = 0.0;
    for (float windSpeed : windSpeeds)
    {
        variance += pow(windSpeed - mean, 2);
    }
    variance /= windSpeeds.size();

    // Calculate standard deviation
    return sqrt(variance);
}

float Logic::AverageAirTemperatureMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year)
{
    BstWeatherHelper BWH;
    float totalAirTemperature = 0.0;
    int count = 0;

    //Check if data of that year exist
    if(windLog.count(year) > 0)
    {
        //Check if data of that year and month exist
        if(windLog.at(year).count(month) > 0)
        {
            //Loops through the month map for each day
            //Get BST <Weather> of each day and get count and total airTemp of each day
            map<int, Bst<Weather>>::const_iterator it;
            for (it = windLog.at(year).at(month).begin(); it != windLog.at(year).at(month).end(); ++it)
            {
                totalAirTemperature += it->second.GetSumValueFloat(&BWH.GetWeatherAirTemp);
                count += it->second.TreeNodeCount();
            }
        }
        else //No data of that date exist
        {
            return -1;
        }
    }
    else //No data of that date exist
    {
        return -1;
    }
    return totalAirTemperature/count;
}

float Logic::StandardDeviationAirTemperature(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year)
{
    float totalAirTemperature = 0.0;
    Vector<float> airTemperatures;

    // Check if data of that year exist
    if(windLog.count(year) > 0)
    {
        // Check if data of that year and month exist
        if(windLog.at(year).count(month) > 0)
        {
            // Loop through the month map for each day
            for (const auto& dayEntry : windLog.at(year).at(month))
            {
                dayEntry.second.InOrderTraversalFloat([&](Weather& w)
                {
                    airTemperatures.push_back(w.GetAirTemperature());
                    return w.GetAirTemperature();
                });
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

    // Calculate mean
    for (float airTemp : airTemperatures)
    {
        totalAirTemperature += airTemp;
    }
    float mean = totalAirTemperature / airTemperatures.size();

    // Calculate variance
    float variance = 0.0;
    for (float airTemp : airTemperatures)
    {
        variance += pow(airTemp - mean, 2);
    }
    variance /= airTemperatures.size();

    // Calculate standard deviation
    return sqrt(variance);
}

float Logic::SumSolarRadiationMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year)
{
    float totalSolarRadiation = 0.0;
    Vector<float> solarRads;

    // Check if data of that year exist
    if(windLog.count(year) > 0)
    {
        // Check if data of that year and month exist
        if(windLog.at(year).count(month) > 0)
        {
            // Loop through the month map for each day
            for (const auto& dayEntry : windLog.at(year).at(month))
            {
                dayEntry.second.InOrderTraversalFloat([&](Weather& w)
                {
                    // Check if solar radiation is greater than 100 before adding
                    if (w.GetSolarRadiation() > 100)
                    {
                        solarRads.push_back(w.GetSolarRadiation());
                    }
                    return w.GetSolarRadiation();
                });
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

    for (float solarRad : solarRads)
    {
        totalSolarRadiation += solarRad;
    }

    return totalSolarRadiation;
}

string Logic::IntMonthToString(const int &month)
{
    switch (month)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        cout << endl << "Error converting int month to string" << endl;
        return "ERROR";
    }
}

float Logic::ConvertWindMStoKMH(const float &windSpeed)
{
    if(windSpeed < 0)
    {
        return 0;
    }
    return windSpeed * 3.6;
}

float Logic::ConvertSolarRadiationWMtoKWH(const float &radiation)
{
    if (radiation > 0)
    {
        return (radiation/6) /  1000;
    }
    return 0;
}

void Logic::WriteAppendFile(const string& fileName, const string &output)
{
    ofstream OutputFile(fileName, ofstream::app);
    //appends the string and proceed to next line
    OutputFile << output << endl;
    OutputFile.close();
}

float Logic::calculateSPCC(const Vector<float>& x, const Vector<float>& y)
{
    if (x.size() != y.size())
    {
        std::cerr << "Error: Vectors must be of the same size." << std::endl;
        return std::numeric_limits<float>::quiet_NaN();
    }

    float sumX = 0.0, sumY = 0.0;
    for (unsigned i = 0; i < x.size(); ++i)
    {
        sumX += x[i];
        sumY += y[i];
    }
    float meanX = sumX / x.size();
    float meanY = sumY / y.size();

    float sumNumerator = 0.0;
    float sumDenominatorX = 0.0;
    float sumDenominatorY = 0.0;

    for (unsigned i = 0; i < x.size(); ++i)
    {
        sumNumerator += (x[i] - meanX) * (y[i] - meanY);
        sumDenominatorX += (x[i] - meanX) * (x[i] - meanX);
        sumDenominatorY += (y[i] - meanY) * (y[i] - meanY);
    }

    float denominator = std::sqrt(sumDenominatorX * sumDenominatorY);
    if (denominator == 0)
    {
        cerr << "Error: Division by zero." << endl;
        return numeric_limits<float>::quiet_NaN();
    }

    return sumNumerator / denominator;
}

void Logic::extractMonthData(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year, Vector<float>& windSpeeds, Vector<float>& airTemps, Vector<float>& solarRads)
{
    // Check if the year exists in the map
    auto yearIt = windLog.find(year);
    if (yearIt != windLog.end())
    {
        // Check if the month exists for the given year
        auto monthIt = yearIt->second.find(month);
        if (monthIt != yearIt->second.end())
        {
            // Iterate through each day of the month
            for (const auto& dayEntry : monthIt->second)
            {
                dayEntry.second.InOrderTraversalFloat([&](Weather& w)
                    {
                        windSpeeds.push_back(w.GetWindSpeed());
                        return w.GetWindSpeed();
                    });
                dayEntry.second.InOrderTraversalFloat([&](Weather& w)
                    {
                        airTemps.push_back(w.GetAirTemperature());
                        return w.GetAirTemperature();
                    });
                dayEntry.second.InOrderTraversalFloat([&](Weather& w)
                    {
                        solarRads.push_back(w.GetSolarRadiation());
                        return w.GetSolarRadiation();
                    });
            }
        }
    }
}
