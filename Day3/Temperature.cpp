#include "Temperature.h"


Temperature::Temperature() : temp(0.0) {}

Temperature::Temperature(float t) : temp(t) {}

Temperature::Temperature(const Temperature& other) : temp(other.temp) {}

float Temperature::getFarenheit() const
{
	return temp * 9 / 5 + 32;
}

float Temperature::getCelsius()
{
	return temp;
}

void Temperature::set_temp(float t)
{
	temp = t;
}

Temperature Temperature::operator +(const Temperature& other)
{
	return Temperature(temp + other.temp);
}

Temperature Temperature::operator -(const Temperature& other)
{
	return Temperature(temp - other.temp);
}

Temperature Temperature::operator *(const Temperature& other)
{
	return Temperature(temp * other.temp);
}

Temperature Temperature::operator /(const Temperature& other)
{
	return Temperature(temp / other.temp);
}


Temperature& Temperature::operator ++()
{
	++temp;
	return *this;
}

const Temperature& Temperature::operator ++(int)
{
	Temperature oldTemp(*this);
	++(*this);
	return oldTemp;
}

Temperature operator +(const float& first, const Temperature& other)
{
	return Temperature(first + other.temp);
}

ostream& operator <<(ostream& os, const Temperature& other)
{
	os << other.temp << "C " << other.getFarenheit() << "F ";
	return os;
}

