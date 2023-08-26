//Author: Jonathan Zhu
//Date: November 24, 2022

#include <string>
#include <algorithm>

using namespace std;

// Q1
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

//Q2
int gcd(int x, int y){
    if (y == 0){
        return x;
    }
    return gcd(y, x % y);
}

//Q3
string reverse(string s, int ind){
    if (ind == -1)
        return "";

    return s[ind] + reverse(s, ind - 1);
}

bool isPalindrome(string s, string s1, int ind, int length){
    if (ind == length){
        return true;
    }
    return s[ind] == s1[ind] and isPalindrome(s, s1, ind + 1, length);
}

//Q4
string decimalToBinary(long num){
    if (num == 0)
        return "";
    return decimalToBinary(num / 2) + to_string(num % 2);
}

//Q5
double average(int arr[], int ind){
    if (ind == 0)
        return arr[0];
    return average(arr, ind - 1) + (1.0/ind)*(arr[ind - 1] - average(arr, ind - 1));
}

//Q6
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
    //Q1
//    int timesleft;
//    cin >> timesleft;
//    int A = generateA(timesleft);
//    int B = generateB(timesleft);
//    cout << A << endl << B << endl;


    // Q2
//    int x, y;
//    cin >> x >> y;
//    cout << gcd(x, y) << endl;


    // Q3
//    //Reversed
//    string s;
//    getline(cin, s);
//    int length = s.length();
//    string reversed = reverse(s, length - 1);
//    cout << reversed << endl;
//
//    //IsPalindrome
//    string s1 = "";
//    for (int i = 0; i < length; i++){
//        if (reversed[i] == ' '){
//            continue;
//        }else{
//            s1 += tolower(reversed[i]);
//        }
//    }
//
//    string s_filtered = "";
//    for (int i = 0; i < length; i++){
//        if (s[i] == ' '){
//            continue;
//        }else{
//            s_filtered += tolower(s[i]);
//        }
//    }
//    int newLength = s1.length();
//    bool isPalin = isPalindrome(s_filtered, s1, 0,  newLength - 1);
//    if (isPalin)
//        cout << "true" << endl;
//    else
//        cout << "false" << endl;

    // Q4
//    int num;
//    cin >> num;
//    if (num == 0)
//        cout << 0 << endl;
//    else
//        cout << decimalToBinary(num) << endl;

    // Q5
//    int length;
//    int * arr;
//    cin >> length;
//    arr = new int[length];
//    for (int i = 0; i < length; i++){
//        cin >> arr[i];
//    }
//    printf("%.1f", average(arr, length));

    // Q6
//    int N;
//    cin >> N;
//    cout << FindReinventedFactorial(N) << endl;



    return 0;
}