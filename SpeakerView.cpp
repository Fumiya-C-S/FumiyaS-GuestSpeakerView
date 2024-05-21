#include "SpeakerView.h"

//default constructor
SpeakerView::SpeakerView(){}

//destructor
SpeakerView::~SpeakerView(){
    for (int i = 0; i < numCols; ++i){
        delete[] myDoubleArray[i]; //delete arrays inside the myDoubleArray array
    }
    delete[] myDoubleArray; //delete myDoubleArray
}

void SpeakerView::readInput(string inputFile){

    ifstream inFile; //create input File Stream
    string indHeight; //string containing individual heights

    inFile.open(inputFile); //open file "input.txt"

    if(inFile.is_open()){ //if file is open
        while(getline(inFile, fileContent)){ //get a line
            numLines++; //increment number of lines
            stringstream ss(fileContent); //create a string streams
            while(getline(ss, indHeight, ' ')){ //split the stringstream into individual strings by slicing at each space
                numGuests++; //increment for each individual string created
            }
        }
        if (numGuests % 2 != 0){
            throw runtime_error("Invalid input file");
        }

        numCols = numGuests / numLines; //area divided by one side = other side (12 guests / 4 lines = 3 columns of guests)

        myDoubleArray = new double*[numCols]; //use numCols, numLines to create a 2D array
        for (int i = 0; i < numCols; ++i) {
            myDoubleArray[i] = new double[numLines]; //creates arrays inside of array based on number of columns
        }

        //reset the file to read from the beginning again
        inFile.clear(); 
        inFile.seekg(0, ios::beg);

        int cols; //create cols int to iterate through the 2D array
        int rows = numLines - 1; //create rows int to iterate through the array inside array, but backwards 
        while(getline(inFile, fileContent)){
            cols = 0;
            stringstream ss(fileContent);
            while(getline(ss, indHeight, ' ')){ //due to the format of input.txt, the while loop will fill index 0 of all arrays first, then all index 1 ...
                myDoubleArray[cols][rows] = stod(indHeight);
                cols++; //go to next array
            }
            rows--; //go to the space before
        }
    }
    inFile.close(); //close the file

    whoCanSee(); //call the whoCanSee() function
}

//whoCanSee() function
void SpeakerView::whoCanSee(){

    myMonoStack = new MonoStack<double>(numLines); //initialize the MonoStack
    numSeeingGuests = 0; //set numSeeingGuests to 0 as a default

    for (int i = 0; i < numCols; ++i){ //iterate through the first array
        cout << "In column " << i << " there are ";
        for (int j = 0; j < numLines; ++j){ //push the contents of myDoubleArray into MonoStack
            myMonoStack->push(myDoubleArray[i][j], 'd'); //pushing to MonoStack
        }

        numSeeingGuests = myMonoStack->getSize(); //get the size of myMonoStack, since the number of guests left inside are the guests that can see

        cout << numSeeingGuests << " that can see. Their heights are: ";
        myMonoStack->print(); //print all of the guests that can see

        for (int j = 0; j < numSeeingGuests; ++j){ //iterate through the MonoStack
            myMonoStack->pop(); //pop every guest in MonoStack to get a clear new MonoStack for next array
        }

        cout << endl;
    }

    delete myMonoStack; //garbage collect myMonoStack

}