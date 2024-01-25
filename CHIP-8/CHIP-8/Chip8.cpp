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
	for (unsigned int i = 0; i < FONTSET_SIZE; ++i)
	{
		memory[FONTSET_START_ADDRESS + i] = fontset[i];
	}

	// initialize RNG
	randByte = std::uniform_int_distribution<uint8_t>(0, 255U);

	// set up function pointer table
	table[0x0] = &Chip8::Table0;



}