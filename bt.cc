#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction a(1, 2);
    Fraction b(1, 2, false);
    cout << a.ref_value();
}