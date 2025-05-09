/**
 * @file BstWeatherHelper.cpp
 * @author Khon Min Thite
 * @brief .cpp file for BstWeatherHelper.h
 * @version 0.1
 * @date 6-3-2024
 *
 *
 */

#include "BstWeatherHelper.h"

float BstWeatherHelper::GetWeatherWindSpeed(Weather& weather)
{
    return weather.GetWindSpeed();
}

float BstWeatherHelper::GetWeatherAirTemp(Weather& weather)
{
    return weather.GetAirTemperature();
}

float BstWeatherHelper::GetWeatherSolarRad(Weather& weather)
{
    return weather.GetSolarRadiation();
}

