#include <iostream>
#include <vector>
#include <string>

char* GetName()
{
	return "Cherno";
}

int main()
{
	auto name = GetName();
	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");
	strings.push_back("Juice");

	for (std::vector<std::string>::iterator it = strings.begin();
		it < strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cin.get();
}