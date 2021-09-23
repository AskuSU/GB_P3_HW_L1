#include "Task3.h"
#include <string>
#include <algorithm>
#include <iomanip>

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

void PhoneBook::SortByPhone()
{
	Less less(true);
	std::sort(record.begin(), record.end(), less);
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& surname)
{
	PhoneNumber number;
	std::string res = "";
	uint8_t count = 0;
	std::for_each(record.begin(), record.end(),
		[&](const auto& rec)
		{
			if (rec.first.getSurname() == surname)
			{
				number = rec.second;
				count++;
			}
		});
	if (count == 0) res = "not found";
	else if (count > 1) res = "found more than 1";
	return std::make_tuple(res, number);
}

void PhoneBook::ChangePhoneNumber(const Person& person, const PhoneNumber& phNum)
{
}

std::ostream& operator<<(std::ostream& out, PhoneBook phBook)
{	
	for (const auto& [person, number] : phBook.record)
	{
		out << person << std::setw(5) << number << std::endl;
	}
	return out;
}
