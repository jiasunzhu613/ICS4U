//
// Created by Jonathan Zhu on 2023-02-05.
//

#include "Fraction.h"

int Fraction::numberOfFractions = 0;

Fraction::Fraction() {
    numerator = 1;
    denominator = 1;
    numberOfFractions++;
}

Fraction::Fraction(int n, int d) {
    setNumerator(n);
    setDenominator(d);
    numberOfFractions++;

}

Fraction::Fraction(const Fraction &other) {
    setNumerator(other.numerator);
    setDenominator(other.denominator);
    numberOfFractions++;
}

Fraction& Fraction::operator=(const Fraction &other){
    // check if objects are the same
    if (this != &other) {
        setNumerator(other.numerator);
        setDenominator(other.denominator);
    }
    return *this;
}

Fraction::~Fraction() {

}

void Fraction::setNumerator(int n) {
    numerator = n;
}

void Fraction::setDenominator(int d) {
    denominator = d;
}

int Fraction::getNumerator() {
    return numerator;
}

int Fraction::getDenominator() {
    return denominator;
}

double Fraction::value() {
    return (double) numerator / denominator;
}

string Fraction::toString() {
    stringstream ss;
    ss << "Numerator: " << numerator << endl;
    ss << "Denominator: " << denominator << endl;
    ss << "Value of fraction: " << setprecision(5) << fixed << value();
    return ss.str();
}

int Fraction::gcd(int x, int y){
    if (y == 0){
        return x;
    }
    return gcd(y, x % y);
}

void Fraction::add(Fraction &other){
    //if denominators are the same simply add numerators
    if (denominator == other.denominator){
        numerator += other.numerator;
    }else{ //if they arent, we multiply using opposing base
        numerator = (numerator * other.denominator) + (other.numerator * denominator);
        denominator *= other.denominator;
    }

    //reduce fraction
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

void Fraction::subtract(Fraction &other){
//if denominators are the same simply subtract numerators
    if (denominator == other.denominator){
        numerator -= other.numerator;
    }else{ //if they arent, we multiply using opposing base
        numerator = (numerator * other.denominator) - (other.numerator * denominator);
        denominator *= other.denominator;
    }

    //reduce fraction
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

void Fraction::multiply(Fraction &other){
    numerator *= other.numerator;
    denominator *= other.denominator;

    //reduce fraction
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

void Fraction::divide(Fraction &other){
    numerator *= other.denominator;
    denominator *= other.numerator;

    //reduce fraction
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

Fraction Fraction::add(Fraction &f, Fraction &g){
    Fraction h;
    if (f.denominator == g.denominator){
        h.numerator= f.numerator + g.numerator;
        h.denominator = f.denominator;
    }else{
        h.numerator= f.numerator * g.denominator + g.numerator * f.denominator;
        h.denominator = f.denominator * g.denominator;
    }

    //reduce fraction
    int divisor = gcd(h.numerator, h.denominator);
    h.numerator /= divisor;
    h.denominator /= divisor;
    return h;
}

Fraction Fraction::subtract(Fraction &f, Fraction &g){
    Fraction h;
    if (f.denominator == g.denominator){
        h.numerator= f.numerator - g.numerator;
        h.denominator = f.denominator;
    }else{
        h.numerator= f.numerator * g.denominator - g.numerator * f.denominator;
        h.denominator = f.denominator * g.denominator;
    }

    //reduce fraction
    int divisor = gcd(h.numerator, h.denominator);
    h.numerator /= divisor;
    h.denominator /= divisor;
    return h;
}

Fraction Fraction::multiply(Fraction &f, Fraction &g){
    Fraction h;
    h.numerator = f.numerator * g.numerator;
    h.denominator = f.denominator * g.denominator;

    //reduce fraction
    int divisor = gcd(h.numerator, h.denominator);
    h.numerator /= divisor;
    h.denominator /= divisor;
    return h;
}

Fraction Fraction::divide(Fraction &f, Fraction &g){
    Fraction h;
    h.numerator = f.numerator * g.denominator;
    h.denominator = f.denominator * g.numerator;

    //reduce fraction
    int divisor = gcd(h.numerator, h.denominator);
    h.numerator /= divisor;
    h.denominator /= divisor;
    return h;
}

int Fraction::printCount(){
    return numberOfFractions;
}

