#include "InputValidator.h"

#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <limits>

using std::string;

void InputValidator::clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void InputValidator::displayError(const string& message) {
    std::cout << message << std::endl;
    clearInputStream();
}


int InputValidator::getInt(const string& prompt) {
    int value;
    while (true) {
        try {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.fail()) { // Check for failbit
                throw std::runtime_error("Invalid input.");
            }
            clearInputStream();
            return value;
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << " Please enter an integer.\n";
            std::cin.clear(); // Clear the failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}


double InputValidator::getDouble(const string& prompt) {
    double value;
    while (true) {
        try {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.fail()) {
                throw std::runtime_error("Invalid input.");
            }
            clearInputStream();
            return value;
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << " Please enter a double.\n";
            clearInputStream();
        }
    }
}


string InputValidator::getString(const string& prompt) {
    std::cout << prompt;
    string value;
    std::getline(std::cin, value);

    if (std::cin.fail()) {
        std::cin.clear();
        std::cerr << "Input error. Please enter a valid string.\n";
        return getString(prompt); // Recursive call for retry
    }
    return value;
}


bool InputValidator::getBool(const string& prompt) {
    string input;
    while (true) {
        try {
            std::cout << prompt;
            std::cin >> input;
            std::transform(input.begin(), input.end(), input.begin(), ::tolower);

            if (input == "yes" || input == "y") {
                clearInputStream();
                return true;
            } else if (input == "no" || input == "n") {
                clearInputStream();
                return false;
            } else {
                throw std::runtime_error("Invalid input.");
            }
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << " Please enter 'yes' or 'no'.\n";
            clearInputStream();
        }
    }
}


string InputValidator::getTime(const string& prompt) {
    std::regex timePattern(R"(^(2[0-3]|[01]?[0-9]):([0-5]?[0-9])$)");
    string time;

    while (true) {
        try {
            std::cout << prompt;
            std::cin >> time;

            if (!std::regex_match(time, timePattern)) {
                throw std::runtime_error("Invalid time format.");
            }
            clearInputStream();
            return time;
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << " Please use hh:mm format.\n";
            clearInputStream();
        }
    }
}


string InputValidator::getDate(const string& prompt) {
    std::regex datePattern(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[012])/(19|20)\d\d$)");
    string date;

    while (true) {
        try {
            std::cout << prompt;
            std::cin >> date;

            if (!std::regex_match(date, datePattern)) {
                throw std::runtime_error("Invalid date format.");
            }
            clearInputStream();
            return date;
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << " Please use dd/mm/yyyy format.\n";
            clearInputStream();
        }
    }
}