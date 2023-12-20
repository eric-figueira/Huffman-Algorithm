#include <iostream>

#include "CharCode.h"
#include "Types.h"

CharCode::CharCode() : character(0), code(nullptr), code_size(0) {}

CharCode::CharCode(byte character, bool* code, unsigned int code_size) : character(character), code(code), code_size(code_size) {}

CharCode::~CharCode()
{
	delete[] code;
}

CharCode& CharCode::operator=(const CharCode& other)
{
	delete[] code;
	code = new bool[8];

	for (unsigned int i = 0; i < other.code_size; i++)
	{
		code[i] = other.code[i];
	}

	return *this;
}

byte CharCode::get_char() const { return character; }

bool* CharCode::get_code() const { return code; }

unsigned int CharCode::get_code_size() const { return code_size; }

void CharCode::push_to_code(bool v) {
	code[code_size++] = v;
}

void CharCode::pop_from_code() {
	code[code_size - 1];
	code_size--;
}