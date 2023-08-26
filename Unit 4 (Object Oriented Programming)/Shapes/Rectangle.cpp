//
// Created by Jonathan Zhu on 2023-03-24.
//

#include "Rectangle.h"

Rectangle::Rectangle() : Shape(){
    length = 1.0;
    width = 1.0;
}

Rectangle::Rectangle(string name, double length, double width) : Shape(name){
    this->length = length;
    this->width = width;
}

void Rectangle::setLength(double length) {
    this->length = length;
}

void Rectangle::setWidth(double width) {
    this->width = width;
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getArea() const {
    return length * width;
}

double Rectangle::getPerimeter() const {
    return 2 * (length + width);
}

string Rectangle::getShape() const {
    return "Rectangle";
}