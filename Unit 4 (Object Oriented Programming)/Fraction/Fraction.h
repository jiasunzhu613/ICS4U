//
// Created by Jonathan Zhu on 2023-02-05.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

#ifndef FRACTION_FRACTION_H
#define FRACTION_FRACTION_H


class Fraction {
private:
    //From Fundamental Exercises
    int numerator;
    int denominator;
    //From Advanced Exercises
    static int numberOfFractions;

public:
    //From Fundamental Exercises
    Fraction();
    Fraction(int, int);
    Fraction(const Fraction&);
    Fraction& operator =(const Fraction&);
    ~Fraction();
    void setNumerator(int);
    void setDenominator(int);
    int getNumerator();
    int getDenominator();
    double value();
    string toString();
    //From Advanced Exercises
    static int gcd(int, int);
    void add(Fraction&);
    void subtract(Fraction&);
    void multiply(Fraction&);
    void divide(Fraction&);
    static Fraction add(Fraction&, Fraction&);
    static Fraction subtract(Fraction&, Fraction&);
    static Fraction multiply(Fraction&, Fraction&);
    static Fraction divide(Fraction&, Fraction&);
    static int printCount();
};


#endif //FRACTION_FRACTION_H
