#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray(int n){
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
    return false;
    }

    if (value < -100 || value > 100) {
    return false;
    }

    data[index] = value;
    return true;
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= size) {
        throw "Index out of range";
    }
    return data[index];
}
bool DynamicArray::pushBack(int value) {
    if (value < -100 || value > 100) {
        return false;
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
    for (int i = 0; i < size; i++) {
        int value = 0;

        if (i < other.size) {
            value = other.data[i];
        }

        data[i] += value;
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    for (int i = 0; i < size; i++) {
        int value = 0;

        if (i < other.size) {
            value = other.data[i];
        }

        data[i] -= value;
    }
}

