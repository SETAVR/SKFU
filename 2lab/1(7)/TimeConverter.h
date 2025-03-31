#ifndef TIMECONVERTER_H
#define TIMECONVERTER_H

#include <string>

class TimeConverter {
private:
    int hours;
    int minutes;

public:
    TimeConverter(int h, int m);
    std::string getInfo();
    int Minutes();
};

#endif // TIMECONVERTER_H
