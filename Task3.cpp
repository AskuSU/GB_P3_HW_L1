#include"Task3.h"
#include<string>

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
		while (fstr >> surname >> first_name >> patronymic.value() >> countryCode >> city—ode >> number >> ext.value())
		{
			if (patronymic.has_value())
				if (patronymic.value() == "-")
					patronymic = std::nullopt;
			Person person(surname, first_name, patronymic);
			if (ext.has_value())
				if (ext.value() == "-")
					extension = std::nullopt;
				else
					extension.value() = std::stoi(ext.value());

			PhoneNumber phoneNum(countryCode, city—ode, number, extension);

			record.push_back(std::make_pair(person, phoneNum));
		}
	}
	fstr.close();
}
