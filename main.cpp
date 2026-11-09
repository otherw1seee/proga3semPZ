#include "DynamicArray.h"
#include <iostream>
#include <windows.h>

DynamicArray vvodDynamicArray() {
    int size;
    std::cout << "Enter array size:\n";
    std::cin >> size;
    while (size <= 0) {
        std::cout << "Size must be greater than zero. Try again:\n";
        std::cin >> size;
    }
    DynamicArray arr(size);
    for (int i = 0; i < size; ++i) {
        int value;
        std::cout << "Enter value for index " << i << " (from -100 to 100):\n";
        std::cin >> value;
        while (!arr.set(i, value)) {
            std::cout << "Invalid value. Try again:\n";
            std::cin >> value;
        }
    }
    return arr;
}

int main() {
    SetConsoleOutputCP(65001);
    std::cout << "Enter the FIRST array:\n";
    DynamicArray arr1 = vvodDynamicArray();
    std::cout << "First array:\n";
    arr1.print();
    std::cout << "\nEnter the SECOND array:\n";
    DynamicArray arr2 = vvodDynamicArray();
    std::cout << "Second array:\n";
    arr2.print();
    std::cout << "\n";
    std::cout << "GETTING AN ELEMENT\n";
    int index;
    std::cout << "Enter element index in the first array:\n";
    std::cin >> index;
    try {
        std::cout << "Element: " << arr1.get(index) << "\n";
    }
    catch (const char* error) {
        std::cout << error << "\n";
    }
    std::cout << "\n";
    std::cout << "CHANGING AN ELEMENT\n";
    int value;
    std::cout << "Enter element index:\n";
    std::cin >> index;
    std::cout << "Enter new value (from -100 to 100):\n";
    std::cin >> value;
    if (arr1.set(index, value)) {
        std::cout << "Element successfully changed\n";
    }
    else {
        std::cout << "Error: invalid index or value\n";
    }

    std::cout << "First array:\n";
    arr1.print();

    std::cout << "\n";
    std::cout << "COPY CONSTRUCTOR\n";

    DynamicArray arr3 = arr1;

    std::cout << "Copied array:\n";
    arr3.print();

    std::cout << "\n";
    std::cout << "ADDING AN ELEMENT\n";

    std::cout << "Enter value to add to the end of the first array (from -100 to 100):\n";
    std::cin >> value;

    if (arr1.pushBack(value)) {
        std::cout << "First array after adding an element:\n";
        arr1.print();
    }
    else {
        std::cout << "Error: value must be from -100 to 100\n";
    }

    std::cout << "\n";
    std::cout << "ADDING ARRAYS\n";

    arr1.add(arr2);

    std::cout << "First array after adding the second array:\n";
    arr1.print();

    std::cout << "\n";
    std::cout << "SUBTRACTING ARRAYS\n";

    arr1.subtract(arr2);

    std::cout << "First array after subtracting the second array:\n";
    arr1.print();

    std::cin.ignore();
    std::cin.get();

    return 0;
}