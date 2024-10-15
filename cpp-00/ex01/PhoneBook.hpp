#pragma once

#include "Contact.hpp"
#include <iomanip>
#include <string>

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;
	int oldestIndex;

public:
	PhoneBook();

	void addContact(const Contact &newContact);

	void searchContacts() const;

	std::string formatField(const std::string &str) const;
};