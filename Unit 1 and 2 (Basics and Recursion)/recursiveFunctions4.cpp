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

string decimalToBinary(long num){
    if (num == 0)
        return "";
    return decimalToBinary(num / 2) + to_string(num % 2);
}

int main(){
    int num;
    cin >> num;
    if (num == 0)
        cout << 0 << endl;
    else
        cout << decimalToBinary(num) << endl;
    return 0;
}