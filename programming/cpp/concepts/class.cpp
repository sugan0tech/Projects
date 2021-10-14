#include<iostream>
#include<string.h>
using namespace std;

class cat
{
    private:
        string color, name;
        int age;
    public:
        void set(int Age, string clr, string Name )
        {
            age = Age;
            color = clr;
            name = Name;
        }
        void print()
        {
            cout<<"Name : "<< name << endl << "Age : "<< age << endl << "Color : " << color << endl;
            doo();
        }
        void doo() ;
};


void cat::doo()
{
    name = "bla";
    cout<<"hi"<<name;
}
int main()
{
    cat felis;
    felis.set(123, "Red", "Karupan");
    felis.print();
    felis.print();
    felis.doo();
}