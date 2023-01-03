#include <iostream>

enum Example : char
{
	A = 5, B, C
};

int main()
{
	Example value = B;

	if (value == 1)
	{
		// do something
	}

	std::cin.get();
}
