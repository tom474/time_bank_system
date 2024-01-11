#include "./GuestController.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

void GuestController::signUp() {
	cout << "\n---------- Sign Up ----------\n";
	string memberID = IdGenerator::generateMemberId();
	int creditPoint = 20;
	vector<Skill*> skills = {};
	vector<Availability*> availability = {};
	vector<string> blockedUsers = {};
	vector<Request*> sendingRequests = {};
	vector<Request*> receivingRequests = {};
	vector<Review*> reviews = {};
	
	// Get unique username
	string username;
	bool isUniqueUsername = false;
	while (!isUniqueUsername) {
		bool isExistingUsername = false;
		username = InputValidator::getString("Enter your username: ");
		for (Member* member : Menu::allMembers) {
			if (member->getUsername() == username) {
				cout << "This username is already taken. Please enter another username!\n";
				isExistingUsername = true;
				break;
			}
		}

		if (!isExistingUsername) {
			isUniqueUsername = true;
		}
	}

	// Get other information
	string password = InputValidator::getString("Enter your password: ");
	string fullname = InputValidator::getString("Enter your fullname: ");
	string phoneNumber = InputValidator::getPhoneNumber("Enter your phone number: ");
	string email = InputValidator::getEmail("Enter your email: ");
	availableCity city = InputValidator::getCity("Enter the city where you are living");
	string homeAddress = InputValidator::getString("Enter your home address: ");
	bool availableStatus = InputValidator::getBool("Are you available to support other members now? (yes/no): ");
	cout << "Now you will have to enter at least 1 skill\n";
	bool isAddingSkill = true;
	while (isAddingSkill) {
		string skillName = InputValidator::getString("Enter your skill name: ");
		string skillDescription = InputValidator::getString("Please describe that skill: ");
		Skill* newSkill = new Skill(skillName, skillDescription, memberID, {});
		skills.push_back(newSkill);
		isAddingSkill = InputValidator::getBool("Do you want to enter another skill? (yes/no): ");
	}
	bool isResetPassword = false;

	Member* newMember = new (std::nothrow) Member(username, password, memberID, fullname, creditPoint, phoneNumber, email, homeAddress, city, availableStatus, isResetPassword, skills, availability, blockedUsers, sendingRequests, receivingRequests, reviews);
	Menu::allMembers.push_back(newMember);
	FileManager::saveMemberDatabase(Menu::allMembers);
	cout << "Register Successfully!\n";
};