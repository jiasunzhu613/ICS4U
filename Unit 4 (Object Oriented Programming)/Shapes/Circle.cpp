//
// Created by Jonathan Zhu on 2023-03-24.
//

#include "Circle.h"

Circle::Circle() : Shape(){
    radius = 1.0;
}

Circle::Circle(string name, double radius) : Shape(name) {
    this->radius = radius;
}

void Circle::setRadius(double radius) {
    this->radius = radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

double Circle::getPerimeter() const {
    return 2 * M_PI * radius;
}

string Circle::getShape() const {
    return "Circle";
}


