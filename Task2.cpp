#include"Task2.h"

std::ostream& operator<<(std::ostream& out, const PhoneNumber& phNum)
{
	out << "+" << phNum.countryCode << "(" << phNum.cityÑode << ")" << phNum.number;
	if (phNum.extension)
		out << " " << phNum.extension.value();
	return out;
}

bool operator<(const PhoneNumber& phNumL, const PhoneNumber& phNumR)
{
	return std::tie(phNumL.countryCode, phNumL.cityÑode, phNumL.number, phNumL.extension) < std::tie(phNumR.countryCode, phNumR.cityÑode, phNumR.number, phNumR.extension);
}
