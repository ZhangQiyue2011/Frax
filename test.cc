#include<iostream>
#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction *b = new Fraction(3);
    Fraction *a = b;
    cout << *a << " " << *b << endl;
}
