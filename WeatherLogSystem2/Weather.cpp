/**
 * @file Weather.cpp
 * @author
 * @brief .ccp for Weather.h
 * @version 0.1
 * @date 2022-02-27
 *
 *
 */

#include "Weather.h"

Weather::Weather()
{
    //Sets to -1
    m_windSpeed = 0.0;
    m_solarRad = 0.0;
    m_airTemp = 0.0;
}

Weather::~Weather() {}

//Getters
const Date& Weather::GetDate() const
{
    return m_date;
}

const Time& Weather::GetTime() const
{
    return m_time;
}

float Weather::GetWindSpeed() const
{
    return m_windSpeed;
}

float Weather::GetSolarRadiation() const
{
    return m_solarRad;
}

float Weather::GetAirTemperature() const
{
    return m_airTemp;
}

//Setters
void Weather::SetDate(const Date& date)
{
    m_date = date;
}

void Weather::SetTime(const Time& time)
{
    m_time = time;
}

void Weather::SetWindSpeed(const float windSpeed)
{
    m_windSpeed = windSpeed;
}

void Weather::SetSolarRadiation(const float solar)
{
    m_solarRad = solar;
}

void Weather::SetAirTemp(const float temp)
{
    m_airTemp = temp;
}

bool operator < (const Weather& lw, const Weather& rw)
{
    return lw.GetTime() < rw.GetTime();
}

bool operator > (const Weather& lw, const Weather& rw)
{
    return lw.GetTime() > rw.GetTime();
}

bool operator == (const Weather&lw, const Weather& rw)
{
    return lw.GetTime() == rw.GetTime();
}
