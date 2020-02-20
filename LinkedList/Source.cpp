#include "tList.h"
#include <iostream>
int main()
{
	//currently can't interact with the linked lists functions need to work on that.
	tList<int> h;
	std::string answer;
	int response = 0;
	while (true)
	{
		std::cout << "Do you want to [1] check whats in the list, [2] add to the list, [3] remove from the front of the list, \n[4] resize the list, [5] sort the list, [6] clear the list, [7] check if its empty, [8] get info on the head or tail" << std::endl;
		std::cin >> response;
		if(response == 1)
		{
			h.Display();
		}
		else if(response == 2)
		{
			std::cout << "Do you want to [1] add to the front or [2] the back." << std::endl;
			std::cin >> response;
			if(response == 1)
			{
				std::cout << "how much do you want to add." << std::endl;
				std::cin >> response;
				h.push_front(response);
			}
			else if(response == 2)
			{
				std::cout << "how much do you want to add to this node." << std::endl;
				std::cin >> response;
				h.push_back(response);
			}
			else
			{
				std::cout << "please enter 1-2 to respond" << std::endl;
			}
		}
		else if (response == 3)
		{
			std::cout << "Do you want to [1] remove to the front or [2] the back." << std::endl;
			std::cin >> response;
			if (response == 1)
			{
				h.pop_front();
			}
			else if (response == 2)
			{
				h.pop_back();
			}
			else
			{
				std::cout << "please enter 1-2 to respond" << std::endl;
			}
		}
		else if (response == 4)
		{
			std::cout << "what do you want the new size to be?" << std::endl;
			std::cin >> response;
			h.resize(response);
		}
		else if (response == 5)
		{
			std::cout << "Do you want to [1] sort it ascending to the front or [2] decending." << std::endl;
			std::cin >> response;
			if (response == 1)
			{
				h.sortAscending();
			}
			else if (response == 2)
			{
				h.sortDescending();
			}
			else
			{
				std::cout << "please enter 1-2 to respond" << std::endl;
			}
		}
		else if (response == 6)
		{
			h.clear();
		}
		else if (response == 7)
		{
			if(h.empty())
			{
				std::cout << "True" << std::endl;
			}
			else
			{
				std::cout << "False" << std::endl;
			}
		}
		else if (response == 8)
		{
			std::cout << "Do you want to [1] info on the head or [2] tail." << std::endl;
			std::cin >> response;
			if (response == 1)
			{
				std::cout << h.front() << std::endl;
			}
			else if (response == 2)
			{
				std::cout << h.back() << std::endl;
			}
			else
			{
				std::cout << "please enter 1-2 to respond" << std::endl;
			}
		}
		else 
		{
			std::cout << "please enter 1-5 to respond" << std::endl;
		}

	}
	return 0;
}
void printTList(tList<int> h)
{
	
}