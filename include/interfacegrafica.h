#ifndef INTERFACEGRAFICA_H
#define INTERFACEGRAFICA_H

#include "tabuleiro.h"
#include "jogador.h"

class InterfaceGrafica {
public:
    void mostrarTabuleiro(Tabuleiro& tabuleiro);
    Jogada capturarJogada(Jogador& jogador);
    void exibirMensagem(std::string mensagem);
};

#endif
