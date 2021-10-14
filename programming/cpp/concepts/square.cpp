#include<iostream>
#include<string.h>
using namespace std;

class square
{
    private:
        double size;
    
    public:
        void store(double r)
        {
            size = r;
        }
        void display(void)
        {
            std::cout<<"\nsize : "<<size;
        }
        double area(void)
        {
            return size*size;
        }
};


int main(void){
    square c;
    c.store(190.2);
    std::cout<<"\narea : "<< c.area();
    c.display();
}