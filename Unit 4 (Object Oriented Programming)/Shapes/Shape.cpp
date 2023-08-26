//
// Created by Jonathan Zhu on 2023-03-23.
//

#include "Shape.h"

Shape::Shape(){
    name = "shape";
}

Shape::Shape(string name) {
    this->name = name;
}

void Shape::setName(string name) {
    this->name = name;
}

string Shape::getName() const {
    return name;
}


