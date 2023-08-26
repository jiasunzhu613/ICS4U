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

int main(){
    //Input
    int max;
    cin >> max;

    int is_p[1000001] = {0};
//    for (int i = 0; i < 10000; i++) {
//        cout << is_p[i] << " ";
//    }
    vector<int> primes;
    for (long long int i = 2; i <= max; i++){
        if (is_p[i] == 0){
            primes.push_back(i);
            for (long long int j = i * i; j <= max; j += i){
                is_p[j] = 1;
            }
        }
    }

    for (int i = 0; i < primes.size(); i++) {
        cout << primes.at(i) << " ";
    }

    return 0;
}