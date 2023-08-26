#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "../Triangle.h"

using namespace std;
int main() {
    //Test Circle Class
    cout << "TESTING CIRCLE CLASS:" << endl;
    string name1{};
    double radius{};
    cout << "PLEASE ENTER A NAME FOR THE CIRCLE BEING CREATED: " << endl;
    cin >> name1;
    cout << "PLEASE THE RADIUS OF THE CIRCLE BEING CREATED: " << endl;
    cin >> radius;
    Circle c{name1, radius};

    cout << "INFORMATION ABOUT THE OBJECT: " << endl;
    cout << "Circle's name: " << c.getName() << endl;
    cout << "Circle's radius: " << c.getRadius() << endl;
    cout << "Circle's area: " << c.getArea() << endl;
    cout << "Circle's circumference: " << c.getPerimeter() << endl;
    cout << endl;

    //Test Rectangle Class
    cout << "TESTING RECTANGLE CLASS:" << endl;
    string name2{};
    double length{}, width{};
    cout << "PLEASE ENTER A NAME FOR THE RECTANGLE BEING CREATED: " << endl;
    cin >> name2;
    cout << "PLEASE THE LENGTH OF THE RECTANGLE BEING CREATED: " << endl;
    cin >> length;
    cout << "PLEASE THE WIDTH OF THE RECTANGLE BEING CREATED: " << endl;
    cin >> width;
    Rectangle r{name2, length, width};

    cout << "INFORMATION ABOUT THE OBJECT: " << endl;
    cout << "Rectangle's name: " << r.getName() << endl;
    cout << "Rectangle's length: " << r.getLength() << endl;
    cout << "Rectangle's width: " << r.getWidth() << endl;
    cout << "Rectangle's area: " << r.getArea() << endl;
    cout << "Rectangle's perimeter: " << r.getPerimeter() << endl;
    cout << endl;


    //Test Triangle Class
    cout << "TESTING TRIANGLE CLASS:" << endl;
    string name3{};
    double base{}, height{};
    cout << "PLEASE ENTER A NAME FOR THE TRIANGLE BEING CREATED: " << endl;
    cin >> name3;
    cout << "PLEASE THE BASE OF THE TRIANGLE BEING CREATED: " << endl;
    cin >> base;
    cout << "PLEASE THE HEIGHT OF THE TRIANGLE BEING CREATED: " << endl;
    cin >> height;
    Triangle t{name3, base, height};

    cout << "INFORMATION ABOUT THE OBJECT: " << endl;
    cout << "Triangle's name: " << t.getName() << endl;
    cout << "Triangle's base: " << t.getBase() << endl;
    cout << "Triangle's height: " << t.getHeight() << endl;
    cout << "Triangle's area: " << t.getArea() << endl;
    cout << "Triangle's perimeter: " << t.getPerimeter() << endl;
    cout << endl;

    cout << "TESTING ALL CLASSES USING POINTER ARRAY: " << endl;
    Shape* shapes[3] = {new Circle{"Circle", 5.2}, new Rectangle{"Rectangle", 6.2, 10.2},
                        new Triangle{"Triangle", 5.9, 4.2}};
    for (int i = 0; i < 3; i++){
        cout << "Shape " << i + 1 << " is a " << shapes[i]->getShape() << endl;
        cout << "Shape " << i + 1 << "'s name is " << shapes[i]->getName() << endl;
        cout << "Shape " << i + 1 << " has an area of " << shapes[i]->getArea() << endl;
        cout << "Shape " << i + 1 << " has a perimeter of " << shapes[i]->getPerimeter() << endl;
        cout << endl;
    }

    return 0;
}
