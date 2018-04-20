#include "Rational.h"

const Rational &Rational::set(intmax_t num, intmax_t den) {
    if(den != 0){
        numerator = num;
        denominator = den;

        simplify();
    }

    throw DivideByZeroException();
}

void Rational::simplify() {

}
