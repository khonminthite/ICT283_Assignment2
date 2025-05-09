/**
 * @file Weather.h
 * @author Khon Min Thite
 * @brief Class for storing Wind log details such as date, time, wind speed, solar radiation and air temperature.
 * Each Object correspond to a line of record from data file
 * @version 0.1
 * @date 29-2-2024
 *
 * @version 0.2
 * @date 5-3-2024
 * Added Operator overload > for BST insertion
 * Added Operator overload < for BST insertion
 * Added Operator overload == for BST insertion
 */

#ifndef WEATHER_H
#define WEATHER_H

#include "DATE.H"
#include "TIME.H"

using namespace std;

class Weather
{
public:

    /**
     * @brief Construct a new Weather object
     *
     */
    Weather();

    /**
     * @brief Destroy the Weather object
     *
     */
    ~Weather();

    /**
     * @brief Get m_date
     *
     * @return const Date& - Date object
     */
    const Date& GetDate() const;

    /**
     * @brief Get m_time
     *
     * @return const Time&  -Time Object
     */
    const Time& GetTime() const;

    /**
     * @brief Get m_windSpeed
     *
     * @return float - Wind Speed
     */
    float GetWindSpeed() const;

    /**
     * @brief Get m_solarRad
     *
     * @return float - Solar Radiation
     */
    float GetSolarRadiation() const;

    /**
     * @brief Get m_airTemp
     *
     * @return float - Ambient Air Temperature
     */
    float GetAirTemperature() const;

    /**
     * @brief Set m_date
     *
     * @param date - Date object
     */
    void SetDate(const Date& date);

    /**
     * @brief Set m_time
     *
     * @param time - Time object
     */
    void SetTime(const Time& time);

    /**
     * @brief Set m_windSpeed
     *
     * @param windSpeed - wind speed
     */
    void SetWindSpeed(const float windSpeed);

    /**
     * @brief Set m_solarRad
     *
     * @param solar - Solar Radiation
     */
    void SetSolarRadiation(const float solar);

    /**
     * @brief Set m_airTemp
     *
     * @param temp - Ambient Air Temperature
     */
    void SetAirTemp(const float temp);

private:
    //Stores the date part includes the day, month & year
    Date m_date;
    //Stores the time part include hour and minutes
    Time m_time;
    //Stores the wind speed in m/s for each record
    float m_windSpeed;
    //Stores the solar radiation in W/m^2
    float m_solarRad;
    //Stores the ambient air temperature in degrees C
    float m_airTemp;
};

/**
 * @brief Operator overload of < comparison. Compares Weather.
 *
 * @param lw - The Weather object on the left of comparison
 * @param rw - The Weather object on the right of comparison
 * @return true - If lw is less than rw
 * @return false - If lw is more than rw
 */
bool operator < (const Weather& lw, const Weather& rw);

/**
 * @brief Operator overload of > comparison. Compares Weather.
 *
 * @param lw - The Weather object on the left of comparison
 * @param rw - The Weather object on the right of comparison
 * @return true - If lw is more than rw
 * @return false - If lw is less than rw
 */
bool operator > (const Weather& lw, const Weather& rw);

/**
 * @brief Operator overload of ==. Equate Weather.
 *
 * @param lw - The Weather object on the left of comparison
 * @param rw - The Weather object on the right of comparison
 * @return true - If lw is equal to rw
 * @return false - If lw is not equal to rw
 */
bool operator == (const Weather&lw, const Weather& rw);

#endif
