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
//
////Q1
//void cubeByPointer(int * number){
//    *number = pow(*number, 3);
//}
//
////Q2
//void sumTwoInt(int * value, int * add_on){
//    *value += *add_on;
//}
//
////Q3
//void calcCircleStuff(double * radius, double * area, double * circum){
//    //Calc area
//    *area = M_PI * pow(*radius, 2);
//
//    //Calc circum
//    *circum = 2 * M_PI * *radius;
//}
//
////Q4
//bool quadEquation(double a, double b, double c, string * sol1, string * sol2){
//    //Calculate number of sols
//    double discrim = pow(b, 2) - (4 * a * c);
//
//    if (discrim == 0){
//        *sol1 = to_string((b * -1) / (2 * a));
//        return true;
//    }else if (discrim > 0){
//        *sol1 = to_string(((b * -1) + sqrt(discrim)) / (2 * a));
//        *sol2 = to_string(((b * -1) - sqrt(discrim)) / (2 * a));
//        return true;
//    }
//
//    return false;
//}
void modifyArray(int b[], int arr_size){
    for (int i = 0; i < arr_size; i++){
        b[i] *= 2;
    }
}

void modifyElement(int a)
{
    a *= 2;
}

void q3()
{
    int element[5];
    for (int index = 0; index <= 4; index++)
        element[index] = index;
    cout << "Effects of passing entire array call by reference\n\n";
    cout << "Value of the original array is \n";
    for (int x = 0; x <= 4; x++)
        cout << element[x] << " ";
    cout << endl;
    modifyArray(element, 5);
    cout << endl << endl;
    cout << "Effects of passing array element call-by-value\n\n";
    cout << "The value of element[3] is " << element[3] << endl;
    modifyElement(element[3]);
    cout << "The value of element[3] is " << element[3] << endl;
}

int main() {
    q3();
//    //Q1
//    int number = 2;
//    int * pnumber = &number;
//    cubeByPointer(pnumber);
//    cout << *pnumber << endl;
//
//    //Q2
//    int value1 = 10, value2 = 5;
//    int * pvalue1 = &value1, * pvalue2 = &value1;
//    sumTwoInt(pvalue1, pvalue2);
//    cout << *pvalue1 << endl;
//
//    //Q3
//    double radius = 5, area = 0, circum = 0;
//    double * pradius = &radius, * parea = &area, * pcircum = &circum;
//    calcCircleStuff(pradius, parea, pcircum);
//    cout << *parea << endl;
//    cout << *pcircum << endl;
//
//    //Q4
//    double a = 1, b = 2, c = -3;
//    string sol1 = "No answer", sol2 = "No answer";
//    string * psol1 = &sol1, * psol2 = &sol2;
//    bool hasAnswers = quadEquation(a, b, c, psol1, psol2);
//    cout << hasAnswers << endl;
//    cout << *psol1 << endl;
//    cout << *psol2 << endl;

    return 0;
}
