//Preprocessor Directive
//Standard library names in < >, 
//User-defined library names in " ".
#include <iostream>
using namespace std;

// No header, no hoisting. Functions/vars used in main() need to be declared 
// above main in a single-file program.

// declare a constant
const int number = 3;


//function with no return
void whisperToProgrammer() {
  cout << "Shhh, I'm telling you secretly" << endl;
}

//function with string return and int parameter with a default value
string shareTheMessageWithTheClass(int count = 10) {
    string message = "LA";
    for (int i = 1; i < count; i++) {
        message.append(" LA");
    }
    return message;
}

//pass in a reference
void setMeTo5(int &numToChange) {
    numToChange = 5;
}

//Note on function declarations: 
//Return types not used to tell overloads apart.  

//friendly neighborhood main function
int main()
{
    int changeable = 3;
    int& alias = changeable;
    changeable += 3;

    //if had not included namespace line.
    //std::cout << "Hello, World!" << std::endl;
    cout << "Hello, World! "; //<-- no end of line, it's not automatic.
    
    //has returns. alias should == 6
    cout << "I'm so happy to see you.\nHere are " << alias << " fish." << endl;

    //should be the memory pointers in hex, and they should be the same.
    cout << &alias << ' ' << &changeable << endl;

    //Don't forget in C++ case statements fall through by default.
    switch (changeable) {
        case 6:
            cout << "Everything as expected.\n";
            break;
        //And switches do NOT have to be exhaustive.
        // default:
        //     cout << "Something feels hinky.\n";
        //     break;
    }

    //Home sweet for loop home.
    for (int i = 1; i <= 5; i++) {
        cout << i;
    }
    cout << endl;

    //foreach
    //warning: range-based for loop is a C++11 extension
    //warning: 'auto' type specifier is a C++11 extension
    //to compile: g++ HelloWorld.cpp -std=c++17 -o HelloWorld
    int pi_times_100k[6] = {3, 1, 4, 1, 5, 9};
    //for (int number : pi_times_100k) {
    for (auto number : pi_times_100k) {
        cout << number;
    }
    cout << endl;

    whisperToProgrammer();
    setMeTo5(changeable);
    //Should print out 5 LA's
    cout << shareTheMessageWithTheClass(alias) << endl;

    //sometimes left out, but is the everything is okay line
    return 0;
}

