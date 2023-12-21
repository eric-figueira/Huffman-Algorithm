#ifndef CHARCODE
#define CHARCODE

#include "Types.h"

using namespace std;

class CharCode {
    private:
        byte character;
        bool* code;
        unsigned int code_size;

    public:
        CharCode();
        CharCode(byte character, bool* code, unsigned int code_size);
        ~CharCode();

        CharCode& operator=(const CharCode& other);

        byte get_char() const;
        bool* get_code() const;
        unsigned int get_code_size() const;

        void push_to_code(bool v);
};

#endif