#include <iostream>

class Entity
{
public:
	float X, Y;

	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
	}
	
	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}

	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};

class Log
{
private:
	//Log() {}
public:
	//Log() {};
	Log() = delete;
	static void write()
	{

	}
};


int main()
{
	Log::write();
	Log l;

	Entity A(10.0f, 3.0f);
	A.Print();
	std::cin.get();
}