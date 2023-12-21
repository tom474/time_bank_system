#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include <iostream>

using std::string;

class Converter {
    public:
        /**
        * Convert string to integer
        * 
        * @param stringVal: string value
        * @return integer value
        */
        static int stringToInteger(string stringVal);


        /**
        * Convert string to double
        * 
        * @param stringVal: string value
        * @return double value
        */
        static double stringToDouble(string stringVal);


        /**
        * Convert boolean to string
        * 
        * @param boolVal: boolean value
        * @return string value
        */
        static string boolToString(bool boolVal);
};
#endif  // _CONVERTER_H_