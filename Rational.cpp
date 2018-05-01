#include "Rational.h"

Rational &Rational::set(intmax_t num, intmax_t den) {
    if(den == 0){
        throw DivideByZeroException();
    }

    numerator = num;
    denominator = den;

    simplify();
}

uintmax_t gcd(intmax_t a, intmax_t b) {
    assert(a != 0 && b != 0);

    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a;
}

void Rational::simplify() {
    if(numerator == 0){
        denominator = 1;
        return;
    }

    if (denominator < 0) {
        denominator = -denominator;
        numerator = -numerator;
    }

    intmax_t common_div = numerator > 0 ? gcd(numerator, denominator) : gcd(-numerator, denominator);
    numerator /= common_div;
    denominator /= common_div;
}

Rational &Rational::operator+=(const Rational &right) {
    numerator = numerator * right.denominator + denominator * right.numerator;
    denominator *= right.denominator;
    simplify();
    return *this;
}

Rational &Rational::operator+=(int right) {
    numerator = numerator + denominator * right;
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
    numerator = numerator - denominator * right;
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

Rational Rational::pow(size_t p) {
    Rational res(*this);

    res.set(static_cast<intmax_t>(std::pow(numerator, p)), static_cast<intmax_t>(std::pow(denominator, p)));
    return res;
}