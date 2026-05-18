#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

void increment(int& number)
{
    number += 1;
}

int main()
{
    // --- TEST 1: Non-const Integer Array ---
    std::cout << "--- TEST 1: Non-const Integer Array ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original array : ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incrementing elements..." << std::endl;
    ::iter(intArray, intLen, increment);

    std::cout << "Modified array : ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl << std::endl;


    // --- TEST 2: Const Double Array ---
    std::cout << "--- TEST 2: Const Double Array (Should support const) ---" << std::endl;
    const double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Const double array: ";
    ::iter(doubleArray, doubleLen, printElement<double>);
    std::cout << std::endl << std::endl;


    // --- TEST 3: String Array ---
    std::cout << "--- TEST 3: String Array ---" << std::endl;
    std::string strArray[] = {"Hello", "42", "Kocaeli", "Network"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    ::iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}