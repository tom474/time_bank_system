#ifndef _RANDOMIZER_H_
#define _RANDOMIZER_H_

#include "./FileManager.h"
#include "../models/user/Member.h"
#include "../models/service/Request.h"
#include "../models/service/Review.h"
#include "./Converter.h"

#include <iostream>
#include <string>

class IdGenerator {
    public: 
        static string generateMemberId();
        static string generateRequestId();
        static string generateReviewId();
};

#endif