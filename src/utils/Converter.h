#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include <iostream>

using std::string;

class Converter {
    public:
        static int stringToInteger(string stringVal);
        static double stringToDouble(string stringVal);
        static string boolToString(bool boolVal);
};

#endif  // _CONVERTER_H_