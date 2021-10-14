#include <iostream>
#include <string.h>
using namespace std;

class bank
{
    private:
        string name;
        double Account_num;
        string Account_type;
        double Balance_amount;

    public:

        void set(void)
        {
            cout<<"\nname : ";
            cin>>name;
            cout<<"\nAccount number : ";
            cin>>Account_num;
            cout<<"\nAccount type : ";
            cin>>Account_type;
            cout<<"\nBalance Amount : ";
            cin>>Balance_amount;
        }
        
        void deposit(double n)
        {
            Balance_amount += n;
        }

        void withdraw(double n)
        {
            if (Balance_amount > n)
                Balance_amount -= n;
            else
                cout << "Un sufficient Balance";
        }

        void display(void)
        {
            cout <<"\nName : "<< name << "\tAccount Number : " << Account_num <<"\tAccount type : "<< Account_type << "\tAccount Balance : " << Balance_amount; 
        }
};


int main()
{
    bank usr;
    double ammount;
    usr.set();
    usr.display();
    cout << "\nEnter the Deposite value : ";
    cin>> ammount;
    usr.deposit(ammount);
    usr.display();
    cout << "\nEnter the withdrawl value : ";
    cin>> ammount;
    usr.withdraw(ammount);
    usr.display();
}