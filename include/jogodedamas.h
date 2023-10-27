#ifndef JOGODEDAMAS_H
#define JOGODEDAMAS_H

#include "tabuleiro.h"
#include "jogador.h"
#include "regrasdojogo.h"
#include "interfacegrafica.h"

class JogoDeDamas {
private:
    Tabuleiro tabuleiro;
    Jogador jogador1;
    Jogador jogador2;
    RegrasDoJogo regras;
    InterfaceGrafica interface;

public:
    JogoDeDamas();
    void iniciarJogo();
    void rodadaDeJogo();
    bool jogoTerminou();
    Cor verificarVencedor();
    void encerrarJogo();
};

#endif
