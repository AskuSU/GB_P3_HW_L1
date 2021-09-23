#include <windows.h>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"



int main()
{
	setlocale(LC_ALL, "RU");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    std::ifstream file("../Input.txt");
    PhoneBook book(file);
    std::cout << book;

    //std::cout << "------SortByPhone-------" << std::endl;
    //book.SortByPhone();
    //std::cout << book;

    std::cout << "------SortByName--------" << std::endl;
    book.SortByName();
    std::cout << book;

    //std::cout << "-----GetPhoneNumber-----" << std::endl;

    //// лямбда функция, которая принимает фамилию и выводит номер телефона этого человека, либо строку с ошибкой 
    //auto print_phone_number = [&book](const string& surname) {
    //    std::cout << surname << "\t";
    //    auto answer = book.GetPhoneNumber(surname);
    //    if (get<0>(answer).empty())
    //        std::cout << get<1>(answer);
    //    else
    //        std::cout << get<0>(answer);
    //    cout << std::endl;
    //};

    //// вызовы лямбды
    //print_phone_number("Ivanov");
    //print_phone_number("Petrov");

    //std::cout << "----ChangePhoneNumber----" << std::endl;
    //book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
    //    PhoneNumber{ 7, 123, "15344458", std::nullopt });
    //book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
    //    PhoneNumber{ 16, 465, "9155448", 13 });
    //std::cout << book;

    return 0;
}