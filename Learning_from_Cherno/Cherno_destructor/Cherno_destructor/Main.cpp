#include <iostream>

class Entity
{
public:
	float X, Y;

	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
		std::cout << "Created Entity" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity" << std::endl;
	}

	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};

void Function()
{
	Entity A;
	A.Print();
}
int main()
{
	Function();
	std::cin.get();
}