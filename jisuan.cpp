#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction a(4, Fraction(1, 5), false);
    Fraction b(2, Fraction(1, 4));
    Fraction c(a + b);
    cout << c << endl;
    return 0;
}
