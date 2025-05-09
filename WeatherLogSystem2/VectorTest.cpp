/**
 * @file Vector.h
 * @author Khon Min Thite
 * @brief Unit test for Vector.h
 * @version 0.1
 * @date 24-3-2024
 *
 *
 */


#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
    // Test default constructor
    Vector<int> testVector1;
    cout << "Default Constructor" << endl;
    cout << "Size: " << testVector1.size() << endl;
    cout << "Capacity: " << testVector1.capacity() << endl;
    cout << "Is Empty: " << (testVector1.empty() ? "Yes" : "No") << endl << endl;

    // Test constructor with size
    Vector<int> testVector2(5);
    cout << "Constructor with size" << endl;
    cout << "Size: " << testVector2.size() << endl;
    cout << "Capacity: " << testVector2.capacity() << endl;
    cout << "Is Empty: " << (testVector2.empty() ? "Yes" : "No") << endl << endl;

    // Test constructor with size and initial value
    Vector<int> testVector3(5, 10);
    cout << "Constructor with size and initial value" << endl;
    cout << "Size: " << testVector3.size() << endl;
    cout << "Capacity: " << testVector3.capacity() << endl;
    cout << "Is Empty: " << (testVector3.empty() ? "Yes" : "No") << endl << endl;

    // Test element access
    testVector3[0] = 20;
    cout << "Element Access" << endl;
    cout << "First Element: " << testVector3[0] << endl;
    cout << "Second Element: " << testVector3[1] << endl << endl;

    // Test push_back
    testVector3.push_back(30);
    cout << "Push Back" << endl;
    cout << "Size: " << testVector3.size() << endl;
    cout << "Capacity: " << testVector3.capacity() << endl;
    cout << "Last Element: " << testVector3[testVector3.size() - 1] << endl << endl;

    // Test pop_back
    testVector3.pop_back();
    cout << "Pop Back" << endl;
    cout << "Size: " << testVector3.size() << endl;
    cout << "Capacity: " << testVector3.capacity() << endl << endl;

    // Test reserve
    testVector3.reserve(10);
    cout << "Reserve" << endl;
    cout << "Size: " << testVector3.size() << endl;
    cout << "Capacity: " << testVector3.capacity() << endl << endl;

    // Test resize
    testVector3.resize(3);
    cout << "Resize" << endl;
    cout << "Size: " << testVector3.size() << endl;
    cout << "Capacity: " << testVector3.capacity() << endl << endl;

    // Test iterators
    cout << "Iterators" << endl;
    for (auto it = testVector3.begin(); it != testVector3.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
