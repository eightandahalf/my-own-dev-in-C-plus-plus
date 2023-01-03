#include <iostream>

struct Entity
{
	static int x, y;

	static void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

int Entity::x;
int Entity::y;

int main()
{
	Entity e;
	Entity::x = 2;
	Entity::y = 3;
		
	Entity e1;
	Entity::x = 5;
	Entity::y = 8;

	Entity::Print();
	Entity::Print();
	std::cin.get();
}