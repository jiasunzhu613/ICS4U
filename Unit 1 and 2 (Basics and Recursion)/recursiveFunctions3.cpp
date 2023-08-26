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

int main(){
    //Reversed
    string s;
    getline(cin, s);
    int length = s.length();
    string reversed = reverse(s, length - 1);
    cout << reversed << endl;

    //IsPalindrome
    string s1 = "";
    for (int i = 0; i < length; i++){
        if (reversed[i] == ' '){
            continue;
        }else{
            s1 += tolower(reversed[i]);
        }
    }

    string s_filtered = "";
    for (int i = 0; i < length; i++){
        if (s[i] == ' '){
            continue;
        }else{
            s_filtered += tolower(s[i]);
        }
    }
    int newLength = s1.length();
    bool isPalin = isPalindrome(s_filtered, s1, 0,  newLength - 1);
    if (isPalin)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}