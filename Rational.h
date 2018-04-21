#ifndef RATIONALNUMBER_RATIONAL_H
#define RATIONALNUMBER_RATIONAL_H

#include <exception>
#include <stdexcept>
#include <stdint-gcc.h>

using std::runtime_error;
using std::string;

class DivideByZeroException : public std::runtime_error {
public:
    DivideByZeroException() : runtime_error("Division by zero(0) happened!") {}

    virtual const char *what() const throw() {
        return runtime_error::what();
    }
};

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
    Rational &set(intmax_t num, intmax_t den);

    // operators
    Rational &operator+=(const Rational &right);

    Rational &operator+=(int right);

    Rational &operator-=(const Rational &right);

    Rational &operator-=(int right);

    Rational &operator*=(const Rational &right);

    Rational &operator*=(int right);

    Rational &operator/=(const Rational &right);

    Rational &operator/=(int right);

    Rational operator-() const;

    // invert numerator and denominator
    Rational invert() const;

    inline Rational operator+() const {
        return *this;
    }

    // Casting
    inline double to_double() const {
        return static_cast<double>(numerator) / denominator;
    }

    inline double to_float() const {
        return static_cast<float>(numerator) / denominator;
    }
};

inline Rational operator+(Rational lhs, const Rational &rhs) {
    return lhs += rhs;
}

inline Rational operator+(Rational lhs, int rhs) {
    return lhs += rhs;
}

inline Rational operator+(int lhs, Rational rhs) {
    return rhs += lhs;
}

inline Rational operator*(Rational lhs, const Rational &rhs) {
    return lhs *= rhs;
}

inline Rational operator*(Rational lhs, int rhs) {
    return lhs *= rhs;
}

inline Rational operator*(int lhs, Rational rhs) {
    return rhs *= lhs;
}

inline Rational operator-(Rational lhs, const Rational &rhs) {
    return lhs -= rhs;
}

inline Rational operator-(Rational lhs, int rhs) {
    return lhs -= rhs;
}

inline Rational operator-(int lhs, Rational rhs) {
    return (-rhs) += lhs;
}

inline Rational operator/(Rational lhs, const Rational &rhs) {
    return lhs /= rhs;
}

inline Rational operator/(Rational lhs, int rhs) {
    return lhs /= rhs;
}

inline Rational operator/(int lhs, Rational rhs) {
    return rhs.invert() * lhs;
}

#endif