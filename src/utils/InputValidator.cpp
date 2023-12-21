#include "InputValidator.h"

#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <limits>


void InputValidator::clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void InputValidator::displayError(const std::string& message) {
    std::cout << message << std::endl;
    clearInputStream();
}


/**
* Prompts the user to enter an integer and validates the input.
* 
* @param prompt The message displayed to the user.
* @return The validated integer input from the user.
*/
int InputValidator::getInt(const std::string& prompt) {
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


/**
* Prompts the user to enter a double and validates the input.
* 
* @param prompt The message displayed to the user.
* @return The validated double input from the user.
*/
double InputValidator::getDouble(const std::string& prompt) {
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


/***
 * Get string from the console
 * 
 * @param prompt is the prompt shows to the user when input the string
 * @return the string that the user input in the console
*/
std::string InputValidator::getString(const std::string& prompt) {
    std::cout << prompt;
    std::string value;
    std::getline(std::cin, value);

    if (std::cin.fail()) {
        std::cin.clear();
        std::cerr << "Input error. Please enter a valid string.\n";
        return getString(prompt); // Recursive call for retry
    }
    return value;
}


/**
* Prompts the user to enter a string. This method can capture strings
* containing whitespaces.
* 
* @param prompt The message displayed to the user.
* @return The string input from the user.
*/
bool InputValidator::getBool(const std::string& prompt) {
    std::string input;
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


/**
* Prompts the user to enter time in hh:mm format and validates it.
* 
* @param prompt The message displayed to the user.
* @return The validated time string from the user.
*/
std::string InputValidator::getTime(const std::string& prompt) {
    std::regex timePattern(R"(^(2[0-3]|[01]?[0-9]):([0-5]?[0-9])$)");
    std::string time;

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


/**
* Prompts the user to enter a date in dd/mm/yyyy format and validates it.
* 
* @param prompt The message displayed to the user.
* @return The validated date string from the user.
*/
std::string InputValidator::getDate(const std::string& prompt) {
    std::regex datePattern(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[012])/(19|20)\d\d$)");
    std::string date;

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


/**
* Prompts the user to enter a phone number and validates it.
* 
* @param prompt The message displayed to the user.
* @return The validated phone number string from the user.
*/
std::string InputValidator::getPhoneNumber(const std::string& prompt) {
    std::regex phonePattern(R"(^\d{10}$)");
    std::string phoneNumber;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, phoneNumber);

        if (std::regex_match(phoneNumber, phonePattern)) {
            return phoneNumber;
        } else {
            std::cerr << "Invalid phone number. Please enter a 10-digit number.\n";
        }
    }
}


/**
* Prompts the user to enter an email and validates it.
* 
* @param prompt The message displayed to the user.
* @return The validated email string from the user.
*/
std::string InputValidator::getEmail(const std::string& prompt) {
    std::regex emailPattern(R"(^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$)");
    std::string email;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, email);

        if (std::regex_match(email, emailPattern)) {
            return email;
        } else {
            std::cerr << "Invalid email. Please enter a valid email address.\n";
        }
    }
}


/**
* Prompts the user to enter a city and validates it.
* 
* @param prompt The message displayed to the user.
* @return The validated city enum from the user.
*/
availableCity InputValidator::getCity(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt << " (Saigon/Hanoi): ";
        std::getline(std::cin, input);

        if (input == "Saigon" || input == "SaiGon") {
            return SaiGon;
        } else if (input == "Hanoi" || input == "HaNoi") {
            return HaNoi;
        } else {
            std::cerr << "Invalid input. Please enter 'Saigon' or 'Hanoi'.\n";
        }
    }
}
