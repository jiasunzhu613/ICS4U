//
// Created by Jonathan Zhu on 2023-03-24.
//

#include <iostream>
#include <string>
#include "Shape.h"

using namespace std;


#ifndef SHAPES_RECTANGLE_H
#define SHAPES_RECTANGLE_H


class Rectangle : public Shape{
private:
    double length, width;
public:
    Rectangle();
    Rectangle(string, double, double);
    void setLength(double);
    void setWidth(double);
    double getLength() const;
    double getWidth() const;
    virtual double getArea() const;
    virtual double getPerimeter() const;
    virtual string getShape() const;
};


#endif //SHAPES_RECTANGLE_H
