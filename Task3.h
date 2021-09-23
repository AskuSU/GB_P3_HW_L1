#pragma once
#include"Task1.h"
#include"Task2.h"

#include<vector>
#include<fstream>

class PhoneBook
{
private:
	std::vector<std::pair<Person, PhoneNumber>> record;

public:
	PhoneBook(std::ifstream& fstr);

	void SortByName();

	friend std::ostream& operator<< (std::ostream& out, PhoneBook phBook);
};

class Less
{
public:
	bool operator() (const std::pair<Person, PhoneNumber>& left, const std::pair<Person, PhoneNumber>& right)
	{
		if (left.first == right.first)
			return left.second < right.second;
		else return left.first < right.first;
	}
};
