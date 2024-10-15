
#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

void Contact::setFirstName(const std::string &fname)
{
	firstName = fname;
}

void Contact::setLastName(const std::string &lname)
{
	lastName = lname;
}

void Contact::setNickname(const std::string &nname)
{
	nickname = nname;
}

void Contact::setPhoneNumber(const std::string &pnumber)
{
	phoneNumber = pnumber;
}

void Contact::setDarkestSecret(const std::string &dsecret)
{
	darkestSecret = dsecret;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}

// Метод для отображения полного контакта
void Contact::displayFullContact() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}