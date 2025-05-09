/**
 * @file FunctionHelper.h
 * @author Khon Min Thite
 * @brief Each function here represents a option for the program. In addition, the function to display the menu is here too.
 * @version 0.1
 * @date 2022-04-05
 *
 *
 */

#ifndef FUNCTIONHELPER_H
#define FUNCTIONHELPER_H

#include "Logic.h"

#include <iostream>
#include <cstdio>

using namespace std;

class FunctionHelper
{
public:

    /**
    * @brief Displays the menu
    *
    */
    string DisplayMenu();

    /**
     * @brief Function 1
     *
     * @param windLog - The maps of BST of weather
     * @param monthInput - The month to search
     * @param yearInput - The year to search
     * @return string - The result string
     */
    string FindAverageWindSpeedAndStandardDeviationMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int monthInput, int yearInput);

    /**
     * @brief Function 2
     *
     * @param windLog - The maps of BST of weather
     * @param monthInput - The month to search
     * @param yearInput - The year to search
     * @return string - The result string
     */
    string FindAverageAirTemperatureAndStandardDeviationMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int monthInput, int yearInput);

    /**
     * @brief Function 2
     *
     * @param windLog - The maps of BST of weather
     * @param yearInput - The year to search
     * @return string - The result string
     */
    string FindAverageTemperatureYear(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput);

    /**
     * @brief Function 4
     *
     * @param windLog - The maps of BST of weather
     * @param yearInput - The year to search
     * @return string - The result string
     */
    string FindSumSolarRadMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput);

    /**
     * @brief Function 3
     *
     * @param windLog - The maps of BST of weather
     * @param monthInput - The month to search
     */
    string FindsPCCForGivenMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int month);

    /**
     * @brief Function 4
     *
     * @param windLog - The maps of BST of weather
     * @param yearInput - The year to search
     */
    void OutputFileAverageWindTempSolarMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput);

    /**
     * @brief Function 5
     *
     * @param windLog - The maps of BST of weather
     */
    void ReloadData(map<int, map<int, map<int, Bst<Weather>>>>& windLog);
};

#endif
