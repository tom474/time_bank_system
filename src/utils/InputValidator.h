#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>

class InputValidator {
private:
    void clearInputStream();
    void displayError(const std::string& message);

public:
    int getInt(const std::string& prompt);
    double getDouble(const std::string& prompt);
    std::string getString(const std::string& prompt);
    bool getBool(const std::string& prompt);
    std::string getTime(const std::string& prompt);
    std::string getDate(const std::string& prompt);
};

#endif // INPUTVALIDATOR_H
