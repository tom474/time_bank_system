#include "./Converter.h"

#include <iostream>
#include <sstream>

using std::string;

int stringToInteger(string str) {
    std::stringstream sstr;
    int intNum;
    sstr << str;
    sstr >> intNum;
    return intNum;
}

double stringToDouble(string str) {
    std::stringstream sstr;
    double doubleNum;
    sstr << str;
    sstr >> doubleNum;
    return doubleNum;
}