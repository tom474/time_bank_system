#include "./Converter.h"

#include <iostream>
#include <sstream>

using std::string;

int Converter::stringToInteger(string stringVal) {
    std::stringstream sstr;
    int intNum;
    sstr << stringVal;
    sstr >> intNum;
    return intNum;
}

double Converter::stringToDouble(string stringVal) {
    std::stringstream sstr;
    double doubleNum;
    sstr << stringVal;
    sstr >> doubleNum;
    return doubleNum;
}

string Converter::boolToString(bool boolVal) {
    return boolVal ? "true" : "false";
}