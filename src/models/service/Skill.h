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
        Skill();
        Skill(string nameVal, string descriptionVal, string memberIDVal, vector<int> ratingScoreVal);
        string getName();
        string getDescription();
        vector<int> getRatingScore();
        double getAverageRatingScore();
        string getMemberID();
        void addRatingScore(int ratingScoreVal);
        ~Skill();
};

#endif  // _SKILL_H_