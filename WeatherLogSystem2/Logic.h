/**
 * @file Logic.h
 * @author Khon Min Thite
 * @brief A helper class for main.cpp
 * Handles task such as displaying menu, converting of data types, addition..
 * Function for writing to file will be including in this helper class in this program as there is only 1 function in this program that will write output to file.
 * @version 0.1
 * @date 29-2-2024
 *
 * @version 0.2
 * @date 4-3-2024
 * Change LoadDataFileCSV function to return boolean
 *
 * @version 0.3
 * @date 6-3-2004
 * Moved Display menu to functionHelper class
 * Changed all function that accept vector of weather to accepting maps of binary search tree of weather instead
 */

#ifndef LOGIC_H
#define LOGIC_H

#include "Bst.h"
#include "Date.h"
#include "Time.h"
#include "Weather.h"
#include "Validator.h"
#include "BstWeatherHelper.h"
#include "Vector.h"

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>
#include <numeric>

using namespace std;

/**
 * @class Logic
 * @brief A class that handles loading, processing, and analyzing weather data.
 *
 * This class provides functionality for loading weather data from CSV files,
 * inserting weather data into a binary search tree (BST) structure, and performing
 * various calculations and conversions on the data.
 */
class Logic
{
public:

    /**
     * @brief Reads the input file line by line for filename pass to LoadDataFileCSV function to read and load data into the wind log
     *
     * @param inputFile - Input file with the list of data file name to read and load
     * @param windLog - The maps of binary search tree of weather for storing Weather object which will store data from data file. This will be passed to LoadDataFileCSV function to load file by file
     */
    void LoadMultiDataFileCSV(ifstream& inputFile, map<int, map<int, map<int, Bst<Weather>>>>& windLog);

    /**
     * @brief Load the data of an input data file and store it in a maps of binary search tree of weather
     *
     * @param inputFile - The input file
     * @param WindLog - The maps of binary search tree of weather
     * @return true - Load successful
     * @return false - Load unsuccessful
     */
    bool LoadDataFileCSV(ifstream& inputFile, map<int, map<int, map<int, Bst<Weather>>>>& windLog);

    /**
     * @brief Inserts tempLog into wind log
     *
     * @param windLog - The maps of binary search tree of weather
     * @param tempLog - The weather object to be inserted into windLog
     */
    void InsertWeatherToMap(map<int, map<int, map<int, Bst<Weather>>>>& windLog, Weather& tempLog);

    /**
     * @brief Removes leading 0 s from a given string
     *
     * @param input - The input string
     * @return string - The string after removing leading 0 s
     */
    string RemoveLeadingZeros(string input);

    /**
     * @brief Search and Calculates the average wind speed of a month when given the month and year to search for
     *
     * @param array - The maps of binary search tree of weather to search in
     * @param month - The month to search for
     * @param year - The year to search for
     * @return float - The average wind speed of a month
     */
    float AverageWindSpeedMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year);

    /**
     * @brief Calculates the standard deviation of wind speed for a specified month and year.
     *
     * This method searches the wind log for the specified month and year and calculates the standard deviation of wind speed.
     *
     * @param windLog - The map of BSTs containing the weather data.
     * @param month - The month to search for.
     * @param year - The year to search for.
     * @return The standard deviation of wind speed for the specified month and year.
     */
    float StandardDeviationWindSpeed(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year);

    /**
     * @brief Calculates the standard deviation of air temperature for a specified month and year.
     *
     * This method searches the wind log for the specified month and year and calculates the standard deviation of air temperature.
     *
     * @param windLog - The map of BSTs containing the weather data.
     * @param month - The month to search for.
     * @param year - The year to search for.
     * @return The standard deviation of air temperature for the specified month and year.
     */
    float StandardDeviationAirTemperature(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year);

    /**
     * @brief Search and Calculates the average air temperature of a month when given the month and year to search for
     *
     * @param array - The maps of binary search tree of weather to search in
     * @param month - The month to search for
     * @param year - The year to search for
     * @return float - The average air temperature of a month
     */
    float AverageAirTemperatureMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year);

    /**
     * @brief Search and Calculates the total solar radiation of a month when given the month and year to search for
     *
     * @param array - The maps of binary search tree of weather to search in
     * @param month - The month to search for
     * @param year - The year to search for
     * @return float - The total solar radiation of a month
     */
    float SumSolarRadiationMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year);

    /**
     * @brief Converts a given integer month to string month
     *
     * @param month - A month in integer
     * @return string - A month in string
     */
    string IntMonthToString(const int& month);

    /**
     * @brief Converts wind speed m/s  to km/h
     *
     * @param windSpeed - wind speed in m/s
     * @return float - wind speed in km/h
     */
    float ConvertWindMStoKMH(const float& windSpeed);

    /**
     * @brief Converts solar radiation from W per 10 min to kWh
     *
     * @param radiation - Radiation in W per 10 min
     * @return float - Radiation in kWh
     */
    float ConvertSolarRadiationWMtoKWH(const float& radiation);

    /**
     * @brief Create/Appends a given string into "WindTempSolar.csv"
     *
     * @param output - The string to append
     */
    void WriteAppendFile(const string& fileName, const string& output);

    /**
     * @brief Calculates Sample Pearson Correlation Coefficient (SPCC) between two vectors.
     *
     * This method calculates Sample Pearson Correlation Coefficient between two vectors of floating-point numbers.
     *
     * @param x - The first vector of floating-point numbers.
     * @param y - The second vector of floating-point numbers.
     * @return Sample Pearson Correlation Coefficient between the two vectors.
     */
    float calculateSPCC(const Vector<float>& x, const Vector<float>& y);

    /**
     * @brief Extracts data for a specified month and year from the wind log.
     *
     * This method extracts wind speeds, air temperatures, and solar radiation data for a specified month and year from the wind log.
     *
     * @param windLog - The map of BSTs containing the weather data.
     * @param month - The month to extract data for.
     * @param year - The year to extract data for.
     * @param windSpeeds - A vector to store the extracted wind speeds.
     * @param airTemps - A vector to store the extracted air temperatures.
     * @param solarRads - A vector to store the extracted solar radiation data.
     */
    void extractMonthData(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year, Vector<float>& windSpeeds, Vector<float>& airTemps, Vector<float>& solarRads);
};

#endif
