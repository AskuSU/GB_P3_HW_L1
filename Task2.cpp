#include"Task2.h"

std::ostream& operator<<(std::ostream& out, const PhoneNumber& phNum)
{
	out << "+" << phNum.countryCode << "(" << phNum.cityÑode << ")" << phNum.number;
	if (phNum.extension)
		out << " " << phNum.extension.value();
	return out << std::endl;
}
