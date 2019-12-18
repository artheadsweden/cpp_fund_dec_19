#include <iostream>
#include "Temperature.h"
using namespace std;


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

