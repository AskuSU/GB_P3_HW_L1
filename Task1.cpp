#include "Task1.h"
#include <tuple>
#include <iomanip>


std::ostream& operator<< (std::ostream& out, const Person& person)
{
	out << std::setw(12) << person.surname << " " << std::setw(9) << person.first_name;
	if (person.patronymic.has_value())
	{
		out << " " << std::setw(14) << person.patronymic.value();
	}
	else
	{
		out << "   " << std::setw(15);
	}
	return out;
}

bool operator<(const Person& persL, const Person& persR)
{
	return std::tie(persL.surname, persL.first_name, persL.patronymic) < std::tie(persR.surname, persR.first_name, persR.patronymic);
	/*if (persL.surname != persR.surname) 
		return persL.surname < persR.surname;
	if (persL.first_name != persR.first_name) 
		return persL.first_name < persR.first_name;
	if (persL.patronymic.has_value())
	{
		if (persR.patronymic.has_value())
		{
			return persL.patronymic.value() < persR.patronymic.value();
		}
		else return false;
	}
	else return true;*/
}

bool operator==(const Person& persL, const Person& persR)
{
	return std::tie(persL.surname, persL.first_name, persL.patronymic) == std::tie(persR.surname, persR.first_name, persR.patronymic);
	/*if (persL.surname != persR.surname) 
		return false;
	if (persL.first_name != persR.first_name) 
		return false;
	if (!(persL.patronymic.has_value() ^ persR.patronymic.has_value()))
	{
		if (persL.patronymic.has_value()) return persL.patronymic.value() == persR.patronymic.value();
	}
	return false;*/
}
