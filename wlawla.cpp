#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction a(2, 3);
    Fraction b(4u, a);
    cout << a << endl;
    cout << b << endl;
    return 0;
}
