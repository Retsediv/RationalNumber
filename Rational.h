#ifndef RATIONALNUMBER_RATIONAL_H
#define RATIONALNUMBER_RATIONAL_H

#include <exception>
#include <cassert>
#include <stdexcept>
#include <stdint-gcc.h>
#include <cmath>
#include "Exceptions.h"

using std::abs;
using std::string;

uintmax_t gcd(uintmax_t a, uintmax_t b);

class Rational {
private:
    intmax_t numerator, denominator;

    void simplify();
public:
    // Constructors
    Rational(intmax_t num, intmax_t den) : numerator(num), denominator(den) {
        if(den == 0){
            throw DivideByZeroException();
        }

        simplify();
    };

    // getters
    intmax_t getNumerator() const { return numerator; }
    intmax_t getDenominator() const { return denominator; }

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

    inline Rational operator+() const {
        return *this;
    }

    Rational pow(size_t p);

    // invert numerator and denominator
    Rational invert() const;

    // Casting
    inline double to_double() const {
        return static_cast<double>(numerator) / denominator;
    }

    inline double to_float() const {
        return static_cast<float>(numerator) / denominator;
    }

    // Comparators
#define ASSERT_CHECK_IF_REDUCED(obj) assert( (obj).denominator>0 && ( (obj).numerator== 0 || gcd(abs((obj).numerator), (obj).denominator)==1 ) )
#define ASSERT_CHECK_IF_REDUCED_THIS ASSERT_CHECK_IF_REDUCED(*this);
#define ASSERT_CHECK_IF_REDUCED_BOTH do{ ASSERT_CHECK_IF_REDUCED( *this ); ASSERT_CHECK_IF_REDUCED( rhs ); } while(false);

    inline bool operator==(const Rational &rhs) const {
        ASSERT_CHECK_IF_REDUCED_BOTH
        return numerator == rhs.numerator && denominator == rhs.denominator;
    }

    inline bool operator==(int rhs) const {
        ASSERT_CHECK_IF_REDUCED_THIS
        return numerator == rhs && denominator == 1;
    }

    inline bool operator!=(const Rational &rhs) const {
        ASSERT_CHECK_IF_REDUCED_BOTH
        return numerator != rhs.numerator || denominator != rhs.denominator;
    }

    inline bool operator!=(int rhs) const {
        ASSERT_CHECK_IF_REDUCED_THIS
        return numerator != rhs || denominator != 1;
    }

    inline bool operator>(const Rational &rhs) const {
        ASSERT_CHECK_IF_REDUCED_BOTH
        return numerator * rhs.denominator > rhs.numerator * denominator;
    }

    inline bool operator>(int rhs) const {
        ASSERT_CHECK_IF_REDUCED_THIS
        return numerator > rhs * denominator;
    }

    inline bool operator<(const Rational &rhs) const {
        ASSERT_CHECK_IF_REDUCED_BOTH
        return numerator * rhs.denominator < rhs.numerator * denominator;
    }

    inline bool operator<(int rhs) const {
        ASSERT_CHECK_IF_REDUCED_THIS
        return numerator < rhs * denominator;
    }

    inline bool operator>=(const Rational &rhs) const {
        ASSERT_CHECK_IF_REDUCED_BOTH
        return numerator * rhs.denominator >= rhs.numerator * denominator;
    }

    inline bool operator>=(int rhs) const {
        ASSERT_CHECK_IF_REDUCED_THIS
        return numerator >= rhs * denominator;
    }

    inline bool operator<=(const Rational &rhs) const {
        ASSERT_CHECK_IF_REDUCED_BOTH
        return numerator * rhs.denominator <= rhs.numerator * denominator;
    }

    inline bool operator<=(int rhs) const {
        ASSERT_CHECK_IF_REDUCED_THIS
        return numerator <= rhs * denominator;
    }


#undef ASSERT_CHECK_IF_REDUCED_BOTH
#undef ASSERT_CHECK_IF_REDUCED_THIS
#undef ASSERT_CHECK_IF_REDUCED

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

inline Rational operator-(int lhs, const Rational &rhs) {
    return (-rhs) += lhs;
}

inline Rational operator/(Rational lhs, const Rational &rhs) {
    return lhs /= rhs;
}

inline Rational operator/(Rational lhs, int rhs) {
    return lhs /= rhs;
}

inline Rational operator/(int lhs, const Rational &rhs) {
    return rhs.invert() * lhs;
}

#endif