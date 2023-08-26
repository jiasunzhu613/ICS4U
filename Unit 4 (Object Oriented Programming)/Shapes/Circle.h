//
// Created by Jonathan Zhu on 2023-03-24.
//

#include <iostream>
#include <string>
#include "Shape.h"

using namespace std;


#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H


class Circle : public Shape{
private:
    double radius;
public:
    Circle();
    Circle(string, double);
    void setRadius(double);
    double getRadius() const;
    virtual double getArea() const;
    virtual double getPerimeter() const;
    virtual string getShape() const;
};


#endif //SHAPES_CIRCLE_H
