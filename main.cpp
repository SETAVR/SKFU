#include <iostream>
#include "TimeConverter.h"

int main() {
    int hours, minutes;

    std::cout << "Введите количество часов: ";
    std::cin >> hours;
    std::cout << "Введите количество минут: ";
    std::cin >> minutes;

    TimeConverter timeee(hours, minutes);

    std::cout << timeee.getInfo() << std::endl;
    std::cout << "Общее количество минут: " << timeee.Minutes() << std::endl;

    return 0;
}
