//
// Created by Jonathan Zhu on 2023-03-08.
//
#include <ostream>
#include <iostream>

using namespace std;

class testClass{
private:
    int* arr;
    int size;

public:
    testClass(int* arr, int size){
      this->arr = arr;
      this->size = size;
    };

    friend ostream& operator <<(ostream&, testClass&);
    void getElementsFromUser();
};

ostream& operator <<(ostream& output, testClass& testclass){
    for (int i = 0; i < testclass.size; i++){
        output << testclass.arr[i] << " ";
    }
    return output << endl;
};

void testClass::getElementsFromUser() {
    for (int i = 0; i < size; i++){
        int x;
        cin >> x;
        arr[i] = x;
    }
}

int main(){
    int* random = new int[9]{0, 1, 2, 3, 4 ,5, 6, 7, 8};
    int size = 9;
    testClass testclass{random, size};
    cout << testclass;
    testclass.getElementsFromUser();
    cout << testclass;
    return 0;
}