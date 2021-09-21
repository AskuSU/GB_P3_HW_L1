#include"Task1.h"


std::ostream& operator<< (std::ostream& out, const Person& person)
{
	out << person.surname << " " << person.first_name;
	if (person.patronymic.has_value())
	{
		out << " " << person.patronymic.value();
	}
	out << std::endl;
	return out;
}

bool operator<(const Person& persL, const Person& persR)
{
	if (persL.surname != persR.surname) return persL.surname < persR.surname;
	if (persL.first_name != persR.first_name) return persL.first_name < persR.first_name;
	if (persL.patronymic.has_value())
	{
		if (persR.patronymic.has_value())
		{
			return persL.patronymic.value() < persR.patronymic.value();
		}
		else return false;
	}
	else return true;
}

bool operator==(const Person& persL, const Person& persR)
{
	if (persL.surname != persR.surname) return false;
	if (persL.first_name != persR.first_name) return false;
	if (!(persL.patronymic.has_value() ^ persR.patronymic.has_value()))
	{
		if (persL.patronymic.has_value()) return persL.patronymic.value() == persR.patronymic.value();
	}
	return false;
}
