#include "SpeakerView.h"

int main(int argc, char const *argv[])
{
    SpeakerView *mySV = new SpeakerView; //initialize SpeakerView

    try{ //try the following code
        mySV->readInput(argv[1]);
    }
    catch(runtime_error &excpt){ //if an error is thrown
        cout << excpt.what() << endl;  //print the error
    }

    delete mySV; //garbage collect SpeakerView
    return 0;
}
