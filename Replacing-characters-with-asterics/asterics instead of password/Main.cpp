#include "defines_+_includes.h"

enum ascii_values{
	BACK_SPACE = 8,
	CAR_RETURN = 13
};

std::string UserAutentificationData()
{
	char ch;
	std::string data;
	bool loop = true;
	while (loop)
	{
		ch = _getch();
		if ((int)ch == 0)
		{
			ch = _getch();
			switch (ch) {
			case KEY_F1: continue; // f1
			case KEY_F2: continue; // f2
			case KEY_F3: continue; // f3
			case KEY_F4: continue; // f4
			case KEY_F5: continue; // f5
			case KEY_F6: continue; // f6
			case KEY_F7: continue; // f7
			case KEY_F8: continue; // f8
			case KEY_F9: continue; // f9
			case KEY_F10: continue; // f10
			default: continue;
			}
		}
		if ((int)ch == -32) // navigation keys
		{
			ch = _getch();
			switch (ch) {
			case KEY_UP: continue; // up
			case KEY_DOWN: continue; // down
			case KEY_LEFT: continue; // left
			case KEY_RIGHT: continue; // right
			case KEY_DELETE: continue; // delete
			case KEY_INS: continue; // right
			case KEY_PRTSC: continue; // delete
			default: continue;
			}
		}
		else if ((int)ch == KEY_ESCAPE || (int)ch == KEY_SPACE || (int)ch == KEY_TAB) // escape, space, tab
		{
			continue;
		}
		else if (ch == BACK_SPACE && data.size() != 0) // you enter backspace and size of string not equal to zero
		{
			std::cout << "\b \b";
			data.pop_back();
		}
		else if (ch == BACK_SPACE && data.size() == 0) // you enter backspace and size of string equl to zero
		{
			continue;
		}
		else if (ch == CAR_RETURN) // you enter enter
		{
			std::cout << std::endl;
			return data;
		}
		else
		{
			data.push_back(ch);
			std::cout << '*';
		}
	}
	return data;	
}

int main()
{
	std::string login, password;

	std::cout << "login: " << std::endl;
	login = UserAutentificationData();
	std::cout << "Your login: " << login << std::endl;

	std::cout << "password: " << std::endl;
	password = UserAutentificationData();
	std::cout << "Your password: " << password << std::endl;

	/*char ch; // to check acscii value of keys like up_arrow, down_arrow.., f1, f2.., esc, space, tab..
	ch = _getch();
	std::cout << (int)ch << std::endl;
	ch = _getch();
	std::cout << (int)ch << std::endl;*/

	std::cin.get();
}