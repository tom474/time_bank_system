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
    cout << string(tableWidth, '-') << "\n\n";
}