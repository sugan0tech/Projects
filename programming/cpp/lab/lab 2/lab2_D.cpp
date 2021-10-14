#include<iostream>
#include<string.h>
using namespace std;

class rectangle
{

    public:

        double length,breadth;

        rectangle();
        rectangle(double);
        rectangle(double ,double );
        void area();
};

void rectangle::area()
{
    double area=length*breadth;
    cout<<"the area of the rectangle is : "<<area<<endl;
}
rectangle::rectangle(){
    length=0;
    breadth=0;
    area();
    
}

rectangle::rectangle(double num){
    double n1, n2;
    length=num;
    breadth=num;
    area();
}

rectangle::rectangle(double x,double y){
    length=x;
    breadth=y;
    area();
}

int main()
{

    int length,breadth;

    cout<<"enter the length of the rectangle : ";
    cin>>length;
    cout<<"enter the breadth of the rectangle : ";
    cin>>breadth;

    rectangle rect;
    rect.length = length;
    rect.breadth = breadth;
    rectangle(rect.length);
    rectangle(rect.length,rect.breadth);
    return 0;
}