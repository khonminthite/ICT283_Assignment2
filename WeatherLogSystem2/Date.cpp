/**
 * @file Date.cpp
 * @author Khon Min Thite
 * @brief .cpp file for Date.h
 * @version 0.1
 * @date 18-2-2024
 *
 *
 */

#include "Date.h"

Date::Date(unsigned int d, unsigned int m, unsigned int y)
{
    m_day = d;
    m_month = m;
    m_year = y;
}

//Getters
int Date::GetDay() const
{
    return m_day;
}

int Date::GetMonth() const
{
    return m_month;
}

int Date::GetYear() const
{
    return m_year;
}

//Setters
void Date::SetDay(const unsigned int d)
{
    m_day = d;
}

void Date::SetMonth(const unsigned int m)
{
    m_month = m;
}

void Date::SetYear(const unsigned int y)
{
    m_year = y;
}

string Date::DisplayFullDate() const
{
    return to_string(m_day) + "/" + to_string(m_month) + "/" + to_string(m_year);
}
