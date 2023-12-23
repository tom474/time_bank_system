#include "MenuOptionsGenerator.h"

void MenuOptionsGenerator::showMenu(vector<string> options)
{
    for (int i = 0; i < options.size(); i++)
    {
        cout << i + 1 << ". " << options[i] << endl;
    }
    cout << "\n";
}