/**
 * @file BSTWEATHERHELPER.H
 * @author Khon Min Thite
 * @brief Holds all the functions that is used as parameter for BST functions in the program
 * @version 0.1
 * @date 6-3-2024
 *
 *
 */

#ifndef MENUHELPER_H
#define MENUHELPER_H

#include "Weather.h"

class BstWeatherHelper
{
public:
    /**
     * @brief Get the Weather object's Wind Speed
     *
     * @param weather - A weather object
     * @return float - the value of wind speed of weather
     */
    static float GetWeatherWindSpeed(Weather& weather);

    /**
     * @brief Get the Weather object's Air Temp
     *
     * @param weather - A weather object
     * @return float - the value of air temperature of weather
     */
    static float GetWeatherAirTemp(Weather& weather);

    /**
     * @brief Get the Weather object's Solar Rad
     *
     * @param weather - A weather object
     * @return float - the value of solar radiation of weather
     */
    static float GetWeatherSolarRad(Weather& weather);
};

#endif

