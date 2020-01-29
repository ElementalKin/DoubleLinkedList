#include "tList.h"
#include <iostream>
int main()
{
	tList<int> h;
	int e = 4;
	h.push_front(e);
	h.pop_front();
	std::cout << h.front() << std::endl;
	while (true)
	{
		
	}
	return 0;
}