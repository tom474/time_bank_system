#ifndef _MEMBER_CONTROLLER_H_
#define _MEMBER_CONTROLLER_H_

#include <iostream>
#include <vector>
#include "../models/service/Skill.h"
#include "../models/service/Availability.h"
#include "../models/service/Request.h"
#include "../models/service/Review.h"
#include "../models/user/Member.h"
#include "../utils/InputValidator.h"
#include "../utils/IdGenerator.h"
#include "../views/Menu.h"

using std::vector;

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
     * Print out the list of members as a table
     *
     * @param vector<Member*>: list of members
     * @return none
     */
    static void viewMemberList(vector<Member*> members);

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
};

#endif // _MEMBER_CONTROLLER_H_
