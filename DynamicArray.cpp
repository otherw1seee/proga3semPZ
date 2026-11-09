#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>

DynamicArray::DynamicArray(int n){
    if (n <= 0) {
        throw std::invalid_argument("Invalid array size");
    }
    size = n;
    data = new int[size];

    for(int i=0; i<size; i++){
        data[i]=0;
    }
}

DynamicArray::~DynamicArray(){  
    delete[] data;
}

DynamicArray::DynamicArray(const DynamicArray &other){
    size = other.size;
    data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

void DynamicArray::print(){
    for(int i=0; i<size; i++){
        std::cout<< data[i] << ' ';
    }
}

bool DynamicArray::set(int index, int value){
    if (index < 0 || index >= size){
    throw std::out_of_range("Index out of range");
    }

    if (value < -100 || value > 100) {
    throw std::invalid_argument("Value must be from -100 to 100");
    }

    data[index] = value;
    return true;
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
bool DynamicArray::pushBack(int value) {
    if (value < -100 || value > 100) {
        throw std::invalid_argument("Value must be from -100 to 100");
    }

    int* newData = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    newData[size] = value;

    delete[] data;

    data = newData;
    size++;

    return true;
}

void DynamicArray::add(const DynamicArray& other) {
    if (size != other.size) {
        throw std::out_of_range("Arrays have different sizes");
    }
    for (int i = 0; i < size; i++) {
        int value = 0;

        if (i < other.size) {
            value = other.data[i];
        }

        data[i] += value;
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    if (size != other.size) {
        throw std::out_of_range("Arrays have different sizes");
    }
    for (int i = 0; i < size; i++) {
        int value = 0;

        if (i < other.size) {
            value = other.data[i];
        }

        data[i] -= value;
    }
}