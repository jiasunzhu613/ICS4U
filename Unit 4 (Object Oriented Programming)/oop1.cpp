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

class Animal {
public:
    string name;
    int age;
    float speed;
    string getName();
    int getAge();
    float getSpeed();
    float getDisplacement(float time);
    float getTimeToDisplace(float displacement);
};

float Animal::getDisplacement(float time){
    return speed * time;
}

float Animal::getTimeToDisplace(float displacement){
    return displacement / speed;
}

string Animal::getName(){
    return name;
}

int Animal::getAge(){
    return age;
}

float Animal::getSpeed(){
    return speed;
}

int main(){
    Animal dog, cat;
    cout << "Enter a name for a dog: " << endl;
    cin >> dog.name;
    cout << "Enter an age for a dog: " << endl;
    cin >> dog.age;
    cout << "Enter a speed for a dog in meters per second: " << endl;
    cin >> dog.speed;
    cout << "Enter a name for a cat: " << endl;
    cin >> cat.name;
    cout << "Enter an age for a cat: " << endl;
    cin >> cat.age;
    cout << "Enter a speed for a cat in meters per second: " << endl;
    cin >> cat.speed;

    cout << "Your dog's name is " << dog.getName() << " and he/she is " << dog.getAge() << " years olds. "
    << dog.getName() << " has a speed of " << dog.getSpeed() << " meters per second" << endl << endl;

    cout << "Your cat's name is " << cat.getName() << " and he/she is " << cat.getAge() << " years olds. "
         << cat.getName() << " has a speed of " << cat.getSpeed() << " meters per second" << endl << endl;

    float dist, time;
    cout << "Enter how much your dog has been displaced: " << endl;
    cin >> dist;
    cout << "It took " << dog.getName() << " " << dog.getTimeToDisplace(dist) << " seconds to be displaced "
                                                                                 "that much." << endl;

    cout << "Enter how much time your dog has been running: " << endl;
    cin >> time;
    cout << dog.getName() << " was displaced by " << dog.getDisplacement(time) << " meters." << endl;

    cout << "Enter how much your cat has been displaced: " << endl;
    cin >> dist;
    cout << "It took " << cat.getName() << " " << cat.getTimeToDisplace(dist) << " seconds to be displaced "
                                                                                 "that much." << endl;
    cout << "Enter how much time your cat has been running: " << endl;
    cin >> time;
    cout << cat.getName() << " was displaced by " << cat.getDisplacement(time) << " meters." << endl;
    return 0;
}