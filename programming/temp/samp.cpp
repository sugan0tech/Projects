#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>

using namespace std;

/*
1. Input strings
2. Split() with . delimiter
3. print from last
*/
int main()
{

    string input_str;
    vector<string> temp;

    cout << "Enter String: ";
    cin >> input_str;

    boost::split(temp, input_str, boost::is_any_of("."));

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << temp[i];
        }
        else
        {
            cout << temp[i] << ".";
        }
    }
}