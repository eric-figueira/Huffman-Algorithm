#include "CharCode.h"
#include <iostream>

CharCode::CharCode() : character(0), code(nullptr), code_size(0) {}

CharCode::CharCode(char character, bool* code, unsigned int code_size) : character(character), code(code), code_size(code_size) {}

CharCode::~CharCode()
{
	free(code);
}

char CharCode::get_char() const { return character; }

bool* CharCode::get_code() const { return code; }

unsigned int CharCode::get_code_size() const { return code_size; }

void CharCode::push_to_code(bool v) {
	code[code_size++] = v;
}

void CharCode::pop_from_code() {
	code[code_size - 1];
	code_size--;
}