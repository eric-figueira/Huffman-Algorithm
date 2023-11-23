using namespace std;

class Classe: ofstream {
    private:
        unsigned char n_used_bits = 0;
        unsigned char bits; // 0 bits significativos

    public:
        // reimplementar
        // passa bits até formar um byte (8 bits), grava no arquivo e zera o contador de bits
        // quando você manda escrever ele não escreve de verdade até formar 8
        ostream& operator<< (streambuf* sb );
};