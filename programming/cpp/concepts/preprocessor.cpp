/* Preprocessor of 4 types
    -Macros
    -File inclusion
    -Conditional Compilation
    -other directives
*/
#include <iostream> //file inclusion #include<file name>
#include "external.cpp"
#define limit 5            // macros
#define area(a, b) (a * b) // macros with arguments
using namespace std;

int main()
{
    f(); // calling function from external.cpp {notice there is no main funtion in external .cpp}
    cout << area(2, 4) << endl;
}
#undef limit // undefining the existing macro