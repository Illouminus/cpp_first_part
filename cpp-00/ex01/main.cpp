
#include <iostream>
#include "PhoneBook.hpp"

std::string getInput(const std::string &prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			// Если произошёл EOF (например, Ctrl+D), завершить программу
			std::cout << "\nExiting program." << std::endl;
			exit(0);
		}
		if (!input.empty())
			break;
		std::cout << "This field cannot be empty. Please enter again." << std::endl;
	}
	return input;
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nExiting program." << std::endl;
			break;
		}

		if (command == "ADD")
		{
			Contact newContact;
			std::string input;

			// Получение данных от пользователя
			input = getInput("First Name: ");
			newContact.setFirstName(input);

			input = getInput("Last Name: ");
			newContact.setLastName(input);

			input = getInput("Nickname: ");
			newContact.setNickname(input);

			input = getInput("Phone Number: ");
			newContact.setPhoneNumber(input);

			input = getInput("Darkest Secret: ");
			newContact.setDarkestSecret(input);

			phoneBook.addContact(newContact);
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContacts();
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting program." << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		}
	}

	return 0;
}