#ifndef _INPUT_VALIDATOR_H
#define _INPUT_VALIDATOR_H

#include <string>
#include "../models/user/Member.h"

using std::string;

using std::string;

class InputValidator {
    private:
        static void clearInputStream();
        static void displayError(const string& message);

    public:
        /**
        * Prompts the user to enter an integer and validates the input.
        * 
        * @param prompt The message displayed to the user.
        * @return The validated integer input from the user.
        */
        static int getInt(const string& prompt);


        /**
        * Prompts the user to enter a double and validates the input.
        * 
        * @param prompt The message displayed to the user.
        * @return The validated double input from the user.
        */
        static double getDouble(const string& prompt);


        /**
         * Get string from the console
         * 
         * @param prompt is the prompt shows to the user when input the string
         * @return the string that the user input in the console
        */
        static string getString(const string& prompt);


        /**
        * Prompts the user to enter a string. This method can capture strings
        * containing whitespaces.
        * 
        * @param prompt The message displayed to the user.
        * @return The string input from the user.
        */
        static bool getBool(const string& prompt);


        /**
        * Prompts the user to enter time in hh:mm format and validates it.
        * 
        * @param prompt The message displayed to the user.
        * @return The validated time string from the user.
        */
        static string getTime(const string& prompt);


        /**
        * Prompts the user to enter a date in dd/mm/yyyy format and validates it.
        * 
        * @param prompt The message displayed to the user.
        * @return The validated date string from the user.
        */
        static string getDate(const string& prompt);


        /**
        * Prompts the user to enter a phone number and validates it.
        * 
        * @param prompt The message displayed to the user.
        * @return The validated phone number string from the user.
        */
        static string getPhoneNumber(const string& prompt);


        /**
        * Prompts the user to enter an email and validates it.
        * 
        * @param prompt The message displayed to the user.
        * @return The validated email string from the user.
        */
        static string getEmail(const string &prompt);


        /**
        * Prompts the user to enter a city and validates it.
        * 
        * @param prompt The message displayed to the user.
        * @return The validated city enum from the user.
        */
        static availableCity getCity(const string &prompt);
};

#endif // _INPUT_VALIDATOR_H
