#include <iostream>
#include <string>
#include "Stack.h"

int main()
{
	Stack<std::string> history;

	while (true)
	{
		std::cout << "1. Visit a website \n";
		std::cout << "2. Go back\n";
		std::cout << "3. Go forward\n";
		std::cout << "4. Exit\n";
		std::cout << "Enter your choice: ";
		int choice;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			std::string website;
			std::cout << "Enter website URL: ";
			std::cin >> website;
			history.push(website);
			std::cout << "Visited: " << website << std::endl;
			break;
		}
		case 2:
		{
			if (!history.isEmpty())
			{
				std::string back = history.pop();
				std::cout << "Going back to: " << back << std::endl;
			}
			else
			{
				std::cout << "No previous pages\n";
			}
			break;
		}
		case 3:
		{
			if (!history.isForwardEmpty())
			{
				std::string forward = history.popForward();
				std::cout << "Going forward to: " << forward << std::endl;
			}
			else
			{
				std::cout << "No forward pages\n";
			}
			break;
		}
		case 4:
		{
			std::cout << "Exiting...\n";
			return 0;
		}
		default:
		{
			std::cout << "Invalid choice. Please try again.\n";
		}
		}
	}
	return 0;
}