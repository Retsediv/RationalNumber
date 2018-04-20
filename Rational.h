#ifndef RATIONALNUMBER_RATIONAL_H
#define RATIONALNUMBER_RATIONAL_H

#include <exception>
#include <stdexcept>

using std::runtime_error;
using std::string;

class DivideByZeroException : public std::runtime_error {
public:
    DivideByZeroException() : runtime_error("Division by zero(0) happened!") {}

    virtual const char *what() const throw() {
        return runtime_error::what();
    }
};


#include <stdint-gcc.h>

class Rational {
private:
    intmax_t numerator, denominator;

    void simplify();

public:
    // Constructors
    Rational(intmax_t num, intmax_t den) : numerator(num), denominator(den) {
        simplify();
    };

    Rational(const Rational &rational) : numerator(rational.getNumerator()), denominator(rational.getDenominator()) {};

    // getters
    intmax_t getNumerator() const {
        return numerator;
    }

    intmax_t getDenominator() const {
        return denominator;
    }

    // setters
    const Rational &set(intmax_t num, intmax_t den);
};


#endif