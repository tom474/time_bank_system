#include "./Converter.h"

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

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

string Converter::intToString(int intVal) {
    std::stringstream sstr;
    string strVal;
    sstr << intVal;
    sstr >> strVal;
    return strVal;
}

string Converter::blockedUsersToString(vector<string> blockedUsers) {
    string strVal = "";
    for (int i = 0; i < blockedUsers.size(); i++) {
        strVal += blockedUsers[i];
        if (i != blockedUsers.size() - 1) {
            strVal += ", ";
        }
    }

    if (strVal == "") {
        strVal = "None";
    }

    return strVal;
}

string Converter::skillsToString(vector<Skill*> skills) {
    string strVal = "";
    for (int i = 0; i < skills.size(); i++) {
        strVal += skills[i]->getName();
        if (i != skills.size() - 1) {
            strVal += ", ";
        }
    }

    if (strVal == "") {
        strVal = "None";
    }
    
    return strVal;
}

vector<string> Converter::skillsToStringVector(vector<Skill*> skills) {
    vector<string> strVal;
    for (int i = 0; i < skills.size(); i++) {
        strVal.push_back(skills[i]->getName());
    }
    return strVal;
}