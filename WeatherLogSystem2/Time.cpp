/**
 * @file Time.cpp
 * @author Khon Min Thite
 * @brief .cpp file for Time.h
 * @version 0.1
 * @date 18-02-2024
 *
 */

#include "Time.h"

Time::Time(unsigned int h, unsigned int m)
{
    m_hour = h;
    m_minute = m;
}

int Time::GetHour() const
{
    return m_hour;
}

int Time::GetMinute() const
{
    return m_minute;
}

void Time::SetHour(const unsigned int h)
{
    m_hour = h;
}

void Time::SetMinute(const unsigned int m)
{
    m_minute = m;
}

string Time::Display24HTime() const
{
    string result;
    if(m_hour < 10)
    {
        result += "0" + to_string(m_hour);
    }
    else
    {
        result += to_string(m_hour);
    }
    result += ":";
    if(m_minute < 10)
    {
        result += "0" + to_string(m_minute);
    }
    else
    {
        result += to_string(m_minute);
    }

    return result;
}

bool operator < (const Time& lt, const Time& rt)
{
    if(lt.GetHour() != rt.GetHour())
    {
        return lt.GetHour() < rt.GetHour();
    }
    return lt.GetMinute() < rt.GetMinute();
}

bool operator > (const Time& lt, const Time& rt)
{
    if(lt.GetHour() != rt.GetHour())
    {
        return lt.GetHour() > rt.GetHour();
    }
    return lt.GetMinute() > rt.GetMinute();
}

bool operator == (const Time& lt, const Time& rt)
{
    return lt.GetHour() == rt.GetHour() && lt.GetMinute() == rt.GetMinute();
}
