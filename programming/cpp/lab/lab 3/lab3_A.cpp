/*Implement a program of maintaining banking account information system using multiple 
inheritance in C++ Programming. Here class savings derived from class  account and class 
user. Use appropriate functions and variables.*/
#include <iostream>
#include <string.h>
using namespace std;

class account
{
public:
    long int account_num;
    string User_name, account_type, status;
    void get_account();
    void set_account(long int account_num, string User_name, string account_type, string status);
};

void account::set_account(long int account_num, string User_name, string account_type, string status)
{
    this->account_num = account_num;
    this->User_name = User_name;
    this->account_type = account_type;
    this->status = status;
};

void account::get_account()
{
    cout << "\nAccount number : " << this->account_num << "\nUser name : " << this->User_name << "\nstatus : " << this->status << "\naccount_type : " << this->account_type;
}

class user
{
public:
    string name, address;
    long long int phone;
    int age, user_id;
    static int user_count;

public:
    void get_user();
    void set_user(string name, string address, long long int phone, int age);
};

void user::set_user(string name, string address, long long int phone, int age)
{
    this->name = name;
    this->address = address;
    this->age = age;
    this->phone = phone;
    this->user_id = ++user_count;
};

int user::user_count = 0;

void user::get_user()
{
    cout << "\nuser name : " << this->name << "\nage : " << this->address << "\nuser_id : " << this->user_id << "\nphone : " << this->phone;
}

class savings : public user, public account
{
public:
    int savings_limit = 100000, savings, net_bal;

public:
    float interest = 0.04;
    void set(int savings, int net_bal);
    void get_savings();
    void deposit();
    void withdraw();
    void info();
};

void savings::set(int savings, int net_bal)
{
    user::set_user("sugavanesh", "salem", 8778559307, 18);
    account::set_account(user::user_id, user::name, "savings", "active");
    this->savings = savings;
    this->net_bal = net_bal;
};

void savings::get_savings()
{
    cout << "\nSavings limit : " << this->savings_limit << "\nsavings : " << this->savings << "\nnet bal : " << this->net_bal;
}

void savings::info()
{
    cout << "\n\n\tFrom user obj part : \n";
    user::get_user();
    cout << "\n\n\tFrom account obj part : \n";
    account::get_account();
    cout << "\n\n\tFrom savings obj part : \n";
    get_savings();
};

void savings::deposit()
{
    int ammount;
    cout << "\nEnter the amount to deposit :";
    cin >> ammount;
    this->net_bal = this->net_bal + ammount;
};

void savings::withdraw()
{
    int ammount;
    cout << "\nEnter the amount to withdraw :";
    cin >> ammount;
    this->net_bal = this->net_bal - ammount;
};

int main()
{
    savings me;
    me.set(100, 5000);
    me.info();
    me.deposit();
    me.withdraw();
    me.info();
    return 0;
}