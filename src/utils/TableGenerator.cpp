#include "./TableGenerator.h"

#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::string;
using std::vector;
using std::setw;
using std::max;

void TableGenerator::generateMemberTable(string title, vector<Member *> members) {
    if (members.size() == 0) {
        cout << "There is no member in the database!\n";
        return;
    }

    // Calculate the maximum length for each column
    size_t idWidth = 8;
    size_t fullnameWidth = 8;
    size_t skillWidth = 6;
    size_t phoneNumberWidth = 12;
    size_t emailWidth = 5;
    size_t homeAddressWidth = 12;
    size_t cityWidth = 8;
    size_t statusWidth = 6;

    for (Member *member : members) {
        size_t width;
        width = std::max(fullnameWidth, member->getFullname().length());
        if (width > fullnameWidth) {
            fullnameWidth = width;
        }
        width = std::max(skillWidth, Converter::skillsToString(member->getSkill()).length());
        if (width > skillWidth) {
            skillWidth = width;
        }
        width = std::max(emailWidth, member->getEmail().length());
        if (width > emailWidth) {
            emailWidth = width;
        }
        width = std::max(homeAddressWidth, member->getHomeAddress().length());
        if (width > homeAddressWidth) {
            homeAddressWidth = width;
        }
        string statusStr = member->getAvailableStatus() ? "Available" : "Unavailable";
        width = std::max(statusWidth, statusStr.length());
        if (width > statusWidth) {
            statusWidth = width;
        }
    }

    // Print the title
    size_t titleLength = title.length() + 2;
    size_t tableWidth = idWidth + fullnameWidth + skillWidth + phoneNumberWidth + emailWidth + homeAddressWidth + cityWidth + statusWidth + 25;
    size_t leftPadding = (tableWidth - titleLength) / 2;
    size_t rightPadding = tableWidth - titleLength - leftPadding;

    cout << "\n";
    cout << string(leftPadding, '-') << " " << title << " " << string(rightPadding, '-') << "\n";

    // Print a line separator
    cout << string(tableWidth, '-') << "\n";

    // Print the header
    cout << "| " << std::left << setw(idWidth) << "ID" << " | "
              << setw(fullnameWidth) << "Fullname" << " | "
              << setw(skillWidth) << "Skills" << " | "
              << setw(phoneNumberWidth) << "Phone Number" << " | "
              << setw(emailWidth) << "Email" << " | "
              << setw(homeAddressWidth) << "Home Address" << " | "
              << setw(cityWidth) << "City" << " | "
              << setw(statusWidth) << "Status" << " |\n";

    // Print a line separator
    cout << string(tableWidth, '-') << "\n";

    // Print the member information
    for (Member *member : members) {
        string statusStr = member->getAvailableStatus() ? "Available" : "Unavailable";
        cout << "| " << std::left << setw(idWidth) << member->getMemberId() << " | "
                  << setw(fullnameWidth) << member->getFullname() << " | "
                  << setw(skillWidth) << Converter::skillsToString(member->getSkill()) << " | "
                  << setw(phoneNumberWidth) << member->getPhoneNumber() << " | "
                  << setw(emailWidth) << member->getEmail() << " | "
                  << setw(homeAddressWidth) << member->getHomeAddress() << " | "
                  << setw(cityWidth) << member->getAvailableCity() << " | "
                  << setw(statusWidth) << statusStr << " |"
                  << "\n";
    }

    // Print a line separator
    cout << string(tableWidth, '-') << "\n";
}

void TableGenerator::generateAvailabilityTable(string title, vector<Availability *> availabilities) {
    if (availabilities.size() == 0) {
        cout << "There is no availability to display!\n";
        return;
    }

    // Calculate the maximum length for each column
    size_t skillWidth = 6;

    for (Availability *availability : availabilities) {
        size_t width = std::max(skillWidth, Converter::skillsToString(availability->getPerformedSkills()).length());
        if (width > skillWidth) {
            skillWidth = width;
        }
    }

    // Print the title
    size_t titleLength = title.length() + 2;
    size_t tableWidth = 8 + 16 + 16 + skillWidth + 14 + 16;
    size_t leftPadding = (tableWidth - titleLength) / 2;
    size_t rightPadding = tableWidth - titleLength - leftPadding;

    std::cout << "\n";
    std::cout << std::string(leftPadding, '-') << " " << title << " " << std::string(rightPadding, '-') << "\n";
    
    // Print a line separator
    std::cout << std::string(8 + 16 + 16 + skillWidth + 14 + 16, '-') << "\n";

    std::cout << "| " << std::left << std::setw(8) << "Session" << " | "
              << std::setw(16) << "Start Time" << " | "
              << std::setw(16) << "End Time" << " | "
              << std::setw(skillWidth) << "Skills" << " | "
              << std::setw(14) << "Point Per Hour" << " |\n";

    // Print a line separator
    std::cout << std::string(8 + 16 + 16 + skillWidth + 14 + 16, '-') << "\n";

    // Print the availability information
    int session = 1;
    for (Availability *availability : availabilities) {
        std::cout << "| " << std::left << std::setw(8) << session << " | "
                  << std::setw(16) << availability->getAvailableTime()->getStartTime().toString() << " | "
                  << std::setw(16) << availability->getAvailableTime()->getEndTime().toString() << " | "
                  << std::setw(skillWidth) << Converter::skillsToString(availability->getPerformedSkills()) << " | "
                  << std::right << std::setw(14) << availability->getPointPerHour() << " |\n";
        session++;
    }

    // Print a line separator
    std::cout << std::string(8 + 16 + 16 + skillWidth + 14 + 16, '-') << "\n";
}

void TableGenerator::generateRequestTable(string title, vector<Request *> requests) {
    if (requests.size() == 0) {
        cout << "There is no request to display!\n";
        return;
    }

    // Calculate the maximum length for each column
    size_t requestIDWidth = 10;
    size_t hostIDWidth = 8;
    size_t supporterIDWidth = 12;
    size_t startTimeWidth = 16;
    size_t endTimeWidth = 16;
    size_t requestedSkillsWidth = 16;
    size_t statusWidth = 8;

    for (Request *request : requests) {
        size_t skillWidth = std::max(requestedSkillsWidth, Converter::skillsToString(request->getRequestedSkills()).length());
        if (skillWidth > requestedSkillsWidth) {
            requestedSkillsWidth = skillWidth;
        }
    }

    // Print the title
    size_t titleLength = title.length() + 2;
    size_t tableWidth = requestIDWidth + hostIDWidth + supporterIDWidth + startTimeWidth + endTimeWidth + requestedSkillsWidth + statusWidth + 22;
    size_t leftPadding = (tableWidth - titleLength) / 2;
    size_t rightPadding = tableWidth - titleLength - leftPadding;

    std::cout << "\n";
    std::cout << std::string(leftPadding, '-') << " " << title << " " << std::string(rightPadding, '-') << "\n";

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the header
    std::cout << "| " << std::left << std::setw(requestIDWidth) << "Request ID" << " | "
              << std::setw(hostIDWidth) << "Host ID" << " | "
              << std::setw(supporterIDWidth) << "Supporter ID" << " | "
              << std::setw(startTimeWidth) << "Start Time" << " | "
              << std::setw(endTimeWidth) << "End Time" << " | "
              << std::setw(requestedSkillsWidth) << "Requested Skills" << " | "
              << std::setw(statusWidth) << "Status" << " |\n";
    
    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the request information
    for (Request *request : requests) {
        std::cout << "| " << std::left << std::setw(requestIDWidth) << request->getRequestID() << " | "
                  << std::setw(hostIDWidth) << request->getHostID() << " | "
                  << std::setw(supporterIDWidth) << request->getSupporterID() << " | "
                  << std::setw(startTimeWidth) << request->getRequestedTime()->getStartTime().toString() << " | "
                  << std::setw(endTimeWidth) << request->getRequestedTime()->getEndTime().toString() << " | "
                  << std::setw(requestedSkillsWidth) << Converter::skillsToString(request->getRequestedSkills()) << " | "
                  << std::setw(statusWidth) << request->getStatus() << " |\n";
    }

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";
}

void TableGenerator::generateReviewTable(string title, vector<Review *> reviews) {
    if (reviews.size() == 0) {
        cout << "There is no review to display!\n";
        return;
    }

    // Calculate the maximum length for each column
    size_t reviewIDWidth = 10;
    size_t reviewerIDWidth = 12;
    size_t reviewedIDWidth = 12;
    size_t ratingWidth = 6;
    size_t commentWidth = 8;

    for (Review *review : reviews) {
        size_t width;
        width = std::max(commentWidth, review->getComment().length());
        if (width > commentWidth) {
            commentWidth = width;
        }
    }

    // Print the title
    size_t titleLength = title.length() + 2;
    size_t tableWidth = reviewIDWidth + reviewerIDWidth + reviewedIDWidth + ratingWidth + commentWidth + 16;
    size_t leftPadding = (tableWidth - titleLength) / 2;
    size_t rightPadding = tableWidth - titleLength - leftPadding;

    std::cout << "\n";
    std::cout << std::string(leftPadding, '-') << " " << title << " " << std::string(rightPadding, '-') << "\n";

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the header
    std::cout << "| " << std::left << std::setw(reviewIDWidth) << "Review ID" << " | "
              << std::setw(reviewerIDWidth) << "Reviewer ID" << " | "
              << std::setw(reviewedIDWidth) << "Reviewee ID" << " | "
              << std::setw(ratingWidth) << "Rating" << " | "
              << std::setw(commentWidth) << "Comment" << " |\n";
    
    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the review information
    for (Review *review : reviews) {
        std::cout << "| " << std::left << std::setw(reviewIDWidth) << review->getReviewID() << " | "
                  << std::setw(reviewerIDWidth) << review->getReviewerID() << " | "
                  << std::setw(reviewedIDWidth) << review->getReviewedID() << " | "
                  << std::setw(ratingWidth) << review->getRatingScore() << " | "
                  << std::setw(commentWidth) << review->getComment() << " |\n";
    }

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";
}

void TableGenerator::generateSkillTable(string title, vector<Skill *> skills) {
    if (skills.size() == 0) {
        cout << "There is no skill to display!\n";
        return;
    }

    // Calculate the maximum length for each column
    size_t nameWidth = 4;
    size_t descriptionWidth = 11;
    size_t ratingWidth = 6;

    for (Skill *skill : skills) {
        size_t width;
        width = std::max(nameWidth, skill->getName().length());
        if (width > nameWidth) {
            nameWidth = width;
        }
        width = std::max(descriptionWidth, skill->getDescription().length());
        if (width > descriptionWidth) {
            descriptionWidth = width;
        }
    }

    // Print the title
    size_t titleLength = title.length() + 2;
    size_t tableWidth = nameWidth + descriptionWidth + ratingWidth + 10;
    size_t leftPadding = (tableWidth - titleLength) / 2;
    size_t rightPadding = tableWidth - titleLength - leftPadding;

    std::cout << "\n";
    std::cout << std::string(leftPadding, '-') << " " << title << " " << std::string(rightPadding, '-') << "\n";

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the header
    std::cout << "| " << std::left << std::setw(nameWidth) << "Name" << " | "
              << std::setw(descriptionWidth) << "Description" << " | "
              << std::setw(ratingWidth) << "Rating" << " |\n";
    
    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the skill information
    for (Skill *skill : skills) {
        std::cout << "| " << std::left << std::setw(nameWidth) << skill->getName() << " | "
                  << std::setw(descriptionWidth) << skill->getDescription() << " | "
                  << std::setw(ratingWidth) << std::fixed << std::setprecision(1) << skill->getAverageRatingScore() << " |\n";
    }

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";
}

void TableGenerator::generateHostTable(string title, vector<Member *> hosts) {
    if (hosts.size() == 0) {
        cout << "There is no host to display!\n";
        return;
    }

    // Calculate the maximum length for each column
    size_t idWidth = 8;
    size_t fullnameWidth = 8;
    size_t phoneNumberWidth = 12;
    size_t emailWidth = 5;
    size_t cityWidth = 8;
    size_t hostRatingWidth = 11;

    for (Member *host : hosts) {
        size_t width;
        width = std::max(fullnameWidth, host->getFullname().length());
        if (width > fullnameWidth) {
            fullnameWidth = width;
        }
        width = std::max(emailWidth, host->getEmail().length());
        if (width > emailWidth) {
            emailWidth = width;
        }
    }

    // Print the title
    size_t titleLength = title.length() + 2;
    size_t tableWidth = idWidth + fullnameWidth + phoneNumberWidth + emailWidth + cityWidth + hostRatingWidth + 19;
    size_t leftPadding = (tableWidth - titleLength) / 2;
    size_t rightPadding = tableWidth - titleLength - leftPadding;

    std::cout << "\n";
    std::cout << std::string(leftPadding, '-') << " " << title << " " << std::string(rightPadding, '-') << "\n";

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the header
    std::cout << "| " << std::left << std::setw(idWidth) << "ID" << " | "
              << std::setw(fullnameWidth) << "Fullname" << " | "
              << std::setw(phoneNumberWidth) << "Phone Number" << " | "
              << std::setw(emailWidth) << "Email" << " | "
              << std::setw(cityWidth) << "City" << " | "
              << std::setw(hostRatingWidth) << "Host Rating" << " |\n";

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the host information
    for (Member *host : hosts) {
        std::cout << "| " << std::left << std::setw(idWidth) << host->getMemberId() << " | "
                  << std::setw(fullnameWidth) << host->getFullname() << " | "
                  << std::setw(phoneNumberWidth) << host->getPhoneNumber() << " | "
                  << std::setw(emailWidth) << host->getEmail() << " | "
                  << std::setw(cityWidth) << host->getAvailableCity() << " | "
                  << std::setw(hostRatingWidth) << std::fixed << std::setprecision(1) << host->getHostRating() << " |\n";
    }

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";
}

void TableGenerator::generateSupporterTable(string title, vector<Member *> supporters) {
    if (supporters.size() == 0) {
        cout << "There is no supporter to display!\n";
        return;
    }

    // Calculate the maximum length for each column
    size_t idWidth = 8;
    size_t fullnameWidth = 8;
    size_t phoneNumberWidth = 12;
    size_t emailWidth = 5;
    size_t cityWidth = 8;
    size_t skillWidth = 6;
    size_t supporterRatingWidth = 16;

    for (Member *supporter : supporters) {
        size_t width;
        width = std::max(fullnameWidth, supporter->getFullname().length());
        if (width > fullnameWidth) {
            fullnameWidth = width;
        }
        width = std::max(emailWidth, supporter->getEmail().length());
        if (width > emailWidth) {
            emailWidth = width;
        }
        width = std::max(skillWidth, Converter::skillsToString(supporter->getSkill()).length());
        if (width > skillWidth) {
            skillWidth = width;
        }
    }

    // Print the title
    size_t titleLength = title.length() + 2;
    size_t tableWidth = idWidth + fullnameWidth + phoneNumberWidth + emailWidth + cityWidth + skillWidth + supporterRatingWidth + 22;
    size_t leftPadding = (tableWidth - titleLength) / 2;
    size_t rightPadding = tableWidth - titleLength - leftPadding;

    std::cout << "\n";
    std::cout << std::string(leftPadding, '-') << " " << title << " " << std::string(rightPadding, '-') << "\n";

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the header
    std::cout << "| " << std::left << std::setw(idWidth) << "ID" << " | "
              << std::setw(fullnameWidth) << "Fullname" << " | "
              << std::setw(phoneNumberWidth) << "Phone Number" << " | "
              << std::setw(emailWidth) << "Email" << " | "
              << std::setw(cityWidth) << "City" << " | "
              << std::setw(skillWidth) << "Skills" << " | "
              << std::setw(supporterRatingWidth) << "Supporter Rating" << " |\n";

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the supporter information
    for (Member *supporter : supporters) {
        std::cout << "| " << std::left << std::setw(idWidth) << supporter->getMemberId() << " | "
                  << std::setw(fullnameWidth) << supporter->getFullname() << " | "
                  << std::setw(phoneNumberWidth) << supporter->getPhoneNumber() << " | "
                  << std::setw(emailWidth) << supporter->getEmail() << " | "
                  << std::setw(cityWidth) << supporter->getAvailableCity() << " | "
                  << std::setw(skillWidth) << Converter::skillsToString(supporter->getSkill()) << " | "
                  << std::setw(supporterRatingWidth) << std::fixed << std::setprecision(1) << supporter->getSupporterRating() << " |\n";
    }

    // Print a line separator
    std::cout << std::string(tableWidth, '-') << "\n";
}