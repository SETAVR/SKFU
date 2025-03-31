
#include <iostream>
#include "Rectangle.h"
using namespace std;
int main() {
    int x1, y1, x2, y2;

    cout << "Введите x1, y1, x2, y2 через пробел: ";
    cin >> x1 >> y1 >> x2 >> y2;

    Rectangle rect(x1, y1, x2, y2);

    cout << rect.getInfo() << endl;

    return 0;
}
