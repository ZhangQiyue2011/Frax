#include<iostream>
#include"Fraction_copy.hpp"
using namespace std;

int main()
{
    Fraction a0(0, 1);
    int n;
    cin >> n;
    int flag = 1;
    Fraction a(0, 1);
    Fraction *b = new Fraction(0, 1);
    for (int i = 0; i < n; i++)
    {
        *b = Fraction(8, flag * (flag + 2));
        
        a = a + *b;
        flag += 4;
        

    }/*
    Fraction ejid(4, 1);
    Fraction erj(4 , 3, bf);
    cout << ejid + erj << endl;*/
    cout << a << endl;
    cout << a.ref_value() << endl;
    
}
