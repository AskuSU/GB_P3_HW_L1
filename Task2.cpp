#include"Task2.h"

std::ostream& operator<<(std::ostream& out, const PhoneNumber& phNum)
{
	out << "+" << phNum.countryCode << "(" << phNum.city�ode << ")" << phNum.number;
	if (phNum.extension)
		out << " " << phNum.extension.value();
	return out;
}

bool operator<(const PhoneNumber& phNumL, const PhoneNumber& phNumR)
{
	return std::tie(phNumL.countryCode, phNumL.city�ode, phNumL.number, phNumL.extension) < std::tie(phNumR.countryCode, phNumR.city�ode, phNumR.number, phNumR.extension);
}
