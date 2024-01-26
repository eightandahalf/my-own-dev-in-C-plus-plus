#include "Chip8.hpp"
#include <chrono>
#include <cstdint>
#include <csring>
#include <fstream>
#include <random>

const unsigned int FONTSET_SIZE = 80;
const unsigned int FONTSET_START_ADDRESS = 0x50;
const unsigned int START_ADDRESS = 0x200;

uint8_t fontset[FONTSET_SIZE] = 
{
	0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

// member randGen of class Chip8 must be initialised, 
// but since it's missing  from the constructor, 
// we must initialise is as "Chip8::Chip8() : randGen(...)"
// in book "Lippman S., Lajoie J., Moo B. - C++ Primer - 2012" 
// on page 289 there is explanation of that situation.
// This line 
// "std::chrono::system_clock::now().time_since_epoch().count()" 
// means amount of hours from start of epoch
Chip8::Chip8() : randGen(std::chrono::system_clock::now().time_since_epoch().count())
{
	// initialize pc
	pc = START_ADDRESS;
	
	// load fonts into memory
	for(unsigned int i = 0; i < FONTSET_SIZE; ++i)
	{
		memory[FONTSET_START_ADDRESS + i] = fontset[i];
	}
	
	// initialize RNG
	randByte = std::uniform_int_distribution<uint8_t>(0, 255U);
	
	// set up function pointer table
	table[0x0] = &Chip8::Table0;
	table[0x1] = &Chip8::OP_1nnn;
	table[0x2] = &Chip8::OP_2nnn;
	table[0x3] = &Chip8::OP_3xkk;
	table[0x4] = &Chip8::OP_4xkk;
	table[0x5] = &Chip8::OP_5xy0;
	table[0x6] = &Chip8::OP_6xkk;
	table[0x7] = &Chip8::OP_7xkk;
	table[0x8] = &Chip8::Table8;
	table[0x9] = &Chip8::OP_9xy0;
	table[0xA] = &Chip8::OP_Annn;
	table[0xB] = &Chip8::OP_Bnnn;
	table[0xC] = &Chip8::OP_Cxkk;
	table[0xD] = &Chip8::OP_Dxyn;
	table[0xE] = &Chip8::TableE;
	table[0xF] = &Chip8::TableF;
	
	for(size_t i = 0; i <= 0xE; i++)
	{
			table0[i] = &Chip8::OP_NULL;
			table8[i] = &Chip8::OP_NULL;
			tableE[i] = &Chip8::OP_NULL;		
	}
	
	table0[0x0] = &Chip8::OP_00E0;
	table0[0xE] = &Chip8::OP_00EE;
	
	table8[0x0] = &Chip8::OP_8xy0;
	table8[0x1] = &Chip8::OP_8xy1;
	table8[0x2] = &Chip8::OP_8xy2;
	table8[0x3] = &Chip8::OP_8xy3;
	table8[0x4] = &Chip8::OP_8xy4;
	table8[0x5] = &Chip8::OP_8xy5;
	table8[0x6] = &Chip8::OP_8xy6;
	table8[0x7] = &Chip8::OP_8xy7;
	table8[0xE] = &Chip8::OP_8xyE;
	
	tableE[0x1] = &Chip8::OP_ExA1;
	tableE[0xE] = &Chip8::OP_Ex9E;
	
	for(size_t i = 0; i <= 0x65; i++)
	{
		tableF[i] = &Chip8::OP_NULL;
	}
	
	tableF[0x07] = &Chip8::OP_Fx07;
	tableF[0x0A] = &Chip8::OP_Fx0A;
	tableF[0x15] = &Chip8::OP_Fx15;
	tableF[0x18] = &Chip8::OP_Fx18;
	tableF[0x1E] = &Chip8::OP_Fx1E;
	tableF[0x29] = &Chip8::OP_Fx29;
	tableF[0x33] = &Chip8::OP_Fx33;
	tableF[0x55] = &Chip8::OP_Fx55;
	tableF[0x65] = &Chip8::OP_Fx65;
}

void Chip8::LoadROM(char const* filename)
{
	// std::ifstream is "input file stream object" of name "file"
	// with file modes binary + ate. real file that will connect
	// to this object must located in "char const* filename".
	// binary means to open file in binary mode; ate means to 
	// set the initial position at the end of the file.
	// if this flag is not set to any value, the inital 
	// position is the beginning of the file
	std::ifstream file(filename, std::ios::binary | std::ios::ate);
	
	if(file.is_open())
	{
		// "size" determine size of a file.
		// tellg returns the position of the current 
		// character in the input stream.
		// ate that we previously write open 
		// and seek to end immediately after opening
		std::streampos size = file.tellg();
		char* buffer = new char[size];
		
		// seekg repositions the marker by 
		// seeking to a given position. g = getting/reading.
		//
		// seekg(offset, from)
		// Reposition the marker for an input stream integral number
		// offset characters ahead or behind from. from can be one of
		// • beg, seek relative to the beginning of the stream
		// • cur, seek relative to the current position of the stream
		// • end, seek relative to the end of the stream
		//
		file.seekg(0, std::ios::beg);
		file.read(buffer, size);
		file.close();
		
		for(long i = 0; i < size; ++i)
		{
			memory[START_ADDRESS + i] = buffer[i];
		}
		
		delete[] buffer;
	}
}


	