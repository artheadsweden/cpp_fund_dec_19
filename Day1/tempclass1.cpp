#include <iostream>

using namespace std;

class Temperature
{
public:
	Temperature();
	Temperature(float t);
	Temperature(const Temperature& other);
	float getFarenheit();
	float getCelsius();
	void set_temp(float f);
	Temperature operator +(const Temperature& other);
private:
	float temp;
};

Temperature::Temperature(): temp(0.0){}

Temperature::Temperature(float t): temp(t){}

Temperature::Temperature(const Temperature& other): temp(other.temp){}

float Temperature::getFarenheit()
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

int main()
{
	Temperature t1(12.4f);
	Temperature t2(15.6f);
	Temperature t3 = t1 + t2;
	Temperature t4 = t1 + 4.5;
	Temperature t5 = 4.5f + t1;

	cout << t3.getCelsius() << " " << t3.getFarenheit() << endl;
	return 0;
}