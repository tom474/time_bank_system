#ifndef _REVIEW_H_
#define _REVIEW_H_

#include <iostream>

using std::string;

enum reviewType {
    Supporter,
    Host
};

class Review {
    private:
        string reviewID;
        string reviewerID;
        string reviewedID;
        reviewType type;
        string comment;
        int ratingScore;
    public:
        Review();
        Review(string reviewIDVal, string reviewerIDVal, string reviewedIDVal, reviewType typeVal, string commentVal, int ratingScoreVal);
        string getReviewID();
        string getReviewerID();
        string getReviewedID();
        string getType();
        int getRatingScore();
        string getComment();
};

#endif  // _REVIEW_H_