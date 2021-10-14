#include<iostream>
using namespace std;

class parent
{
    public:
        int data_member1;
        void parent_func()
        {
            cout<<"A parent function";
        }

};

class child:public parent 
{
    public:
        int data_member_child;
        void child_func()
        {
            cout<<"A child function";
        }
};

int main()
{
    child kid;
    kid.child_func();
    kid.parent_func();
}