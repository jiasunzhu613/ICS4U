//
// Created by Jonathan Zhu on 2023-03-24.
//

#include "Triangle.h"

Triangle::Triangle() : Shape(){
    base = 1.0;
    height = 1.0;
}

Triangle::Triangle(string name, double base, double height) : Shape(name){
    this->base = base;
    this->height = height;
}

void Triangle::setBase(double base) {
    this->base = base;
}

void Triangle::setHeight(double height) {
    this->height = height;
}

double Triangle::getBase() const {
    return base;
}

double Triangle::getHeight() const {
    return height;
}

double Triangle::getArea() const {
    return 0.5 * base * height;
}

double Triangle::getPerimeter() const {
    double opposingSides = sqrt(pow(base/2, 2) + pow(height, 2));
    return base + 2 * opposingSides;
}

string Triangle::getShape() const {
    return "Triangle";
}

