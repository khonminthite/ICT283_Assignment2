/**
 * @file BstTest.spp
 * @author Khon Min Thite
 * @brief Unit test for Bst.h
 * @version 0.1
 * @date 5-3-2024
 *
 *
 */

#include "Bst.h"
#include "BstWeatherHelper.h"

using namespace std;

int main()
{
    //Check that Constructor can correctly initialize an empty BST and Operator[] will throw out of range exception
    Bst<Weather> weatherTree1;
    cout << "Test Constructor" << endl;
    cout << weatherTree1.TreeNodeCount() << endl;
    cout << endl;

    //Check that the copy constructor can correctly deep copy another Vector
    cout << "Test Copy constructor" << endl;
    Bst<int> intTree1;
    intTree1.Insert(1);
    Bst<int> intTree2(intTree1);
    cout << "Tree 1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;

    cout << "Tree 2 values after copying Tree 1 and deleting Tree 1: ";
    intTree1.DeleteTree();
    intTree2.InOrderTraversal();
    cout << endl;
    cout << endl;

    //Check that the destructor can successfully delete the Vector
    cout << "Test destructor" << endl;
    cout << "Tree 1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;

    cout << "Tree 2 values: ";
    intTree2.InOrderTraversal();
    cout << endl;

    intTree2.~Bst();
    cout << "Tree 2 values after destruction: ";
    intTree2.InOrderTraversal();
    cout << endl;
    cout << endl;

    //Check that BST is correctly deleted using deleteTree function
    cout << "Test DeleteTree function" << endl;
    cout << "Tree 1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;

    intTree1.DeleteTree();
    cout << "Tree 1 values after deleting tree: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << endl;

    //Check that Operator= can correctly deep copy another Vector
    cout << "Test = operator" << endl;
    intTree1.Insert(1);
    cout << "Tree 1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;

    cout << "Tree 2 values after copying Tree 1 and deleting Tree 1: ";
    intTree2 = intTree1;
    intTree1.DeleteTree();
    intTree2.InOrderTraversal();
    cout << endl;
    cout << endl;

    //Check that Search function can correctly determine if a value exist in BST
    cout << "Test Search function" << endl;
    cout << "Value found: " << intTree2.Search(1) << endl;
    cout << "Value not found: " << intTree2.Search(2) << endl;
    cout << endl;

    //Check that Insert function can correctly insert into BST
    cout << "Test Insert function" << endl;
    cout << "Tree 1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;

    cout << "After insert" << endl;
    intTree1.Insert(1);
    intTree1.Insert(2);
    intTree1.Insert(5);
    intTree1.Insert(4);
    intTree1.Insert(3);
    cout << "Tree 1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << endl;

    //Check that DeleteNode function can correctly delete a node in BST by value given
    cout << "Test DeleteNode function" << endl;
    cout << "Tree 1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;

    cout << "Deletes node" << endl;
    intTree1.DeleteNode(1);
    cout << "Tree 1 values after delete: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << endl;

    //Check that TreeNodeCount function can return the correct number of node in BST
    cout << "Test TreeNodeCount function" << endl;
    cout << "Count: " << intTree1.TreeNodeCount() << endl;
    cout << endl;
    //Create and insert weather objects
    BstWeatherHelper BST;

    Weather testWeather1;
    Date testDate1(16,3,2016);
    testWeather1.SetDate(testDate1);
    Time testTime2(9,15);
    testWeather1.SetTime(testTime2);
    testWeather1.SetWindSpeed(23.1);
    testWeather1.SetSolarRadiation(53.15);
    testWeather1.SetAirTemp(53.25);

    Weather testWeather2;
    Date testDate2(16,3,2016);
    testWeather2.SetDate(testDate2);
    Time testTime3(9,15);
    testWeather2.SetTime(testTime3);
    testWeather2.SetWindSpeed(33.1);
    testWeather2.SetSolarRadiation(53.15);
    testWeather2.SetAirTemp(53.25);

    Weather testWeather3;
    Date testDate3(16,3,2016);
    testWeather3.SetDate(testDate3);
    Time testTime4(9,15);
    testWeather3.SetTime(testTime4);
    testWeather3.SetWindSpeed(13.1);
    testWeather3.SetSolarRadiation(53.15);
    testWeather3.SetAirTemp(57.25);

    weatherTree1.Insert(testWeather1);
    weatherTree1.Insert(testWeather2);
    weatherTree1.Insert(testWeather3);
    //Check that InOrderTraversal function can traverse the BST in an in order way
    cout << "Test InOrderTraversal function" << endl;
    intTree1.Insert(1);
    intTree1.InOrderTraversal();
    cout << endl;
    cout << endl;

    //Check that PRE-OrderTraversal function can traverse the BST in a pre order way
    cout << "Test PRE-OrderTraversal function" << endl;
    intTree1.PreOrderTraversal();
    cout << endl;
    cout << endl;

    //Check that PostOrderTraversal function can traverse the BST in a post order way
    cout << "Test PostOrderTraversal function" << endl;
    intTree1.PreOrderTraversal();
    cout << endl;
    cout << endl;

    //Check that GetSumValueFloat function can correctly get the total value of all nodes in BST
    cout << "Test GetSumValueFloat function" << endl;
    cout << intTree1.GetSumValueFloat() << endl;
    cout << "Test GetSumValueFloat with function as parameter" << endl;
    cout << weatherTree1.GetSumValueFloat(BST.GetWeatherWindSpeed) << endl;
    cout << endl;

    //Check that InOrderTraversalFloat function can correctly get the value of individual nodes in BST
    cout << "Test InOrderTraversalFloat function" << endl;
    cout << weatherTree1.InOrderTraversalFloat(BST.GetWeatherAirTemp) << endl;
    return 0;
}
