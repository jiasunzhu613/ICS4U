//
// Created by Jonathan Zhu on 2023-03-24.
//

#include <iostream>
#include <string>
#include "Shapes/Shape.h"

using namespace std;


#ifndef SHAPES_TRIANGLE_H
#define SHAPES_TRIANGLE_H


class Triangle : public Shape{
private:
    double base, height;
public:
    Triangle();
    Triangle(string, double, double);
    void setBase(double);
    void setHeight(double);
    double getBase() const;
    double getHeight() const;
    virtual double getArea() const;
    virtual double getPerimeter() const;
    virtual string getShape() const;
};


#endif //SHAPES_TRIANGLE_H
