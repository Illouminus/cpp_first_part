#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

void PhoneBook::addContact(const Contact &newContact)
{
	if (contactCount < 8)
	{
		contacts[contactCount] = newContact;
		contactCount++;
	}
	else
	{
		contacts[oldestIndex] = newContact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
	std::cout << "Contact added successfully." << std::endl;
}

// Вспомогательный метод для форматирования полей
std::string PhoneBook::formatField(const std::string &str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
	{
		std::string formatted = str;
		while (formatted.length() < 10)
			formatted = " " + formatted;
		return formatted;
	}
}

// Метод для поиска и отображения контактов
void PhoneBook::searchContacts() const
{
	if (contactCount == 0)
	{
		std::cout << "PhoneBook is empty. Add some contacts first." << std::endl;
		return;
	}

	// Заголовок таблицы
	std::cout << std::setw(10) << "Index" << "|"
				 << std::setw(10) << "First Name" << "|"
				 << std::setw(10) << "Last Name" << "|"
				 << std::setw(10) << "Nickname" << std::endl;

	// Отображение всех контактов
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|"
					 << formatField(contacts[i].getFirstName()) << "|"
					 << formatField(contacts[i].getLastName()) << "|"
					 << formatField(contacts[i].getNickname()) << std::endl;
	}

	// Запрос индекса для просмотра деталей
	std::string input;
	std::cout << "Enter the index of the contact to display: ";
	std::getline(std::cin, input);

	// Проверка корректности ввода
	if (input.empty())
	{
		std::cout << "No index entered." << std::endl;
		return;
	}

	// Проверка, что все символы в строке цифры
	bool isNumber = true;
	for (char c : input)
	{
		if (!isdigit(c))
		{
			isNumber = false;
			break;
		}
	}

	if (!isNumber)
	{
		std::cout << "Invalid index format." << std::endl;
		return;
	}

	int index = std::stoi(input);
	if (index < 1 || index > contactCount)
	{
		std::cout << "Index out of range." << std::endl;
		return;
	}
	contacts[index - 1].displayFullContact();
}