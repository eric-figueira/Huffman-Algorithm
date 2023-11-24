#include "CharCode.h"

CharCode::CharCode(): character(NULL), code(NULL) {}

CharCode::CharCode(char character, bool* code, unsigned int code_size): character(character), code(code), code_size(code_size) {}

char CharCode::get_char() const { return character; }

bool* CharCode::get_code() const { return code; }

unsigned int CharCode::get_code_size() const { return code_size; }