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

	friend std::ostream& operator<< (std::ostream& out, PhoneBook phBook);
};
