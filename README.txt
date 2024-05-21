Fumiya Shinagawa 
2416455
shinagawa@chapman.edu
CPSC-350-01
Assignment 3

Who Can See?

GenStack.h, input.txt, main.cpp, MonoStack.h, README.txt, SpeakerView.cpp, SpeakerView.h

Sources:
https://www.mygreatlearning.com/blog/templates-in-cpp/
https://www.geeksforgeeks.org/templates-cpp/
https://www.geeksforgeeks.org/implementing-stack-using-class-templates-in-cpp/
https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/

Struggles:
The biggest struggle in this assignment was reading the input file, and also creating the MonoStack. For the input file, since the rows are 
not the arrays, instead the columns are, which made me have to learn stringstreams and using that to split a string by its spaces. Stringstreams is 
a library that lets us work with strings, just like how I did by using it to split the string into pieces. Also, the MonoStack was confusing because
I at first through that it had to pop all of the numbers that aren't in order, push the original value that you want to push, then repush everything
back into the stack, instead of just popping whatever is not supposed to be there based on what is being added. 

Application Explanation:
This application takes in a input file, the name must be specified in the second command in the command line argument when running the application. 
It will take in a seating chart of NxP, and print the heights of the people who can see the front clearly, meaning that there isn't someone who is 
taller than them in front of them. If the inputFile does not have a clear NxP format, then it will throw an error. 
