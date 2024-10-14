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
	// Конструктор
	PhoneBook();

	// Метод для добавления контакта
	void addContact(const Contact &newContact);

	// Метод для поиска и отображения контактов
	void searchContacts() const;

	// Вспомогательный метод для форматирования полей
	std::string formatField(const std::string &str) const;
};