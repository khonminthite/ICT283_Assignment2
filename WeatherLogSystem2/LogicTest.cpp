/**
 * @file LogicTest.cpp
 * @author Khon Min Thite
 * @brief Unit Test for Logic.h
 * @version 0.1
 * @date 6-3-2024
 *
 *
 */

#include "Logic.h"
#include "Weather.h"

#include <iostream>

using namespace std;

void GetDateTime(Weather& weather)
{
    cout << weather.GetDate().DisplayFullDate() << " " << weather.GetTime().Display24HTime() << endl;
}

int main ()
{
    Logic TestLogic;
    map<int, map<int, map<int, Bst<Weather>>>> testLog;
    ifstream indexFile("data/test_index.txt");

    //Check that LoadMultiDataFileCSV can correctly load multiple data file into map using a index file
    cout << "Test LoadMultiDataFileCSV function" << endl;
    TestLogic.LoadMultiDataFileCSV(indexFile, testLog);
    testLog[2012][1][1].InOrderTraversal(GetDateTime);
    cout << endl;

    //Check that LoadDataFileCSV can correctly load a data file into map using a index file
    map<int, map<int, map<int, Bst<Weather>>>> testLog2;
    ifstream dataFile("data/dataFile1.csv");
    cout << "Test LoadDataFileCSV function" << endl;
    TestLogic.LoadDataFileCSV(dataFile, testLog2);
    testLog2[2010][8][17].InOrderTraversal(GetDateTime);
    cout << endl;

    //Check that InsertWeatherToMap can correctly insert a Weather Object into map
    Weather testWeather;
    Date testDate(16,3,2016);
    testWeather.SetDate(testDate);
    Time testTime(9,15);
    testWeather.SetTime(testTime);
    testWeather.SetWindSpeed(23.1);
    testWeather.SetSolarRadiation(53.15);
    testWeather.SetAirTemp(53.25);
    map<int, map<int, map<int, Bst<Weather>>>> testLog3;
    cout << "Test InsertWeatherToMap function" << endl;
    TestLogic.InsertWeatherToMap(testLog3, testWeather);
    testLog3[2016][3][16].InOrderTraversal(GetDateTime);
    cout << endl;

    //Check that RemoveLeadingZeros function can correctly remove the leading zeros when given a string
    cout << "Test RemoveLeadingZeros(string)" << endl;
    cout << "Test RemoveLeadingZeros(08): " << TestLogic.RemoveLeadingZeros("08") << endl;
    cout << "Test RemoveLeadingZeros(08.9): " << TestLogic.RemoveLeadingZeros("08.9") << endl;
    cout << endl;

    //Check that IntMonthToString function can correctly return the month in string when provided with a month in integer
    cout << "Test IntMonthToString(unsigned int)" << endl;
    cout << "Test IntMonthToString(8): " << TestLogic.IntMonthToString(8) << endl;
    cout << "Test IntMonthToString(13): " << TestLogic.IntMonthToString(13) << endl;
    cout << endl;

    //Check that ConvertWindMStoKMH function can correctly convert wind speed provided in m/s to km/h
    cout << "Test ConvertWindMStoKMH(float)" << endl;
    cout << "Test ConvertWindMStoKMH(10): " << TestLogic.ConvertWindMStoKMH(10) << endl;
    cout << "Test ConvertWindMStoKMH(10.5): " << TestLogic.ConvertWindMStoKMH(10.5) << endl;
    cout << endl;

    //Check that ConvertSolarRadiationWMtoKWH function can correctly convert solar radiation provided in W/M2 to KWH/M2
    cout << "Test ConvertSolarRadiationWMtoKWH(float)" << endl;
    cout << "Test ConvertSolarRadiationWMtoKWH(120): " << TestLogic.ConvertSolarRadiationWMtoKWH(120) << endl;
    cout << "Test ConvertSolarRadiationWMtoKWH(120.42): " << TestLogic.ConvertSolarRadiationWMtoKWH(120.42) << endl;
    cout << endl;

    //Check that AverageWindSpeedMonth function can correctly find and calculate the average wind speed for a month
    cout << "Test AverageWindSpeedMonth(vector,int,int)" << endl;
    cout << "Test AverageWindSpeedMonth(TestLog,6,2011): " << TestLogic.AverageWindSpeedMonth(testLog,6,2011) << endl;
    cout << "Test AverageWindSpeedMonth(TestLog,1,2010): " << TestLogic.AverageWindSpeedMonth(testLog,1,2010) << endl;
    cout << endl;

    //Check that StandardDeviationWindSpeed function can correctly find and calculate the standard deviation of wind speed for a month
    cout << "Test StandardDeviationWindSpeed(vector,int,int)" << endl;
    cout << "Test StandardDeviationWindSpeed(TestLog,6,2011): " << TestLogic.StandardDeviationWindSpeed(testLog,6,2011) << endl;
    cout << "Test StandardDeviationWindSpeed(TestLog,1,2010): " << TestLogic.StandardDeviationWindSpeed(testLog,1,2010) << endl;
    cout << endl;

    //Check that AverageAirTemperatureMonth function can correctly find and calculate the average ambient air temperature for a month
    cout << "Test AverageAirTemperatureMonth(vector,int,int)" << endl;
    cout << "Test AverageAirTemperatureMonth(TestLog,6,2011): " << TestLogic.AverageAirTemperatureMonth(testLog,6,2011) << endl;
    cout << "Test AverageAirTemperatureMonth(TestLog,1,2010): " << TestLogic.AverageAirTemperatureMonth(testLog,1,2010) << endl;
    cout << endl;

    //Check that StandardDeviationAirTemperature function can correctly find and calculate the standard deviation of ambient air temperature for a month
    cout << "Test StandardDeviationAirTemperature(vector,int,int)" << endl;
    cout << "Test StandardDeviationAirTemperature(TestLog,6,2011): " << TestLogic.StandardDeviationAirTemperature(testLog,6,2011) << endl;
    cout << "Test StandardDeviationAirTemperature(TestLog,1,2010): " << TestLogic.StandardDeviationAirTemperature(testLog,1,2010) << endl;
    cout << endl;

    //Check that SumSolarRadiationMonth function can correctly find and calculate the total solar radiation for a month
    cout << "Test SumSolarRadiationMonth(vector,int,int)" << endl;
    cout << "Test SumSolarRadiationMonth(TestLog,6,2011): " << TestLogic.SumSolarRadiationMonth(testLog,6,2011) << endl;
    cout << "Test SumSolarRadiationMonth(TestLog,1,2010): " << TestLogic.SumSolarRadiationMonth(testLog,1,2010) << endl;
    cout << endl;

    //Check that WriteAppendFile able to correctly write to "WindTempSolar.csv"
    cout << "Test WriteAppendFile(string)" << endl;
    TestLogic.WriteAppendFile("test.csv","teststring");
    TestLogic.WriteAppendFile("test.csv","teststring2");
    cout << endl;

    cout << "Test calculateSPCC(vector,vector)" << endl;
    Vector<float> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    Vector<float> y = {2.0, 3.0, 4.0, 5.0, 6.0};
    float spcc = TestLogic.calculateSPCC(x, y);
    cout << "SPCC: " << spcc << endl;
    cout << endl;

    cout << "Test extractMonthData with Edge Cases" << endl;
    Vector<float> windSpeeds, airTemps, solarRads;

    TestLogic.extractMonthData(testLog, 1, 2010, windSpeeds, airTemps, solarRads);
    cout << "Month and Year Not Found Test: Wind Speeds Size: " << windSpeeds.size() << ", Air Temperatures Size: " << airTemps.size() << ", Solar Radiations Size: " << solarRads.size() << endl;

    return 0;
}
