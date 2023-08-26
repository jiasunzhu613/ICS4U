#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <unordered_map>
#include <sstream>
#include <unistd.h>
#include <algorithm>
#include <limits>

using namespace std;

//Q1
void cubeByPointer(int * number){
    *number = pow(*number, 3);
}

//Q2
void sumTwoInt(int * value, int * add_on){
    *value += *add_on;
}

//Q3
void calcCircleStuff(double * radius, double * area, double * circum){
    //Calc area
    *area = M_PI * pow(*radius, 2);

    //Calc circum
    *circum = 2 * M_PI * *radius;
}

//Q4
bool quadEquation(double a, double b, double c, string * sol1, string * sol2){
    //Calculate number of sols
    double discrim = pow(b, 2) - (4 * a * c);

    if (discrim == 0){
        *sol1 = to_string((b * -1) / (2 * a));
        return true;
    }else if (discrim > 0){
        *sol1 = to_string(((b * -1) + sqrt(discrim)) / (2 * a));
        *sol2 = to_string(((b * -1) - sqrt(discrim)) / (2 * a));
        return true;
    }

    return false;
}

//Q5
/*
void swap(float *p1, float *p2){
float *temp;
temp = p1;
p1 = p2;
p2 = temp;
}
-float temp needs to be an integer instead of a pointer
*/

void swap(float * p1, float * p2){
    float temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//Q6
/*
void SquareComplex(double &a, double &b) {
// Squares a complex number a + bi
a = a*a - b*b;
b = 2*a*b;
}
- the parameters need to be pointers instead of references
- the initial a value needs to be held in a temporary variable
- the calculations need to be stored in the dereferenced variable
*/
void SquareComplex(double * a, double * b) {
    // double aVal = *a;
    // double bVal =
    // Squares a complex number a + bi
    double tempA = *a;
    *a = *a * *a - *b * *b;
    *b = 2* tempA * *b;
}

int main() {
    //Q1
    int number = 2;
    int * pnumber = &number;
    cubeByPointer(pnumber);
    cout << *pnumber << endl;

    //Q2
    int value1 = 10, value2 = 5;
    int * pvalue1 = &value1, * pvalue2 = &value1;
    sumTwoInt(pvalue1, pvalue2);
    cout << *pvalue1 << endl;

    //Q3
    double radius = 5, area = 0, circum = 0;
    double * pradius = &radius, * parea = &area, * pcircum = &circum;
    calcCircleStuff(pradius, parea, pcircum);
    cout << *parea << endl;
    cout << *pcircum << endl;

    //Q4
    double a = 1, b = 2, c = -3;
    string sol1 = "No answer", sol2 = "No answer";
    string * psol1 = &sol1, * psol2 = &sol2;
    bool hasAnswers = quadEquation(a, b, c, psol1, psol2);
    cout << hasAnswers << endl;
    cout << *psol1 << endl;
    cout << *psol2 << endl;

    //Q5
    float num1 = 10, num2 = 20;
    float * pnum1 = &num1, * pnum2 = &num2;

    swap(pnum1, pnum2);
    cout << num1 << endl;
    cout << num2 << endl;

    //Q6
    double a1 = 1, b1 = 2;
    double * pa1 = &a, * pb1 = &b;

    SquareComplex(pa1, pb1);

    cout << *pa1 << endl;
    cout << *pb1 << endl;
    
    return 0;
}
