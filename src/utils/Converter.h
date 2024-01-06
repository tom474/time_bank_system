#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include "../models/service/Skill.h"

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

        /**
         * Convert a vector of blocked user id into a string
         * 
         * @param vector<string>: list of blocked user id
         * @return string value
        */
        static string blockedUsersToString(vector<string> blockedUsers);

        /**
         * Convert a skills list into a string
         *
         * @param vector<Skill*>: list of skills
         * @return string value
         */
        static string skillsToString(vector<Skill*> skills);

        /**
         * Convert a skills list into a string vector
         * 
         * @param vector<Skill*>: list of skills
         * @return vector<string>: string vector
        */
        static vector<string> skillsToStringVector(vector<Skill*> skills);
};
#endif // _CONVERTER_H_