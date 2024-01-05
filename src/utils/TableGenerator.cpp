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
    // Calculate the maximum length for each column
    size_t idWidth = 8;
    size_t fullnameWidth = 0;
    size_t skillWidth = 0;
    size_t phoneNumberWidth = 12;
    size_t emailWidth = 0;
    size_t homeAddressWidth = 0;
    size_t cityWidth = 8;
    size_t statusWidth = 6;

    for (Member *member : members) {
        fullnameWidth = max(fullnameWidth, member->getFullname().length());
        skillWidth = max(skillWidth, Converter::skillsToString(member->getSkill()).length());
        emailWidth = max(emailWidth, member->getEmail().length());
        homeAddressWidth = max(homeAddressWidth, member->getHomeAddress().length());
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
        cout << "| " << std::left << setw(idWidth) << member->getMemberId() << " | "
                  << setw(fullnameWidth) << member->getFullname() << " | "
                  << setw(skillWidth) << Converter::skillsToString(member->getSkill()) << " | "
                  << setw(phoneNumberWidth) << member->getPhoneNumber() << " | "
                  << setw(emailWidth) << member->getEmail() << " | "
                  << setw(homeAddressWidth) << member->getHomeAddress() << " | "
                  << setw(cityWidth) << member->getAvailableCity() << " | "
                  << setw(statusWidth) << Converter::boolToString(member->getAvailableStatus()) << " |"
                  << "\n";
    }

    // Print a line separator
    cout << string(tableWidth, '-') << "\n";
}

void TableGenerator::generateAvailabilityTable(string title, vector<Availability *> availabilities) {
    // Calculate the maximum length for each column
    size_t skillWidth = 0;

    for (Availability *availability : availabilities) {
        skillWidth = std::max(skillWidth, Converter::skillsToString(availability->getPerformedSkills()).length());
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
    // Calculate the maximum length for each column
    size_t requestIDWidth = 10;
    size_t hostIDWidth = 8;
    size_t supporterIDWidth = 12;
    size_t startTimeWidth = 16;
    size_t endTimeWidth = 16;
    size_t requestedSkillsWidth = 0;
    size_t statusWidth = 8;

    for (Request *request : requests) {
        requestedSkillsWidth = std::max(requestedSkillsWidth, Converter::skillsToString(request->getRequestedSkills()).length());
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