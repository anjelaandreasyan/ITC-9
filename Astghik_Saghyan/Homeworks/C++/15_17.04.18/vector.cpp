#include <iostream>
#include "vector.hpp"

Vector::Vector() {
    int size = 0;
    int countForPush = 0;
    int countForPop = 0;
    int* vector = nullptr;
    std::cout << "Default constructor works!" << std::endl;
}

Vector::Vector(Vector& vec) {
    std::cout << "Copy constructor works!" << std::endl;
    this->vector = new int[vec.size+5];
    this->size = vec.size;
    this->countForPush = vec.countForPush;
    this->countForPop = vec.countForPop;
    for(int i = 0; i < vec.size; ++i) {
        this->vector[i] = vec.vector[i];
    }
}

Vector::Vector(Vector&& vec) {
    std::cout << "Move constructor works!" << std::endl;
    this->vector = vec.vector;
    this->size = vec.size;
    this->countForPush = vec.countForPush;
    this->countForPop = vec.countForPop;
    vec.vector = nullptr;
    vec.size = 0;
    vec.countForPush = 0;
    vec.countForPop = 0;
}

Vector::~Vector() {
    std::cout << "Delete constructor works!" << std::endl;
    delete [] vector;
    vector = nullptr;
}

void Vector::buildArr(int n, int fill) {
    vector = new int[n+5];
    size = n;
    for(int i = 0; i < size; ++i) {
        vector[i] = fill;
    }
}

int Vector::getSize() {
    return size;
}

int* Vector::getVector() {
    return vector;
}

int Vector::getElem(int index) {
    if(index < size) {
        return vector[index];
    } else {
        std::cout << "The vector hasn't " << index << "-th element" << std::endl;
    }
}

void Vector::push(int newElem) {
    ++size;
    vector[size] = newElem;
    ++countForPush;
    if(0 == countForPush%5) {
        int* tempVec = new int[size + 5];
        for(int i = 0; i < size; ++i) { 
            tempVec[i] = vector[i]; 
        }  
    delete vector; 
    vector = tempVec; 
    std::cout << "We pushed more than 5 time" << std::endl;
    }
}

void Vector::pop() {
    if(size > 0) {
        vector[size] = 0;
        --size;
    }
    ++countForPop;
    if(0 < size && 0 == countForPop%5) {
        int* tempVec = new int[size + 5];
        for(int i = 0; i < size; ++i) { 
            tempVec[i] = vector[i]; 
        }  
    delete vector; 
    vector = tempVec; 
    std::cout << "We poped more than 5 time" << std::endl;
    }
}

void Vector::printVec() {
    for(int i = 0; i < size; ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}




//move constructor in progress
//destructor in progress
