#include <iostream>
#include <cstdio>
#include <ratio>
#include "Rational.h"

using std::cout;
using std::endl;


int main() {
    Rational f{100, 110};
    Rational s{1, 4};

    f += s;

    cout << f.getNumerator() << endl;
    cout << f.getDenominator() << endl;

    f.set(5, 1);

    return 0;
}