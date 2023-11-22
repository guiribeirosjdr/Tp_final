#ifndef PECA_H
#define PECA_H
#include <string>

using namespace std;

enum Cor {
    PRETA, VERMELHA
};

class Peca {
private:
    Cor cor;
    bool dama;

public:
    Peca(Cor cor);
    Cor getCor() const;
    bool isDama() const;
    void promoverDama();
};

#endif
