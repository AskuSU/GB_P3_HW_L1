#pragma once
#include<optional>
#include<iostream>


class Person
{
	std::string surname, first_name;
	std::optional<std::string>	patronymic;

public:
	friend std::ostream& operator<< (std::ostream& out, const Person& person);
	friend bool operator< (const Person& persL, const Person& persR);
	friend bool operator== (const Person& persL, const Person& persR);
};