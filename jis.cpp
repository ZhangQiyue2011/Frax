#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction a(2, 15, true);
    Fraction b(12, 15, true);
    Fraction c(b - a);
    cout << c << endl;
    return 0;
}
