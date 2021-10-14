/*To write a header file that defines a function template that returns the smallest 
value (minimum) in an array of numbers (ints, doubles, floats, unsigned ints, etc.)*/
#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
T small(T arr[], int size)
{
    T small = arr[0];
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] < small)
            small = arr[i];
    }

    return small;
}