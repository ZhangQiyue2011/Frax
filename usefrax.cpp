#include<iostream>
#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction a;
    unsigned denoa, molea;
    cin >> molea >> denoa;
    a = Fraction(molea, denoa);
    Fraction b;
    unsigned denob, moleb;
    cin >> moleb >> denob;
    b = Fraction(moleb, denob);
    string cmd;
    cin >> cmd;
    Fraction c;
    if (cmd == "+")
    {
        c = a + b;
    }
    else if (cmd == "-")
    {
        c = a - b;
    }
    else if (cmd == "*")
    {
        c = a * b;
    }
    else if (cmd == "/")
    {
        c = a / b;
    }
    else if (cmd == "re")
    {
        a.reciprocal();
        c = a;
    }
    else
    {
        cout << "What a command?\n";
        return 0;
    }
    cout << c << endl;
    return 0;
    
    
    
    
    
}
