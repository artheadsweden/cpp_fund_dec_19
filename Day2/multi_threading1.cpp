#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void worker()
{
	for (int i = 0; i < 10; i++)
	{
		cout << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

int main()
{
	thread t1(worker);
	thread t2(worker);
	t1.join();
	t2.join();
	return 0;
}