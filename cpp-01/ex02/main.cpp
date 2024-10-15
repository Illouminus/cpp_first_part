#include <iostream>
#include <string>

int main()
{
    // Инициализация строки
    std::string str = "HI THIS IS BRAIN";
    
    // Создание указателя на строку
    std::string *stringPTR = &str;
    
    // Создание ссылки на строку
    std::string &stringREF = str;
    
    // Вывод адреса самой строки
    std::cout << "Adresse de la string: " << &str << std::endl;
    
    // Вывод адреса, хранящегося в stringPTR
    std::cout << "Adresse stockée dans stringPTR: " << stringPTR << std::endl;
    
    // Вывод адреса, хранящегося в stringREF (адрес строки)
    std::cout << "Adresse stockée dans stringREF: " << &stringREF << std::endl;
    
    std::cout << std::endl; 
    
    // Вывод значения самой строки
    std::cout << "Valeur de la string: " << str << std::endl;
    
    // Вывод значения, на которое указывает stringPTR
    std::cout << "Valeur pointée par stringPTR: " << *stringPTR << std::endl;
    
    // Вывод значения, на которое ссылается stringREF
    std::cout << "Valeur pointée par stringREF: " << stringREF << std::endl;
    
    return 0;
}
