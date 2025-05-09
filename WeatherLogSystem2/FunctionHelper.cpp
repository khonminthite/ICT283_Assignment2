/**
 * @file FunctionHelper.cpp
 * @author Khon Min Thite
 * @brief .cpp for FunctionHelper.h
 * @version 0.1
 * @date 6-3-2024
 *
 *
 */
#include "FUNCTIONHELPER.H"

string FunctionHelper::DisplayMenu()
{
    string menu;
    menu += "1. Average wind speed in km/h and standard deviation for a given specified month and year. \n";
    menu += "2. Average ambient air temperature and sample standard deviation for each month of a specified year. \n";
    menu += "3. sPCC for a given specific month for all years that have been loaded.  \n";
    menu += "4. Write Average wind speed in km/h(standard deviation), average ambient air temperature(standard deviation) and total solar radiation in KWH/M2 for each month of a specified year to CSV. \n";
    menu += "5. Reload data from data/data_source.txt file. \n";
    menu += "6. Exit the program.\n";
    return menu;
}

string FunctionHelper::FindAverageWindSpeedAndStandardDeviationMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int monthInput, int yearInput)
{
    Logic logicHelp;
    string result;
    //Get the average wind speed of the month
    float averageWind = logicHelp.AverageWindSpeedMonth(windLog, monthInput, yearInput);
    //Get the standard deviation of wind speed for the month
    float stdevWind = logicHelp.StandardDeviationWindSpeed(windLog, monthInput, yearInput);

    //If average wind speed and average air temperature is not found
    if(averageWind == -1)
    {
        result += logicHelp.IntMonthToString(monthInput) + " " + to_string(yearInput) + ": " + "No Data" + '\n';
    }
    else
    {
        float convertedWind = logicHelp.ConvertWindMStoKMH(averageWind);

        result += logicHelp.IntMonthToString(monthInput) + " " + to_string(yearInput) + ": "
                  + "Average Speed: " + to_string(convertedWind) + " km/h " + '\n'
                  + "stdev:  " + to_string(stdevWind) + '\n';
    }
    return result;
}

string FunctionHelper::FindAverageAirTemperatureAndStandardDeviationMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int monthInput, int yearInput)
{
    Logic logicHelp;
    string result;
    //Get the average air temperature of the month
    float averageTemp = logicHelp.AverageAirTemperatureMonth(windLog, monthInput, yearInput);

    //Get the standard deviation of air temperature for the month
    float stdevTemp = logicHelp.StandardDeviationAirTemperature(windLog, monthInput, yearInput);


    //If average wind speed and average air temperature is not found
    if(averageTemp == -1)
    {
        result += logicHelp.IntMonthToString(monthInput) + " " + to_string(yearInput) + ": " + "No Data" + '\n';
    }
    else
    {
        result += logicHelp.IntMonthToString(monthInput) + " " + to_string(yearInput) + ": " + "Average:" + to_string(averageTemp) + "degrees C, stdev:" + to_string(stdevTemp) + '\n';
    }
    return result;
}

string FunctionHelper::FindAverageTemperatureYear(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput)
{
    string result;

    //Loop for each month of the year
    for(int month = 1; month <= 12; month++)
    {
        //Get Average air temperature and standard deviation result
        result +=  FindAverageAirTemperatureAndStandardDeviationMonth(windLog, month, yearInput);
    }
    return result;
}

string FunctionHelper::FindSumSolarRadMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput)
{
    Logic logicHelp;
    float totalRadiation;
    string result;

    //Loop for each month of the year
    for(int month = 1; month <= 12; month++)
    {
        //Get total solar radiation of the month
        totalRadiation = logicHelp.SumSolarRadiationMonth(windLog, month, yearInput);

        //If no data for solar radiation is found
        if(totalRadiation == -1)
        {
            result += logicHelp.IntMonthToString(month) + " " + to_string(yearInput) + ": No Data\n";
        }
        else
        {
            totalRadiation = logicHelp.ConvertSolarRadiationWMtoKWH(totalRadiation);

            result += logicHelp.IntMonthToString(month) + " " + to_string(yearInput) + ": " + to_string(totalRadiation) + " KWH/M2 \n";
        }
    }

    return result;
}

void FunctionHelper::OutputFileAverageWindTempSolarMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput)
{
    Logic logicHelp;
    const char outputFile[] = "WindTempSolar.csv";
    const string outputFileStr = "WindTempSolar.csv";
    string outputStr;
    //Delete the output file if it exist
    remove(outputFile);

    //appends the string and proceed to next line
    outputStr += to_string(yearInput) + "\n";

    float averageWind, stdevWind, averageTemp, stdevTemp, totalRadiation;
    //Loop for each month of the year
    for(int month = 1; month <= 12; month++)
    {
        //Get the average wind speed of the month
        averageWind = logicHelp.AverageWindSpeedMonth(windLog, month, yearInput);
        //Get the standard deviation of wind speed for the month
        stdevWind = logicHelp.StandardDeviationWindSpeed(windLog, month, yearInput);
        //Get the average air temperature of the month
        averageTemp = logicHelp.AverageAirTemperatureMonth(windLog, month, yearInput);
        //Get the standard deviation of wind speed for the month
        stdevTemp = logicHelp.StandardDeviationAirTemperature(windLog, month, yearInput);
        //Get the total solar radiation of the month
        totalRadiation = logicHelp.SumSolarRadiationMonth(windLog, month, yearInput);

        //If no data for wind speed and air temperature and solar radiation is found
        if(averageWind == -1 && averageTemp == -1 && totalRadiation == -1)
        {
            continue;
        }
        else
        {
            //Print the month
            outputStr += logicHelp.IntMonthToString(month)+",";

            //If no data for wind speed is found
            if(averageWind == -1)
            {
                continue;
            }
            else
            {
                //Convert and print the data
                averageWind = logicHelp.ConvertWindMStoKMH(averageWind);
                outputStr += to_string(averageWind) + "(" + to_string(stdevWind) + ")";
            }
            //Add , separator
            outputStr += ",";
            //If average air temperature data is not found
            if(averageTemp == -1)
            {
                continue;
            }
            else
            {
                //print the data
                outputStr += to_string(averageTemp)+ "(" + to_string(stdevTemp) + ")";
            }
            //Add , separator
            outputStr += ",";
            //If data for solar radiation not found
            if(totalRadiation == -1)
            {
                continue;
            }
            else
            {
                //Convert and print data
                totalRadiation = logicHelp.ConvertSolarRadiationWMtoKWH(totalRadiation);
                outputStr += to_string(totalRadiation);
            }
        }
        outputStr += "\n";
    }
    logicHelp.WriteAppendFile(outputFileStr, outputStr);
}

string FunctionHelper::FindsPCCForGivenMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int month)
{
    Logic logicHelp;
    Vector<float> windSpeeds, airTemps, solarRads;
    string result;

    // Initialize sPCC values for each correlation
    float spcc_ST_total = 0.0, spcc_SR_total = 0.0, spcc_TR_total = 0.0;
    int yearCount = 0; // To count the number of years processed

    // Loop through all years in the windLog map
    for (const auto& yearEntry : windLog)
    {
        int year = yearEntry.first;
        logicHelp.extractMonthData(windLog, month, year, windSpeeds, airTemps, solarRads);

        // Calculate sPCC for each year
        float spcc_ST = logicHelp.calculateSPCC(windSpeeds, airTemps);
        float spcc_SR = logicHelp.calculateSPCC(windSpeeds, solarRads);
        float spcc_TR = logicHelp.calculateSPCC(airTemps, solarRads);

        // Aggregate sPCC values
        spcc_ST_total += spcc_ST;
        spcc_SR_total += spcc_SR;
        spcc_TR_total += spcc_TR;
        yearCount++;
    }

    // Calculate average sPCC values
    float spcc_ST_avg = yearCount > 0 ? spcc_ST_total / yearCount : 0.0;
    float spcc_SR_avg = yearCount > 0 ? spcc_SR_total / yearCount : 0.0;
    float spcc_TR_avg = yearCount > 0 ? spcc_TR_total / yearCount : 0.0;

    result += "Average Sample Pearson Correlation Coefficient for month " + logicHelp.IntMonthToString(month) + "\n";
    result += "S_T: " + to_string(spcc_ST_avg) + "\n";
    result += "S_R: " + to_string(spcc_SR_avg) + "\n";
    result += "T_R: " + to_string(spcc_TR_avg) + "\n";

    return result;
}

void FunctionHelper::ReloadData(map<int, map<int, map<int, Bst<Weather>>>>& windLog)
{
    // Clear the existing data
    windLog.clear();

    // Reload data from data/data_source.txt file
    ifstream dataFile("data/data_source.txt");
    if (dataFile.is_open())
    {
        Logic logicHelp;
        logicHelp.LoadMultiDataFileCSV(dataFile, windLog);
        dataFile.close();
    }
    else
    {
        cout << "Error opening data/data_source.txt file." << endl;
    }
}
