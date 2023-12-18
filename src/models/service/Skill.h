#ifndef _SKILL_H_
#define _SKILL_H_

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Skill {
    private:
        string name;
        string description;
        vector<int> ratingScore;
        string memberID;
    public:
        Skill(string nameVal, string descriptionVal, string memberIDVal, vector<int> ratingScoreVal);
        string getName();
        string getDescription();
        int getRatingScore();
        string getMemberID();
};

#endif // _SKILL_H_