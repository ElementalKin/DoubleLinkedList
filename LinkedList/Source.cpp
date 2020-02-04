#include "tList.h"
#include <iostream>
int main()
{
	tList<int> h;
	int e = 4;
	h.push_front(0);
	h.push_front(1);
	h.push_front(2);
	h.push_front(3);
	h.push_front(4);
	h.push_front(5);
	h.push_front(6);
	h.push_front(7);
	h.push_front(8);
	std::cout << h.front() << std::endl;
	while (true)
	{
		
	}
	return 0;
}