/**
 * @file Time.h
 * @author Khon Min Thite
 * @brief Time class for storing 24 hour time
 * Splits in hour and minute before storing as unsigned int
 * Expects only 24 hour time
 * @version 0.1
 * @date 18-02-2024
 *
 * @version 0.2
 * @date 5-3-2024
 * Added Operator overload > for BST insertion
 * Added Operator overload < for BST insertion
 * Added Operator overload == for BST insertion
 */

#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time
{
public:

    /**
     * @brief Construct a new Time object
     *
     */
    Time():m_hour(-1), m_minute(-1) {};

    /**
     * @brief Construct a new Time object
     *
     * @param h hour
     * @param m minute
     */
    Time(unsigned int h, unsigned int m);

    /**
     * @brief Destroy the Time object
     *
     */
    ~Time() {};

    /**
     * @brief Get the Hour object
     *
     * @return int
     */
    int GetHour() const;

    /**
     * @brief Get the Minute object
     *
     * @return int
     */
    int GetMinute() const;

    /**
     * @brief Set the Hour object
     *
     * @param h hour
     */
    void SetHour(const unsigned int h);

    /**
     * @brief Set the Minute object
     *
     * @param m minute
     */
    void SetMinute(const unsigned int m);

    /**
     * @brief Display 24 hour
     *
     * @return string
     */
    string Display24HTime() const;

private:
    int m_hour;
    int m_minute;
};

/**
 * @brief Operator overload of < comparison. Compares hour and minute.
 *
 * @param lt - The Time object on the left side of comparison
 * @param rt - The Time object on the right side of comparison
 * @return true - If lt is less than rt
 * @return false - If lt is more than rt
 */
bool operator < (const Time& lt, const Time& rt);

/**
 * @brief Operator overload of > comparison. Compares hour and minute.
 *
 * @param lt - The Time object on the left side of comparison
 * @param rt - The Time object on the right side of comparison
 * @return true - If lt is more than rt
 * @return false - If lt is less than rt
 */
bool operator > (const Time& lt, const Time& rt);

/**
 * @brief Overloaded operator for ==. Equal Time.
 * @param lt - The time object on the left
 * @param rt - The time object on the right
 * @return true - if lt is equal to rt
 * @return false - if lt is not equal to rt
 */
bool operator == (const Time& lt, const Time& rt);

#endif
