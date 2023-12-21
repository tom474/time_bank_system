#include "./Review.h"

#include <iostream>

using std::string;
using std::cout;
using std::cin;

Review::Review() {}

Review::Review(
    string reviewIDVal = "", 
    string reviewerIDVal = "", 
    string reviewedIDVal = "", 
    reviewType typeVal = reviewType::Supporter, 
    string commentVal = "", 
    int ratingScoreVal = 0) 
    : reviewID(reviewIDVal), 
    reviewerID(reviewerIDVal), 
    reviewedID(reviewedIDVal), 
    type(typeVal), 
    comment(commentVal), 
    ratingScore(ratingScoreVal) {
}

string Review::getReviewID() {
    return reviewID;
}

int Review::getRatingScore() {
    return ratingScore;
}

string Review::getReviewedID() {
    return reviewedID;
}

string Review::getReviewerID() {
    return reviewerID;
}

string Review::getComment() {
    return comment;
}

string Review::getType() {
    return type == reviewType::Supporter ? "Supporter" : "Host";
}