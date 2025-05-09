/**
 * @file BstWeatherHelperTest.cpp
 * @author Khon Min Thite
 * @brief Unit Test for BstWeatherHelper.h
 * @version 0.1
 * @date 3-6-2024
 *
 *
 */

#include "BstWeatherHelper.h"

int main()
{
    BstWeatherHelper BST;
    Weather testWeather;
    Date testDate(16,3,2016);
    testWeather.SetDate(testDate);
    Time testTime(9,15);
    testWeather.SetTime(testTime);
    testWeather.SetWindSpeed(11.1);
    testWeather.SetSolarRadiation(23.15);
    testWeather.SetAirTemp(78.25);

    //Check that GetWeatherWindSpeed function can correctly get the wind speed data from given weather object
    cout << "Test GetWeatherWindSpeed" << endl;
    cout << BST.GetWeatherWindSpeed(testWeather) << endl;
    cout << endl;

    //Check that GetWeatherAirTemp function can correctly get the air temperature data from given weather object
    cout << "Test GetWeatherAirTemp" << endl;
    cout << BST.GetWeatherAirTemp(testWeather) << endl;
    cout << endl;

    //Check that GetWeatherSolarRad function can correctly get the solar radiation data
    cout << "Test GetWeatherSolarRad" << endl;
    cout << BST.GetWeatherSolarRad(testWeather) << endl;
    cout << endl;

    return 0;
}
