#pragma once

class DynamicArray{
private:
    int* data;
    int size;
public:
    DynamicArray(int n);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    void print();
    bool set(int index, int value);
    int get(int index);
    bool pushBack(int value);
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};
