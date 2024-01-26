#pragma once

#include <cstdint>
#include <random>

const unsigned int KEY_COUNT = 16;
const unsigned int MEMORY_SIZE = 4096;
const unsigned int REGISTER_COUNT = 16;
const unsigned int STACK_LEVELS = 16;
const unsigned int VIDEO_HEIGHT = 32;
const unsigned int VIDEO_WIDTH = 64;

class Chip8
{
public:
	Chip8();
	void LoadROM(char const* filename);
	void Cycle();

	uint8_t keypad[KEY_COUNT]{};
	uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT];

private:
	void Table0();
	void Table8();
	void TableE();
	void TableF();

	// Do nothing
	void OP_NULL();

	// CLS
	void OP_00E0();

	// RET
	void OP_00EE();

	// JP address
	void OP_1nnn();

	// CALL address
	void OP_2nnn();

	// SE Vx, byte
	void OP_3xkk();

	// SNE Vx, byte
	void OP_4xkk();

	// SE Vx, Vy
	void OP_5xy0();

	// LD Vx, byte
	void OP_6xkk();

	// ADD Vx, byte
	void OP_7xkk();

	// LD Vx, Vy
	void OP_8xy0();

	// OR Vx, Vy
	void OP_8xy1();

	// AND Vx, Vy
	void OP_8xy2();

	// XOR Vx, Vy
	void OP_8xy3();

	// ADD Vx, Vy
	void OP_8xy4();

	// SUB Vx, Vy
	void OP_8xy5();

	// SHR Vx
	void OP_8xy6();

	// SUBN Vx, Vy
	void OP_8xy7();

	// SHL Vx
	void OP_8xyE();

	// SNE Vx, Vy
	void OP_9xy0();

	// LD I, address
	void OP_Annn();

	// JP V0, address
	void OP_Bnnn();

	// RND Vx, byte
	void OP_Cxkk();

	// DRW Vx, Vy, height
	void OP_Dxyn();

	// SKP Vx
	void OP_Ex9E();

	// SKNP Vx
	void OP_ExA1();

	// LD Vx, DT
	void OP_Fx07();

	// LD Vx, K
	void OP_Fx0A();

	// LD DT, Vx
	void OP_Fx15();

	// LD ST, Vx
	void OP_Fx18();

	// ADD I, Vx
	void OP_Fx1E();

	// LD F, Vx
	void OP_Fx29();

	// LD B, Vx
	void OP_Fx33();

	// LD [I], Vx
	void OP_Fx55();

	// LD Vx, [I]
	void OP_Fx65();

	uint8_t memory[MEMORY_SIZE];
	uint8_t registers[REGISTER_COUNT];
	uint16_t index{};
	uint16_t pc{};
	uint8_t delayTimer{};
	uint8_t soundTimer{};
	uint16_t stack[STACK_LEVELS]{};
	uint8_t sp{};
	uint16_t opcode{};

	std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;

	// A function pointer is just that—a pointer that 
	// denotes a function rather than an object.
	
	// Like any other pointer, a function pointer points 
	// to a particular type. A function’s type is determined 
	// by its return type and the types of its parameters.
	// The function’s name is not part of its type. For example:
	// compares lengths of two strings
	// 	bool lengthCompare(const string &, const string &);
	// has type bool(const string&, const string&). To declare 
	// a pointer that can point at this function, we declare 
	// a pointer in place of the function name:
	// pf points to a function returning bool that takes 
	// two const string references
	// 	bool (*pf)(const string &, const string &); // uninitialized

	// As we’ve just seen in the declaration of .., writing 
	// function pointer types quickly gets tedious. Type 
	// aliases, along with decltype(return type) , let us 
	// simplify code that uses function pointers:
	
	// Chip8Func pointer declation to a method of the Chip8 class
	// that return void and has an empty parametr list. At this point, 
	// you don't know the exact method you want to call. You've only 
	// declared a pointer to some arbitrary Chip8 method. Typedef gives 
	// opportunity to use later only Chip8Func without all declation of this.
	// It's function pointer to a class method- "pointer-to-member-function"
	typedef void (Chip8::*Chip8Func)();
	// "table" array and etc. of Chip8Func type pointers
	// to the func that will return void and has no parameters
	Chip8Func table[0xF + 1];
	Chip8Func table0[0xE + 1];
	Chip8Func table8[0xE + 1];
	Chip8Func tableE[0xE + 1];
	Chip8Func tableF[0x65 + 1];

};