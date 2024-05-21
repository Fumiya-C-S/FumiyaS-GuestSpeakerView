#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class GenStack{
    public:
        GenStack(); //default constructor
        GenStack(int maxSize); //overloaded constructor
        ~GenStack(); //destructor

        //core functions
        void push(T data); //push Function
        T pop(); //pop Function
        T peek(); //peek Function

        //auxiliary functions
        int getSize(); //returns size of array
        bool isEmpty(); //returns true or false if array is empty or not
        bool isFull(); //returns true or false if array is full or not

    private:
        int top; //variable keeping track of top
        int mSize; //variable keeping track of size
        T *myArray; //array in use
};

//default constructor
template <class T>
GenStack<T>::GenStack(){
    mSize = 64; //size of array is 64
    top = -1; //top is -1
    myArray = new T[mSize]; //initialize new array
}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize){
    mSize = maxSize; //set mSize to size that is passed in 
    top = -1; //top is -1
    myArray = new T[mSize]; //initialize new array
}

//destructor
template <class T>
GenStack<T>::~GenStack(){
    delete[] myArray; //delete myArray off heap
}

//push Function
template <class T>
void GenStack<T>::push(T data){
    //check if stack is full, if it is full
    if (isFull()){
        cout << "stack resizing to accomodate more data" << endl;
        T *temp = new T[2*mSize]; //create new array with 2x size
        for (int i = 0; i < mSize; ++i){
            temp[i] = myArray[i]; //copy everything into new bigger array
        }
        mSize*= 2; //change variables
        delete[] myArray; //delete old array
        myArray = temp; //copy new array
    }

    myArray[++top] = data; //add the variable to array
}

//peek Function
template <class T>
T GenStack<T>::pop(){
    //check if empty
    if (isEmpty()){
        throw runtime_error("Stack is Empty"); //throw error
    }

    return myArray[top--]; //change index of top to one less, esentially deleting the top value
}

//peek function
template <class T>
T GenStack<T>::peek(){
    //check if empty
    if (isEmpty()){
        throw runtime_error("Stack is Empty"); //throw error
    }
    
    return myArray[top]; //return the top value of the function
}

//getSize function
template <class T>
int GenStack<T>::getSize(){
    return top + 1; //return size of array
}

//isFull function
template <class T>
bool GenStack<T>::isFull(){
    return (top == mSize-1); //return true or false on if array is full or not
}

//isEmpty function
template <class T>
bool GenStack<T>::isEmpty(){
    return (top == -1); //return true or false on if array is empty or not
}

#endif