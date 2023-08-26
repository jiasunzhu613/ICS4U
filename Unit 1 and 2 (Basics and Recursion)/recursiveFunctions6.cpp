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

/*
 * Find lowest common multi of all numbers
 */

long long gcd(long long x, long long y){
    if (y == 0){
        return x;
    }
    return gcd(y, x % y);
}

long long lcm(long long a, long long b){
    return (a / gcd(a, b)) * b;
}

long long FindReinventedFactorial(int N){
    if (N == 1){
        return 1;
    }
    return lcm(N, FindReinventedFactorial(N - 1));
}

int main(){
    int N;
    cin >> N;
    cout << FindReinventedFactorial(N) << endl;
    return 0;
}