#include<iostream>
using namespace std;

class person
{
    string name;
    int age;
    public:
    person(string n,int a)
    {
        name=n;
        age=a;
    }
    void display1()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class employee: public person
{
    int id;
    public:
    employee(string n,int a,int i):person( n, a)
    {
        id=i;
    }
    void display2()
    {
        display1();
        cout<<"id: "<<id<<endl;
    }
};

class manager: public employee
{
    string dept;
    public:
    manager(string n,int a,int i,string d):employee( n,a,i)
    {
        dept=d;
    }
    void displaydetails()
    {
        display2();
        cout<<"Department: "<<dept<<endl<<endl;
    }
};

int main()
{
    manager m1("Shrey",18,106,"Web designer");
    manager m2("Dhyey",18,113,"Advertisement");
    m1.displaydetails();
    m2.displaydetails();
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
