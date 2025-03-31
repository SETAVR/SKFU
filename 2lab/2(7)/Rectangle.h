#ifndef RECTANGLE_H
#define RECTANGLE_H
using namespace std;
#include <string>

class Rectangle {
private:
    int x1, y1, x2, y2;

public:
    Rectangle();
    Rectangle(int _x1, int _y1, int _x2, int _y2);
    ~Rectangle();
    
    int getArea();
    string getInfo();
};

#endif // RECTANGLE_H
