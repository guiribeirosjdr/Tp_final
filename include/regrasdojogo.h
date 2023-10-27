#ifndef REGRASDOJOGO_H
#define REGRASDOJOGO_H

#include "tabuleiro.h"

class RegrasDoJogo {
public:
    bool jogadaValida(Tabuleiro& tabuleiro, int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    bool jogoTerminou(Tabuleiro& tabuleiro);
    void promoverPecaADama(Tabuleiro& tabuleiro, int linha, int coluna);
    // Outras regras específicas do jogo...
};

#endif
