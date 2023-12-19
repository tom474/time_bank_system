#include "Skill.h"

#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

Skill::Skill(
    string nameVal = "",
    string descriptionVal ="",
    string memberIDVal = "",
    vector<int> ratingScoreVal = {}) 
    : name(nameVal),
    description(descriptionVal),
    memberID(memberIDVal),
    ratingScore(ratingScoreVal){
};

string Skill::getDescription() {
    return description;
}

string Skill::getMemberID() {
    return memberID;
}

string Skill::getName() {
    return name;
}

int Skill::getRatingScore() {
    int sum = 0;
    for (auto rating : ratingScore) {
        sum += rating;
    }
    return sum / ratingScore.size();
}
