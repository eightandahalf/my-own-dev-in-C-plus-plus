#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;

	Vector3()
		: x(10), y(11), z(12) {}
};

int main()
{
	int value = 5; // stack allocated
	int array[5]; // array allocated for 5 elements in a stack
	array[0] = 255;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;
	Vector3 vector;

	int* hvalue = new int; // heap allocated 
	*hvalue = 5;
	int* harray = new int[5]; // array allocated in the heap
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;
	Vector3* hvector = new Vector3();

	delete hvalue;
	delete[] harray;
	delete hvector;

	std::cin.get();
}