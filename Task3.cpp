#include "Task3.h"
#include <string>
#include <algorithm>

PhoneBook::PhoneBook(std::ifstream& fstr)
{
	std::string surname, first_name;
	std::optional<std::string>	patronymic;
	uint16_t countryCode, city—ode;
	std::string number;
	std::optional<std::string> ext;
	std::optional<uint16_t> extension;
	
	if (fstr.is_open())
	{
		while (fstr >> surname >> first_name >> patronymic.emplace() >> countryCode >> city—ode >> number >> ext.emplace())
		{
			if (patronymic.has_value())
				if (patronymic.value() == "-")
					patronymic = std::nullopt;
			Person person(surname, first_name, patronymic);
			if (ext.has_value())
				if (ext.value() == "-")
					extension = std::nullopt;
				else
					extension.emplace() = std::stoi(ext.value());

			PhoneNumber phoneNum(countryCode, city—ode, number, extension);

			record.push_back(std::make_pair(person, phoneNum));
		}
	}
	fstr.close();
}

void PhoneBook::SortByName()
{
	Less less;
	std::sort(record.begin(), record.end(), less);
}

std::ostream& operator<<(std::ostream& out, PhoneBook phBook)
{	
	for (auto& rec : phBook.record)
	{
		out << rec.first << "   " << rec.second << std::endl;
	}
	return out;
}
