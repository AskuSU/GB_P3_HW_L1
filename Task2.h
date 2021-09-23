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
	PhoneNumber(uint16_t couC, uint16_t citC, const std::string& num, const std::optional<uint16_t>& ext) : countryCode(couC), city—ode(citC), number(num), extension(ext)
	{};

	friend bool operator< (const PhoneNumber& phNumL, const PhoneNumber& phNumR);
	friend std::ostream& operator<< (std::ostream& out, const PhoneNumber& phNum);
};