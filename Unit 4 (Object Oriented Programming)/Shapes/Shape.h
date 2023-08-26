//
// Created by Jonathan Zhu on 2023-03-23.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#ifndef SHAPES_SHAPE_H
#define SHAPES_SHAPE_H


class Shape {
protected:
    string name;
public:
    Shape();
    Shape(string);
    void setName(string);
    string getName() const;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual string getShape() const = 0;
};


#endif //SHAPES_SHAPE_H
