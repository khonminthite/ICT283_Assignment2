/**
 * @file MAIN.CPP
 * @author Khon Min Thite
 * @brief Controls the cin and cout of the program
 * @version 0.1
 * @date 29-2-2024
 *
 * @version 0.2
 * @date 6-3-2024
 * Move function logic to functionHelper class.
 *
 */
#include "Logic.h"
#include "Validator.h"
#include "FunctionHelper.h"
#include "Date.h"
#include "Time.h"
#include "Weather.h"
#include "Bst.h"

#include <iostream>
#include <sstream>

using namespace std;

int main ()
{
    Logic logicHelp;
    Validator validateHelp;
    FunctionHelper menuHelp;

    map<int, map<int, map<int, Bst<Weather>>>> windLog;

    ifstream indexFile("data/data_source.txt");

    if(indexFile.is_open() == false)
    {
        cout << "Error: File not found." << endl;
        return 1;
    }

    logicHelp.LoadMultiDataFileCSV(indexFile, windLog);
    indexFile.close();

    bool flag = true;
    string input;
    while(flag)
    {
        //Get User input for which function
        cout << menuHelp.DisplayMenu() << endl;
        cin >> input;
        //Check which function user wants to use
        if(input == "1")
        {
            //Ask user which month and year they want to search for and validate those input
            string monthInput, yearInput;
            cout << "Input month to search(1-12)" << endl;
            cin >> monthInput;
            monthInput = logicHelp.RemoveLeadingZeros(monthInput);
            while(validateHelp.IsInteger(monthInput) == false)
            {
                cout << "Error: invalid month. Expects integer." << endl;
                cout << "Input month to search(1-12)" << endl;
                cin >> monthInput;
            }
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(validateHelp.IsInteger(yearInput) == false)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }
            while(validateHelp.IsValidDate(stoi(monthInput), stoi(yearInput)) == false)
            {
                cout << "Error: invalid date." << endl;
                cout << "Input month to search(1-12)" << endl;
                cin >> monthInput;
                monthInput = logicHelp.RemoveLeadingZeros(monthInput);
                while(validateHelp.IsInteger(monthInput) == false)
                {
                    cout << "Error: invalid month. Expects integer." << endl;
                    cout << "Input month to search(1-12)" << endl;
                    cin >> monthInput;
                }
                cout << "Input year to search" << endl;
                cin >> yearInput;
                while(validateHelp.IsInteger(yearInput) == false)
                {
                    cout << "Error: invalid year. Expects integer." << endl;
                    cout << "Input year to search" << endl;
                    cin >> yearInput;
                }
            }

            cout << menuHelp.FindAverageWindSpeedAndStandardDeviationMonth(windLog, stoi(monthInput), stoi(yearInput)) << endl;
        }
        else if (input == "2")
        {
            //Ask user for year to search for and validate the input
            string yearInput;
            cout << "Input year to search(YYYY)" << endl;
            cin >> yearInput;
            while(validateHelp.IsInteger(yearInput) == false ||yearInput.size() != 4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }

            cout << yearInput << endl;

            cout << menuHelp.FindAverageTemperatureYear(windLog, stoi(yearInput)) << endl;
        }
        else if (input == "3")
        {
            //Ask user which month they want to search for and validate those input
            string monthInput, yearInput;
            cout << "Input month to search(1-12)" << endl;
            cin >> monthInput;
            monthInput = logicHelp.RemoveLeadingZeros(monthInput);
            while(validateHelp.IsInteger(monthInput) == false)
            {
                cout << "Error: invalid month. Expects integer." << endl;
                cout << "Input month to search(1-12)" << endl;
                cin >> monthInput;
            }
            while(validateHelp.IsValidMonth(stoi(monthInput)) == false)
            {
                cout << "Error: invalid date." << endl;
                cout << "Input month to search(1-12)" << endl;
                cin >> monthInput;
                monthInput = logicHelp.RemoveLeadingZeros(monthInput);
                while(validateHelp.IsInteger(monthInput) == false)
                {
                    cout << "Error: invalid month. Expects integer." << endl;
                    cout << "Input month to search(1-12)" << endl;
                    cin >> monthInput;
                }
            }
            cout << menuHelp.FindsPCCForGivenMonth(windLog, stoi(monthInput)) << endl;
        }
        else if(input == "4")
        {
            //Ask user for which year to search for and validate the input
            string yearInput;
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(validateHelp.IsInteger(yearInput) == false || yearInput.size() !=4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }

            menuHelp.OutputFileAverageWindTempSolarMonth(windLog, stoi(yearInput));
        }
        else if (input == "5")
        {
            menuHelp.ReloadData(windLog);
        }
        else if (input == "6")
        {
            flag = false;
        }
        else
        {
            cout << "Error: Unknown command. Only numbers 1-6 accepted." << endl;
        }

    }
    return 0;
}
