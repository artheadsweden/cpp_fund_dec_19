#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;

int main()
{
	//int x = 0;
	atomic<int> x = 0;
	auto worker = [&x]()
	{
		for (int i = 0; i < 40'000'000; i++)
		{
			x++;
		}
	};
	
	auto start = chrono::system_clock::now();
	thread t1(worker);
	thread t2(worker);
	thread t3(worker);
	thread t4(worker);
	thread t5(worker);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	auto end = chrono::system_clock::now();
	auto diff = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "Result = " << x << endl;
	cout << "It too " << diff << " milliseconds" << endl;

	return 0;
}