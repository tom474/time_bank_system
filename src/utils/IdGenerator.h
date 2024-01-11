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
        /**
         * Generate the memberID
         *
         * @param none
         * @return string: a unique memberID with the prefix 'MB'
         */
        static string generateMemberId();

        /**
         * Generate the requestID
         *
         * @param none
         * @return string: a unique requestID with the prefix 'RQ'
         */
        static string generateRequestId();

        /**
         * Generate the reviewID
         *
         * @param none
         * @return string: a unique reviewID with the prefix 'RV'
         */
        static string generateReviewId();
};

#endif