#ifndef _MEMBER_CONTROLLER_H_
#define _MEMBER_CONTROLLER_H_

#include <iostream>
#include <vector>
#include <algorithm>

#include "../models/service/Skill.h"
#include "../models/service/Availability.h"
#include "../models/service/Request.h"
#include "../models/service/Review.h"
#include "../models/user/Member.h"
#include "../utils/InputValidator.h"
#include "../utils/IdGenerator.h"
#include "../views/Menu.h"

using std::vector;

class Member;

class MemberController {
public:
    /**
     * Prompts the guest to sign up to be an member
     *
     * @param none
     * @return Member*
     */
    static Member* login();

    /**
     * This function will check if the user have a temporary password or not
     * and prompt them to change password
     *
     * @param Member*
     * @return none
    */
    static void resetPassword(Member* member);

    /**
     * Member can search for suitable supporter
     *
     * @param Member*: current member
     * @return vector<Member*>: list of suitable supporters
    */
    static vector<Member*> searchForSupporters(Member* currentMember);

    /**
     * Member can create a request for any supporter in the list
     *
     * @param Member*: current member
     * @param vector<Member*>: list of supporters
     * @return none
    */
    static void createRequest(Member* currentMember);

    /**
     * Member can block or unblock another member
     *
     * @param Member*: current member
     * @return none
    */
    static void adjustBlockedMembersList(Member* currentMember);

    /**
     * Member can set their available status and update their availability
     *
     * @param Member*: current member
     * @return none
    */
    static void manageAvailability(Member* currentMember);
    
    /**
     * Member can top up their credit points
     *
     * @param Member*: current member
     * @return none
    */
    static void topUpCredits(Member* currentMember);

    /**
     * Member can manage their request
     * 
     * @param Member*: current member
     * @return none
    */
    static void manageRequests(Member* currentMember);
    
    /**
     * Member can accept a specific request
     * 
     * @param Member*: current member
     * @return none
    */
    static void acceptRequest(Member* currentMember);

    /**
     * Member can reject a specific request
     *
     * @param Member*: current member
     * @return none
    */
    static void rejectRequest(Member* currentMember);

    /**
     * Member can rate hosts/supporters
     *
     * @param Member*: current member
     * @return none
    */
    static void rateMember(Member* currentMember);

    /**
     * Member can view their request history
     * 
     * @param Member*: current member
     * @return none
    */
    static void viewRequestHistory(Member* currentMember);

    /**
     * Member can rate a specific host in their request history
     * 
     * @param Member*: current member
     * @return none
    */
    static void rateHost(Member* currentMember);

    /**
     * Member can rate a specific supporter in their request history
     * 
     * @param Member*: current member
     * @return none
    */
    static void rateSupporter(Member* currentMember);
};

#endif // _MEMBER_CONTROLLER_H_