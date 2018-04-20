#include <iostream>
#include <cstdio>
#include <ratio>
#include "Rational.h"

using std::cout;
using std::endl;


int main() {
    Rational r{1, 2};

    cout << r.getDenominator() << endl;
    cout << r.getNumerator() << endl;

    try {
        r.set(1, 0);
    } catch (DivideByZeroException& e){
        cout << e.what() << endl;
    }
    return 0;
}