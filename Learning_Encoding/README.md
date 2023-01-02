### Learning how to print Cyrillic symbols in console
So, I've was writing one project and face with interesting problem.
This problem consists in how to "printing Cyrillic symbols in Visual Studio console".
I learn a lot of information about encoding, utf-8, ascii and etc.
And to solve my problem I compile several answers to another problems.
So, to "printing Cyrillic symbols in Visual Studio console" I use "freopen" function that reuses stream to either open the file specified by filename or to 
change its access mode. And that function I use because we can'not use std::cout and std::wcout together. But I should use both this objects, because when I
wanna get Cyrillic symbols from console, I will use "wchar" data type, because it can store Cyrillic symbols from utf-8, while "char" data type can't. 
And at first time, when I wanna to get Cyrillic symbols from user, I will use "wchar" data type and stream that will process std::wcout; so, at another time, when 
I decided to go back to using std::cout, I will use freopen again and can use the char data type and display it with std::cout.
### P.S. I'm using VS2022
