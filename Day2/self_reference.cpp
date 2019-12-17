#include <iostream>

using namespace std;


template <typename T>
class Thing
{
public:
	Thing(): data(T()), otherThing(nullptr){}
	
	Thing(T d): data(d), otherThing(nullptr){}
	
	T getData()
	{
		return data;
	}
	
	void setData(T d)
	{
		data = d;
	}

	Thing<T>* getOtherThing()
	{
		return otherThing;
	}

	void setOtherThing(Thing<T>* ot)
	{
		otherThing = ot;
	}
private:
	T data;
	Thing<T>* otherThing;
};

int main()
{
	Thing<int> t1(1);
	Thing<int> t2(2);
	Thing<int> t3(3);
	t1.setOtherThing(&t2);
	t2.setOtherThing(&t3);

	Thing<int>* item = &t1;
	while (item)
	{
		cout << item->getData() << endl;
		item = item->getOtherThing();
	}

	return 0;
}