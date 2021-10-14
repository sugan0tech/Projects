/*To write a header file that defines a function template that returns the smallest 
value (minimum) in an array of numbers (ints, doubles, floats, unsigned ints, etc.)*/
#include <iostream>
#include "lab4_B.h"
using namespace std;

int main()
{
    int arri[] = {8, 6, 2, 3, 4, 5};
    float arrf[] = {1.8, 1.6, 1.3, 1.4, 1.5};
    double arrd[] = {12358.0, 12346.2, 12347.1, 12348.01, 12349.01, 1235.10};
    cout << "for int :" << small<int>(arri, 6) << endl;
    cout << "for float :" << small<float>(arrf, 6) << endl;
    cout << "for double :" << small<double>(arrd, 6) << endl;
    return 0;
}