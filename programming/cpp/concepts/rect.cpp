#include<iostream>
#include<string.h>
using namespace std;
class rect
{
    private:
        double width;
        double height;
    
    public:
        //member functions
        void store(double h, double w)
        {
            width = w;
            height = h;

        }
        void display(void)
        {
            std::cout<<"\nwidth : "<<width<<"\theight : "<<height;
        }
        double area(void)
        {
            return width*height;
        }
};


int main(void){
    rect c;
    c.store(10, 7);
    std::cout<<"\narea : "<< c.area();
    c.display();
}