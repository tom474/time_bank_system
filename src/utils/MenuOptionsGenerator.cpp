#include "MenuOptionsGenerator.h"
#include "InputValidator.h"

void MenuOptionsGenerator::showMenu(vector<string> options) {
    for (int i = 0; i < options.size(); i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
    cout << "\n";
}

int MenuOptionsGenerator::showMenuWithSelect(const string &message, vector<string> options) {
    bool isExit = false;
    if (options[0] == "Exit") {
        isExit = true;
    }
    cout << message;
    cout << "\n";
    for (int i = 0; i < options.size(); i++) {
        if (isExit) {
            cout << i << ". " << options[i] << endl;
        } else {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }
    cout << "\n";
    ostringstream prompt;
    if (isExit) {
        prompt << "Enter your choice (0-" << options.size() - 1 << "): ";
    } else {
        prompt << "Enter your choice (1-" << options.size() << "): ";
    }
    int choice = InputValidator::getInt(prompt.str());
    return choice;
}