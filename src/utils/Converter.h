#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include <iostream>

using std::string;

class Converter
{
public:
        /**
         * Convert a string into an integer
         *
         * @param stringVal: string value
         * @return integer value
         */
        static int stringToInteger(string stringVal);

        /**
         * Convert a string into an double
         *
         * @param stringVal: string value
         * @return double value
         */
        static double stringToDouble(string stringVal);

        /**
         * Convert a boolean into a string
         *
         * @param boolVal: boolean value
         * @return string value
         */
        static string boolToString(bool boolVal);

        /**
         * Convert an integer into a string
         *
         * @param intVal: integer value
         * @return string value
         */
        static string intToString(int intVal);
};
#endif // _CONVERTER_H_