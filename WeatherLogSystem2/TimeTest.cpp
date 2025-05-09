/**
 * @file TimeTest.cpp
 * @author Khon Min Thite
 * @brief Unit test for Time
 * @version 0.1
 * @date 18-02-2024
 *
 * @version 0.2
 * @date 3-3-2024
 * Added testing for < operator overload function
 * Added testing for > operator overload function
 *
 * @version 0.3
 * @date 23-3-2024
 * Added testing for == operator overload function
 */

#include "TIME.H"

#include <iostream>

using namespace std;

int main ()
{

    //Check constructor correctly initializes the data and all getters are able to retrieve the data
    Time testTime1;
    cout << " Default Constructor " << endl;
    cout << " Hour:   " << testTime1.GetHour() << endl;
    cout << " Minute: " << testTime1.GetMinute() << endl;
    cout << endl;

    Time testTime2(10,30);
    cout << " Constructor " << endl;
    cout << " Hour:   " << testTime2.GetHour() << endl;
    cout << " Minute: " << testTime2.GetMinute() << endl;
    cout << endl;

    //Check that setters are working correctly
    cout << " Test Setters" << endl;

    //Check that hour setter are working correctly
    cout << " Test Hour setter" << endl;
    testTime2.SetHour(9);
    cout << " Hour:   " << testTime2.GetHour() << endl;

    //Check that minute setter are working correctly
    cout << " Test Minute setter" << endl;
    testTime2.SetMinute(56);
    cout << " Minute: " << testTime2.GetMinute() << endl << endl;

    //Check that < operator overload function can correctly compare 2 Time objects
    cout << " Test < operator" << endl;
    testTime1.SetHour(5);
    testTime1.SetMinute(5);
    cout << " Test Time 1: " << testTime1.Display24HTime() << endl;
    cout << " Test Time 2: " << testTime2.Display24HTime() << endl;
    cout << " Compare testTime 1 < testTime 2: " << (testTime1 < testTime2) << endl;
    cout << endl;

    //Check that > operator overload function can correctly compare 2 Time objects
    cout << " Test > operator" << endl;
    cout << " Compare testTime 1 > testTime 2: " << (testTime1 > testTime2) << endl;
    cout << endl;

    //Check that == operator overload function can correctly equate 2 Time objects
    cout << " Test == operator" << endl;
    cout << " Check testTime 1 == testTime 2: " << (testTime1 == testTime2) << endl;
    cout << endl;
    return 0;
}
