#ifndef CHARCODE
#define CHARCODE


using namespace std;

class CharCode {
    private:
        unsigned char character;
        bool* code;
        unsigned int code_size;

    public:
        CharCode();
        CharCode(unsigned char character, bool* code, unsigned int code_size);

        unsigned char get_char() const;
        bool* get_code() const;
        unsigned int get_code_size() const;

        void push_to_code(bool v);
        void pop_from_code();
};

#endif