#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "--- TEST 1: Default (Empty) Array ---" << std::endl;
    Array<int> emptyArr;
    std::cout << "Empty array size: " << emptyArr.size() << std::endl;
    std::cout << std::endl;

    std::cout << "--- TEST 2: Int Array with Value-Initialization ---" << std::endl;
    Array<int> intArr(5);
    std::cout << "Int array size: " << intArr.size() << std::endl;
    std::cout << "Initial values (must be 0): ";
    for (unsigned int i = 0; i < intArr.size(); ++i)
    {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    for (unsigned int i = 0; i < intArr.size(); ++i)
    {
        intArr[i] = (i + 1) * 10;
    }
    
    std::cout << "Modified values             : ";
    for (unsigned int i = 0; i < intArr.size(); ++i)
    {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "--- TEST 3: Deep Copy & Assignment ---" << std::endl;
    Array<int> copyArr(intArr);
    Array<int> assignArr;
    assignArr = intArr;

    intArr[0] = 999;
    
    std::cout << "Original array[0] (modified) : " << intArr[0] << std::endl;
    std::cout << "Copied array[0]   (isolated) : " << copyArr[0] << std::endl;
    std::cout << "Assigned array[0] (isolated) : " << assignArr[0] << std::endl;
    std::cout << std::endl;

    std::cout << "--- TEST 4: Exception Handling ---" << std::endl;
    try
    {
        std::cout << "Attempting to read index 5 of an array with size 5..." << std::endl;
        std::cout << intArr[5] << std::endl;
    } catch (const std::exception& e)
    {
        std::cout << "[SUCCESS] Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Attempting to write to index 0 of an empty array..." << std::endl;
        emptyArr[0] = 42;
    } catch (const std::exception& e) {
        std::cout << "[SUCCESS] Exception caught: " << e.what() << std::endl;
    }

    return 0;
}