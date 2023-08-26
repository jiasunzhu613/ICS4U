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

int gcd(int x, int y){
    if (y == 0){
        return x;
    }
    return gcd(y, x % y);
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;
//    cout << gcd(5, 10) << endl;
    return 0;
}