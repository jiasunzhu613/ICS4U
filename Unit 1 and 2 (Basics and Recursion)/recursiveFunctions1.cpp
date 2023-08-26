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

int generateA(int timesLeft){
    if (timesLeft == 1){
        return 3;
    }
    return generateA(timesLeft - 1) - 2;
}

int generateB(int timesLeft){
    if (timesLeft == 1){
        return -1;
    }
    return generateB(timesLeft - 1) * 2;
}
int main(){
    int timesleft;
    cin >> timesleft;
    int A = generateA(timesleft);
    int B = generateB(timesleft);
    cout << A << endl << B << endl;
    return 0;
}