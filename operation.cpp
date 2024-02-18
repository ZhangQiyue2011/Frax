#include<iostream>
#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction a(1, 2);
    const Fraction b(3, 4);
    Fraction c = a + b;
    Fraction d = b - a;
    Fraction e = a * b;
    Fraction f = a / b;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    //
    Fraction g = -a;
    cout << g << endl;
    Fraction pa(1, 3);
    cout << ++pa << endl;
    Fraction pb(1, 3);
    cout << pb++ << endl;
    Fraction pc(1, 3);
    cout << --pc << endl;
    Fraction pd(1, 3);
    cout << pd-- << endl;
    cout <<  (a < c) << endl;
    cout << (a > c) << endl;
    cout << (pa == pb) << endl;
    cout << (a <= pb) << endl;
    cout << (pb >= a) << endl;
    Fraction l1(1, 2);
    l1 = -l1;
    Fraction l2(1, 2, false);
    cout << l1 << " " << l2 << endl;
    return 0;
}
