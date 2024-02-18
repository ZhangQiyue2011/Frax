#include<iostream>
#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction a(1, 2);
    const Fraction b(3, 4);
    Fraction c(1, 3, false);/*negative fraction*/
    const Fraction d(3, 15);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
}
