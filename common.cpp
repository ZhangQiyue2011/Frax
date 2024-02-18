#include<iostream>
#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction a(2 ,4);
    const Fraction b(3 ,4);
    cout << a.ref_value()/*refresh and return value*//*return double*/ << endl;
    cout << b.const_ref_value()/*return const double*/ << endl;
    cout << a.ret_num() << "/" << a.ret_deno() << endl;
    cout << b.const_ret_num()/*return const unsigned int*/ << "/" << a.const_ret_deno()/*return const unsigned int*/ << endl;
    
    cout << endl;
    a.app_sc();//Approximate score
    cout << a.ret_num() << "/" << a.ret_deno() << endl;
    a.univ_sc(2);//Universal score
    cout << a.ret_num() << "/" << a.ret_deno() << endl;

    cout << endl << "reciprocal" << endl;
    cout << a << endl;
    a.reciprocal();//reciprocal
    cout << a << endl;

    Fraction c(4, 5);
    Fraction d(7, 9);
    redu_frac_com_deno(&c, &d);
    cout << c.ret_num() << "/" << c.ret_deno() << endl;
    cout << d.ret_num() << "/" << d.ret_deno() << endl;

    Fraction e(1, 2, false);
    const Fraction f(1, 2, false);
    cout << e.ret_pos() << endl;
    cout << e.ret_pos() << endl;
    
    return 0;
}
