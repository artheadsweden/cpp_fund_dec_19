#pragma once
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
