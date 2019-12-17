#include <iostream>

using namespace std;

class Temperature
{
public:
	Temperature();
	Temperature(float t);
	Temperature(const Temperature& other);
	float getFarenheit() const;
	float getCelsius();
	void set_temp(float f);
	Temperature operator +(const Temperature& other);
	Temperature operator -(const Temperature& other);
	Temperature operator *(const Temperature& other);
	Temperature operator /(const Temperature& other);
	Temperature& operator ++();     //Prefix
	const Temperature& operator ++(int);	//Postfix
	friend Temperature operator +(const float& first, const Temperature& other);
	friend ostream& operator <<(ostream& os, const Temperature& other);
private:
	float temp;
};

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

int main()
{
	Temperature t1(12.4f);
	Temperature t2(15.6f);
	Temperature t3 = t1 / t2;
	Temperature t4 = t1 + 4.5;
	Temperature t5 = 4.5f + t1;
	t1++;

	cout << t1 << " " << t1.getFarenheit() << endl;
	return 0;
}