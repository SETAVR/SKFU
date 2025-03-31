#include "TimeConverter.h"
#include <sstream>

TimeConverter::TimeConverter(int h, int m) {
    hours = h;
    minutes = m;
}

string TimeConverter::getInfo() {
    stringstream ss;
    ss << "Часы: " << hours << ", Минуты: " << minutes;
    return ss.str();
}

int TimeConverter::Minutes() {
    return (hours * 60) + minutes;
}
