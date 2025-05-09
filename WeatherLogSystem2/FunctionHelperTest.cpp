/**
 * @file FunctionHelperTest.cpp
 * @author Khon Min Thite
 * @brief Unit test for FunctionHelper.h
 * @version 0.1
 * @date 6-3-2024
 *
 *
 */

#include "FunctionHelper.h"

using namespace std;

int main ()
{
    FunctionHelper funcHelp;
    Logic TestLogic;
    map<int, map<int, map<int, Bst<Weather>>>> testLog;
    ifstream indexFile("data/test_index.txt");
    TestLogic.LoadMultiDataFileCSV(indexFile, testLog);
    //Check that DisplayMenu function can successfully display the menu
    cout << "Test DisplayMenu function" << endl;
    cout << funcHelp.DisplayMenu() << endl;

    //Check that FindAverageAirTemperatureAndStandardDeviationMonth can correctly carry out the function of option 1 of menu given map, month and year input
    cout << "Test FindAverageAirTemperatureAndStandardDeviationMonth function for option 1" << endl;
    cout << funcHelp.FindAverageAirTemperatureAndStandardDeviationMonth(testLog, 1, 2010);
    cout << endl;

    //Check that FindAverageTemperatureYear can correctly carry out the function of option 2 of menu given year input
    cout << "Test FindAverageTemperatureYear function for option 2" << endl;
    cout << funcHelp.FindAverageTemperatureYear(testLog, 2010);
    cout << endl;

    //Check that FindsPCCForGivenMonth can correctly carry out the function of option 3 of menu given map and month input
    cout << "Test FindsPCCForGivenMonth function for option 3" << endl;
    cout << funcHelp.FindsPCCForGivenMonth(testLog, 1);
    cout << endl;

    //Check that OutputFileAverageWindTempSolarMonth can correctly carry out the function of option 4 of menu given map and year input
    cout << "Test OutputFileAverageWindTempSolarMonth function for option 4" << endl;
    funcHelp.OutputFileAverageWindTempSolarMonth(testLog, 2010);
    cout << endl;

    map<int, map<int, map<int, Bst<Weather>>>> testLog1;

    //Check that Option 5 can correctly carry out the function of option 4 of menu given map and year input
    cout << "Test OutputFileAverageWindTempSolarMonth function for option 4" << endl;
    funcHelp.ReloadData(testLog1);
    cout << endl;
    return 0;
}
