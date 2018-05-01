#include <gtest/gtest.h>
#include "../../Rational.h"

TEST(Rational, constructor) {
    EXPECT_THROW(Rational(0, 0), DivideByZeroException);
    EXPECT_THROW(Rational(5, 0), DivideByZeroException);

    EXPECT_NO_THROW(Rational(5, 1));
    EXPECT_NO_THROW(Rational(0, 1));
}

TEST(Rational, getNomAndDen) {
    Rational a{10, 7};

    EXPECT_EQ(10, a.getNumerator());
    EXPECT_EQ(7, a.getDenominator());
}

TEST(Rational, setNomAndDen) {
    Rational a{10, 7};
    a.set(-1, 9);

    EXPECT_EQ(-1, a.getNumerator());
    EXPECT_EQ(9, a.getDenominator());
}

TEST(Rational, simplifying) {
    // while creating
    Rational a{5, -5};

    EXPECT_EQ(1, a.getDenominator());
    EXPECT_EQ(-1, a.getNumerator());

    // while changing(setting)
    a.set(10, 4);

    EXPECT_EQ(5, a.getNumerator());
    EXPECT_EQ(2, a.getDenominator());
}

TEST(Rational, additionValue) {
    Rational a{1, 3};

    int b = 10;

    a += b;

    EXPECT_EQ(31, a.getNumerator());
    EXPECT_EQ(3, a.getDenominator());
}

TEST(Rational, additionRational) {
    Rational a{1, 3};
    Rational b{2, 3};

    a += b;

    EXPECT_EQ(1, a.getNumerator());
    EXPECT_EQ(1, a.getDenominator());
}

TEST(Rational, subtractionValue) {
    Rational a{1, 3};

    int b = 1;

    a -= b;

    EXPECT_EQ(-2, a.getNumerator());
    EXPECT_EQ(3, a.getDenominator());
}

TEST(Rational, subtractionRational) {
    Rational a{4, 5};
    Rational b{1, 5};

    a -= b;

    EXPECT_EQ(3, a.getNumerator());
    EXPECT_EQ(5, a.getDenominator());
}

TEST(Rational, multiplicationValue) {
    Rational a{1, 7};

    int b = 20;

    a *= b;

    EXPECT_EQ(20, a.getNumerator());
    EXPECT_EQ(7, a.getDenominator());
}

TEST(Rational, multiplicationRational) {
    Rational a{1, 7};
    Rational b{7, 9};

    a *= b;

    EXPECT_EQ(1, a.getNumerator());
    EXPECT_EQ(9, a.getDenominator());
}

TEST(Rational, divisionValue) {
    Rational a{2, 7};
    int b = 4;

    a /= b;

    EXPECT_EQ(1, a.getNumerator());
    EXPECT_EQ(14, a.getDenominator());
}

TEST(Rational, divisionRational) {
    Rational a{1, 4};
    Rational b{1, 8};

    a /= b;

    EXPECT_EQ(2, a.getNumerator());
    EXPECT_EQ(1, a.getDenominator());
}

TEST(Rational, operatorMinus) {
    Rational a{1, 4};

    EXPECT_EQ(-1, (-a).getNumerator());
    EXPECT_EQ(4, (-a).getDenominator());

    Rational b{-10, 7};

    EXPECT_EQ(10, (-b).getNumerator());
    EXPECT_EQ(7, (-b).getDenominator());
}

TEST(Rational, operatorPlus) {
    Rational a{1, 4};

    EXPECT_EQ(1, (+a).getNumerator());
    EXPECT_EQ(4, (+a).getDenominator());

    Rational b{-10, 7};

    EXPECT_EQ(-10, (+b).getNumerator());
    EXPECT_EQ(7, (+b).getDenominator());
}

TEST(Rational, toPower) {
    Rational a{1, 4};
    auto res = a.pow(3);

    EXPECT_EQ(1, res.getNumerator());
    EXPECT_EQ(64, res.getDenominator());

    Rational b{-1, 3};
    auto res1 = b.pow(4);

    EXPECT_EQ(1, res1.getNumerator());
    EXPECT_EQ(81, res1.getDenominator());
}

TEST(Rational, invert) {
    Rational a{1, 4};

    auto res = a.invert();

    EXPECT_EQ(4, res.getNumerator());
    EXPECT_EQ(1, res.getDenominator());

    Rational b{-1, 1000000};
    auto res1 = b.invert();

    EXPECT_EQ(-1000000, res1.getNumerator());
    EXPECT_EQ(1, res1.getDenominator());
}

TEST(Rational, castToDouble) {
    Rational a{1, 4};

    double res = a.to_double();

    EXPECT_TRUE(abs(res - ((double) 1 / 4) < 0.00001));
}

TEST(Rational, castToFloat) {
    Rational a{1, 4};

    double res = a.to_float();

    EXPECT_TRUE(abs(res - ((float) 1 / 4) < 0.0001));
}