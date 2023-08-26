#include <iostream>
#include "Fraction.h"

int main() {
    int numerator, denominator;

    // Get input for overloaded constructor
    cout << "Please enter the numerator of the fraction:" << endl;
    cin >> numerator;

    cout << "Please enter the denominator of the fraction:" << endl;
    cin >> denominator;

    while (denominator == 0){
        cout << "Please enter a non-zero value for the value of the denominator:" << endl;
        cin >> denominator;
    }

    //Initialize fraction instances
    Fraction fraction; //calling default constructor on stack.

    Fraction fraction2(numerator, denominator); //calling overloaded constructor on stack.

    Fraction* fraction3 = new Fraction(9, 13); //calling overloaded contructor on heap.

    //Get info about each fraction using to string function and value function
    cout << "Fraction 1 Info: " << endl;
    cout << fraction.toString() << endl << endl;

    cout << "Fraction 2 Info: " << endl;
    cout << fraction2.toString() << endl << endl;

    cout << "Fraction 3 Info: " << endl;
    cout << fraction3->toString() << endl << endl;

    cout << "Changing properties using set method..." << endl;
    cout << "Please enter the new numerator of the fraction:" << endl;
    cin >> numerator;

    cout << "Please enter the new denominator of the fraction:" << endl;
    cin >> denominator;

    while (denominator == 0){
        cout << "Please enter a non-zero value for the value of the new denominator:" << endl;
        cin >> denominator;
    }

    fraction2.setNumerator(numerator);
    fraction2.setDenominator(denominator);

    cout << "Fraction 2 New Info: " << endl;
    cout << fraction2.toString() << endl << endl;


    cout << "Testing static add, subtract, multiply, and divide methods" << endl;
    cout << "Creating a new fraction by adding fraction1 and fraction2 together" << endl;
    Fraction fraction4 = Fraction::add(fraction, fraction2);
    cout << "Created fraction information: " << endl;
    cout << fraction4.toString() << endl << endl;

    cout << "Creating a new fraction by subtracting fraction2 from fraction1 " << endl;
    Fraction fraction5 = Fraction::subtract(fraction, fraction2);
    cout << "Created fraction information: " << endl;

    cout << fraction5.toString() << endl << endl;

    cout << "Creating a new fraction by multiplying fraction1 and fraction2" << endl;
    Fraction fraction6 = Fraction::multiply(fraction, fraction2);
    cout << "Created fraction information: " << endl;

    cout << fraction6.toString() << endl << endl;

    cout << "Creating a new fraction by dividing fraction2 from fraction1" << endl;
    Fraction fraction7 = Fraction::divide(fraction, fraction2);
    cout << "Created fraction information: " << endl;

    cout << fraction7.toString() << endl << endl;

    cout << "Testing void add, subtract, multiply, and divide methods" << endl;
    cout << "Adding fraction2 to fraction1" << endl;
    fraction.add(fraction2);
    cout << "Fraction information: " << endl;
    cout << fraction.toString() << endl << endl;

    cout << "Subtracting 2/3 from the new fraction1" << endl;
    Fraction f(2, 3);
    fraction.subtract(f);
    cout << "Fraction information: " << endl;
    cout << fraction.toString() << endl << endl;

    cout << "Multiplying the new fraction1 by 4/3" << endl;
    Fraction f1(4, 3);
    fraction.multiply(f1);
    cout << "Fraction information: " << endl;
    cout << fraction.toString() << endl << endl;

    cout << "Dividing the new fraction1 by 1/2" << endl;
    Fraction f2(1, 2);
    fraction.divide(f2);
    cout << "Fraction information: " << endl;
    cout << fraction.toString() << endl << endl;

    cout << "# of fraction created in this program: " << Fraction::printCount() << endl;
    return 0;
}
