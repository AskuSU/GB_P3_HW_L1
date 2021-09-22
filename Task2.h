#pragma once
#include<iostream>
#include<optional>

class PhoneNumber
{
private:	
	uint16_t countryCode, city—ode;
	std::string number;
	std::optional<uint16_t> extension;

public:
	friend std::ostream& operator<< (std::ostream& out, const PhoneNumber& phNum);
};