#include <iostream>

class Entity
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};

class Player : public Entity
{
	const char* Name;

	void PrintName()
	{
		std::cout << Name << std::endl;
	}
};

int main()
{
	Player player;
	player.Move(5, 5);

	std::cout << sizeof(Player);

	std::cin.get();
}