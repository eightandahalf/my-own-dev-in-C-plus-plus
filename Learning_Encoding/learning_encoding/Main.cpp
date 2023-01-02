//----------------------------------------------------------------------//
//                                                                      //
//      First of all I set up:                                          //
//      "source-charset:utf-8 /execution-charset:utf-8"                 //
//      in the Properties of the project by clicking on C/C++ and       //
//      selecting Command Line to encode the source and executable      //
//      files as utf-8                                                  //
//                                                                      //
//----------------------------------------------------------------------//
#pragma warning(disable:4996)
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <cstdio>
#include <conio.h>

int main(void)
{
	//(void)_setmode(_fileno(stdout), _O_U8TEXT);
	//
	// (void), as I don't need the return value, because I can ignore that
	//
	// _setmode - set the file translation mode;
	// syntax: int _setmode(int fd, in mode);
	// fd - file descriptor, in our case we use _fileno to gets the 
	// file descriptor associated with a stream;
	// mode - new translation mode, in our case utf-8.
	// 
	// In general, we use _setmode to modify the default
	// translation mode of stdout(standart output) to
	// Unicode.
	// 
	// Cyrillic characters will appear on the console 
	// (if our console font supports those character sets)	// 
	//
	/*const wchar_t* unicode_text = L"aäbcdefghijklmnoöpqrsßtuüvwxyz";
	wprintf(L"%s", unicode_text);

	wprintf(L"\n\x043a\x043e\x0448\x043a\x0430 \x65e5\x672c\x56fd\n");

	std::wcout << L"привет малыш";

	std::wcout << L"\nЗдравствуйте. Используйте для ввода 10-и символов русские буквы, цифры, пробелы, либо запятые: " << std::endl;

	int i = -1;
	wchar_t data[10];
	do
	{
		i++;
		data[i] = _getwch();

		if ((data[i] >= 1040 && data[i] <= 1103) || (data[i] == 44) || (data[i] >= 49 && data[i] <= 58) || (data[i] == 32))
		{
			std::wcout << data[i];
		}
		else if (data[i] == 13) { break; }
		else { i--; continue; }
	} while (i < 9);

	std::wcout << L"\nОтлично, теперь посмотрим, что у Вас получилось: " << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::wcout << data[i];
	}

	std::wcout << L"\nА теперь нажмите Enter, чтобы завершить программу: " << std::endl;*/

	/*unsigned char data = 'а';

	std::cout << (int)data;*/

	//const char a = 'п';
	//const char b = 'р';
	//const char c = 'и';
	//const char d = 'в';
	//const char e = 'е';

	//std::cout << int(a) << " " << int(b) << " " << int(c) << " " << int(d) << " " << int(e) << std::endl;

	/*const char a = -8;
	const char b = -7;
	const char c = -6;
	const char d = -4;
	const char e = -3;*/
	//const wchar_t* a = L"ыплфдыопыф";
	//std::wcout << a;

	//char data[5];
	//int i = -1;
	//do
	//{
	//	i++;
	//	unsigned char a = _getch();
	//	data[i] = a;

	//	if ((data[i] >= -64 && data[i] <= -1) || (data[i] == 44) || (data[i] >= 49 && data[i] <= 58) || (data[i] == 32))
	//	{
	//		std::wcout << data[i];
	//	}
	//	else if (data[i] == '\b' && i == 0) { i--; continue; }
	//	else if (data[i] == '\b' && i != 0) { std::wcout << "\b \b"; } // be secure with this line
	//	else if (data[i] == 13) { break; }
	//	else { i--; continue; }
	//} while (i < 24);
	/*const char* name;

	int mode = fwide(stdout, 0);
	std::cout << "0.mode = " << mode << std::endl;
	name = "хелло";
	std::cout << name << std::endl;
	mode = fwide(stdout, 0);

	std::cout << "1.mode = " << mode << std::endl;

	(void)freopen("", "w", stdout);
	setlocale(LC_ALL, "en_US.UTF-8");

	mode = fwide(stdout, 0);
	std::cout << "2.mode = " << mode << std::endl;
	const wchar_t* surname = L"ппривет";
	std::wcout << surname << std::endl;
	{
		int i = -1;
		wchar_t data[10];
		do
		{
			i++;
			data[i] = _getwch();

			if ((data[i] >= 1040 && data[i] <= 1103) || (data[i] == 44) || (data[i] >= 49 && data[i] <= 58) || (data[i] == 32))
			{
				std::wcout << data[i];
			}
			else if (data[i] == 13) { break; }
			else { i--; continue; }
		} while (i < 9);

		std::wcout << L"\nОтлично, теперь посмотрим, что у Вас получилось: " << std::endl;

		for (int i = 0; i < 10; i++)
		{
			std::wcout << data[i];
		}
	}
	mode = fwide(stdout, 0);
	std::cout << "3.mode = " << mode << std::endl;

	(void)freopen("", "w", stdout);

	mode = fwide(stdout, 0);
	std::cout << "4.mode = " << mode << std::endl;
	std::cout << "пока" << std::endl;

	{
		int i = -1;
		char data[10];
		do
		{
			i++;
			data[i] = _getwch();

			if ((data[i] >= 65 && data[i] <= 122) || (data[i] == 44) || (data[i] >= 49 && data[i] <= 58) || (data[i] == 32))
			{
				std::cout << data[i];
			}
			else if (data[i] == 13) { break; }
			else { i--; continue; }
		} while (i < 9);

		std::cout << "\nОтлично, теперь посмотрим, что у Вас получилось: " << std::endl;

		for (int i = 0; i < 10; i++)
		{
			std::cout << data[i];
		}
	}

	mode = fwide(stdout, 0);
	std::cout << "5.mode = " << mode << std::endl;*/
	int order_num = 1;
	int amount_bytes = 30;
	wchar_t data[30];
#undef max
	(void)freopen("", "w", stdout);
	setlocale(LC_ALL, "en_US.UTF-8");
	//if (order_num == 1)
	//{
	//	std::wcin.clear();
	//	std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//}

	int i = -1;
	do
	{
		i++;
		data[i] = _getwch();

		if ((data[i] >= 1040 && data[i] <= 1103) || (data[i] == 44) || (data[i] >= 49 && data[i] <= 58) || (data[i] == 32))
		{
			std::wcout << data[i];
		}
		else if (data[i] == '\b' && i == 0) { i--; continue; }
		else if (data[i] == '\b' && i != 0) { std::wcout << "\b \b"; } // be secure with this line
		else if (data[i] == 13) { break; }
		else { i--; continue; }
	} while (i < 29);

	int j = 0;
	while (j < i)
	{
		std::wcout << data[j];
		j++;
	}

	std::wcout << L".sdgjasldgjlaskdjglksadjglk";
	(void)freopen("", "w", stdout);
	std::cout << "\n\nhahhaha";
	const char* s0 = "sdfsdf";
	std::cout << s0;

	std::cin.get();
	return 0;
}
