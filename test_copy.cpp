#include<iostream>
using namespace std;

class Component
{
private:
    int val;
public:
    Component(int v): val(v) {}
    ~Component();
    int get_val() {return val;}
};


Component::~Component()
{
}


class MyClass
{
private:
    Component comp;
    Component *compPtr;
public:
    MyClass(Component cp, Component *cpPtr) : comp(cp) , compPtr(cpPtr) {}
    MyClass(const MyClass &myclass) : comp(myclass.comp)
    {
        this->compPtr = new Component(*myclass.compPtr);
    }
    ~MyClass();
    void print()
    {
        cout << "val: " << comp.get_val() << endl;
        cout << "compPtr: " << compPtr << endl;
        cout << "*compPtr.val: " << compPtr->get_val() << endl;
    }
};

MyClass test(MyClass myclass)
{
    return myclass;
}


MyClass::~MyClass()
{
}


int main()
{
    Component comp(1);
    Component comp2(3);
    MyClass mycl1(comp, &comp2);
    mycl1.print();
    cout << "test!" << endl;
    test(mycl1).print();
    return 0;
}
