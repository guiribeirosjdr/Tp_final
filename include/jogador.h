#ifndef JOGADOR_H
#define JOGADOR_H

#include "tabuleiro.h"

class Jogador {
private:
    Cor cor;
public:
    Jogador(Cor cor);
    Jogada realizarJogada(Tabuleiro& tabuleiro);
};

#endif
