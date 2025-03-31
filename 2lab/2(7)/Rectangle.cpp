#include "Rectangle.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;
Rectangle::Rectangle() {
    x1 = y1 = x2 = y2 = 0;
}

Rectangle::Rectangle(int _x1, int _y1, int _x2, int _y2) {
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
}

Rectangle::~Rectangle() {
    scout << "Объект Rectangle уничтожен." << endl;
}

int Rectangle::getArea() {
    return abs((x2 - x1) * (y2 - y1));
}

string Rectangle::getInfo() {
    stringstream ss;
    ss << "Прямоугольник: (" << x1 << ", " << y1 << ") -> (" << x2 << ", " << y2 << ")";
    ss << "\nПлощадь: " << getArea() << " пикселей";
    return ss.str();
}
