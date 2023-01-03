#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

int main()
{
	int a = 5;
	int* b = new int;
	Entity* e = new Entity();
	Entity* e = (Entity*)malloc(sizeof(Entity));
	std::cout << (*e).GetName() << std::endl;
	std::cout << sizeof(Entity) << std::endl;
	delete b;
	delete e;
	std::cin.get();
}