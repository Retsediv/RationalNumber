#include "Rational.h"

Rational &Rational::set(intmax_t num, intmax_t den) {
    if (den != 0) {
        numerator = num;
        denominator = den;

        simplify();
    }

    throw DivideByZeroException();
}

void Rational::simplify() {

}

//Rational &operator+=(const Rational &right) {
//    return *this = Rational(
//            right.denominator * numerator + denominator * right.numerator,
//            denominator * right.denominator);
//};
//
//Rational &operator-=(const Rational &right) {
//    return *this = Rational(
//            right.denominator * numerator - denominator * right.numerator,
//            denominator * right.denominator);
//}
//
//Rational &operator*=(const Rational &right) {
//    return *this = Rational(
//            numerator * right.numerator, denominator * right.denominator);
//}
//
//Rational &operator/=(const Rational &right) {
//    return *this = Rational(
//            right.denominator * numerator, right.numerator * denominator);
//}

Rational &Rational::operator+=(const Rational &right) {
    numerator = numerator * right.denominator + denominator * right.numerator;
    denominator *= right.denominator;
    simplify();
    return *this;
}

Rational &Rational::operator+=(int right) {
    numerator = numerator + denominator*right;
    simplify();
    return *this;
}

Rational &Rational::operator-=(const Rational &right) {
    numerator = numerator * right.denominator - denominator * right.numerator;
    denominator *= right.denominator;
    simplify();
    return *this;
}

Rational &Rational::operator-=(int right) {
    numerator = numerator - denominator*right;
    simplify();
    return *this;
}

Rational &Rational::operator*=(const Rational &right) {
    numerator *= right.numerator;
    denominator *= right.denominator;
    simplify();
    return *this;
}

Rational &Rational::operator*=(int right) {
    numerator *= right;
    simplify();
    return *this;
}

Rational &Rational::operator/=(const Rational &right) {
    numerator *= right.denominator;
    denominator *= right.numerator;
    simplify();
    return *this;
}

Rational &Rational::operator/=(int right) {
    denominator *= right;
    simplify();
    return *this;
}

Rational Rational::operator-() const {
    Rational res(*this);
    res.set(-numerator, denominator);
    return res;
}

Rational Rational::invert() const {
    Rational res(*this);
    res.set(denominator, numerator);
    return res;
}
