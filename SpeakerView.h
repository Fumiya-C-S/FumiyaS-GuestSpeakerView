#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "GenStack.h"
#include "MonoStack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class SpeakerView{
    public:
        SpeakerView(); //default constructor
        ~SpeakerView(); //destructor

        //core functions
        void readInput(string inputFile); //read the guest heights from the input
        void whoCanSee(); //print who is able to see the guest speaker in each column

    private:
        double **myDoubleArray; //2D to save which height is in which seat
        MonoStack<double> *myMonoStack; //MonoStack to see who can see guest speaker
        string fileContent; //string of what is in the input file

        double guestHeight; //saves each guestHeight to put into array
        int numSeeingGuests; //variable keeping track of number of guests that can see in a column


        int numLines = 0; //variable keeping track of P for NxP of guests
        int numCols = 0; //variable keeping track of N of NxP of guests
        int numGuests = 0; //variable keeping track of number of guests in total
};

#endif