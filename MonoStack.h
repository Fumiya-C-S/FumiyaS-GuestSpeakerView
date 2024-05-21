#ifndef MONOSTACK_H
#define MONOTSTACK_H

#include "GenStack.h"
#include <iostream>
#include <exception>
using namespace std;

template <class T>
class MonoStack{
    public:
        MonoStack(); //default constructor
        MonoStack(int maxSize); //overloaded constructor
        ~MonoStack(); //destructor

        //core functions
        //normal push function
        void push(T data);
        //Push Function in Increasing or Decreasing Order
        void push(T data, char o);
        //Pop Function
        T pop();
        //Peek Function
        T peek();

        //auxiliary functions
        int getSize(); //returns the size of array
        bool isEmpty(); //true or false if array is empty or not
        bool isFull(); //true or false if array is full or not
        void print(); //prints array

    private:
        int top; //variable keeping track of top
        int mSize; //the maximum number of elements in array
        T *myArray; //array in use
};

//default constructor
template <class T>
MonoStack<T>::MonoStack(){
    mSize = 64; //size of array is 64
    top = -1; //top is -1
    myArray = new T[mSize]; //initialize new array
}

//overloaded constructor
template <class T>
MonoStack<T>::MonoStack(int maxSize){
    mSize = maxSize; //set size of array to the value passed in
    top = -1; //top is at index -1
    myArray = new T[mSize]; //initialize new array
}

//destructor
template <class T>
MonoStack<T>::~MonoStack(){
    delete[] myArray; //delete array
}

//original push function
template<class T>
void MonoStack<T>::push(T data){
    //if array is full, create a new array with twice the size
    if (isFull()){ 
        cout << "stack resizing to accomodate more data" << endl;
        char *temp = new char[2*mSize];
        for (int i = 0; i < mSize; ++i){
            temp[i] = myArray[i];
        }
        mSize*= 2;
        delete[] myArray;
        myArray = temp;
    }

    myArray[++top] = data; //add data to current top
}

//monotonic stack push
template <class T>
void MonoStack<T>::push(T data, char o){
    //if array is full, create a new array with twice the size
    if (isFull()){
        cout << "stack resizing to accomodate more data" << endl;
        T *temp = new T[2*mSize];
        for (int i = 0; i < mSize; ++i){
            temp[i] = myArray[i];
        }
        mSize*= 2;
        delete[] myArray;
        myArray = temp;
    }

    //if 'i', array will be in increasing order
    if (o == 'i'){
        while (!isEmpty() && myArray[top] > data){ //while array isn't empty, if the top value of array is more than the inputted value
            pop(); //pop that value
        }
    } else if (o == 'd'){
        while (!isEmpty() && myArray[top] < data){ //while array isn't empty, if the top value of array is less than the inputted value
            pop(); //pop that value
        }
    }

    myArray[++top] = data; //add data to current top

}

//Pop Function
template <class T>
T MonoStack<T>::pop(){
    //check if empty
    if (isEmpty()){ 
        throw runtime_error("Stack is Empty"); //if empty throw error
    }

    return myArray[--top]; //change index of top to one less, esentially deleting the top value
}

//Peek function
template <class T>
T MonoStack<T>::peek(){
    //check if empty
    if (isEmpty()){
        throw runtime_error("Stack is Empty"); //if empty throw error
    }

    return myArray[top]; //return the top value
} 

//getSize function
template <class T>
int MonoStack<T>::getSize(){
        return top + 1; //return the current top + 1, which is the size of the array
}

//isFull function
template <class T>
bool MonoStack<T>::isFull(){
    return (top == mSize-1); //return true or false on if the array is full or not
}

//isEmpty function
template <class T>
bool MonoStack<T>::isEmpty(){ 
    return (top == -1); //return true or false on if the array is empty or not
}

//print function
template <class T>
void MonoStack<T>::print(){
    //check if empty
    if (isEmpty()){
        throw runtime_error("Stack is Empty"); //if empty throw error
    }

    for (int i = getSize() - 1; i >= 0; --i){ //print array in reverse order, since the front guest is at index 0
        cout << myArray[i] << " "; 
    }
    cout << endl;
}

#endif