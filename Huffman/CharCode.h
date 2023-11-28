#ifndef CHARCODE
#define CHARCODE

class CharCode {
private:
    char character;
    bool* code;
    unsigned int code_size;

public:
    CharCode();
    CharCode(char character, bool* code, unsigned int code_size);

    char get_char() const;
    bool* get_code() const;
    unsigned int get_code_size() const;

    void push_to_code(bool v);
    void pop_from_code();
};

#endif