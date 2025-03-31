#include <iostream>
#include "TimeConverter.h"
using namespace std;

int main() {
    int hours, minutes;

    cout << "Введите количество часов: ";
    cin >> hours;
    cout << "Введите количество минут: ";
    cin >> minutes;

    TimeConverter timeee(hours, minutes);

    cout << timeee.getInfo() << endl;
    cout << "Общее количество минут: " << timeee.Minutes() << endl;

    return 0;
}
