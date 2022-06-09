#include <iostream>
using namespace std;

class Base{
    public:
    virtual void print(){
        cout<<"print of base class \n";
    }
    void display(){
        cout<<"display of base class \n";
    }
};
class Derived: public Base{
    public:
    virtual void print(){
        cout<<"print of derived class \n";
    }
    void display(){
        cout<<"display of derived class \n";
    }
};
int main()
{
    Base *baseptr;
    Derived d;
    baseptr = &d;

    baseptr -> print();
    baseptr -> display();

}