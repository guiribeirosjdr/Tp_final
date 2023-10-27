#include "jogodedamas.h"

JogoDeDamas::JogoDeDamas() : jogador1(PRETA), jogador2(VERMELHA) {
}

void JogoDeDamas::iniciarJogo() {
}

void JogoDeDamas::rodadaDeJogo() {
}

bool JogoDeDamas::jogoTerminou() {
    return regras.jogoTerminou(tabuleiro);
}

Cor JogoDeDamas::verificarVencedor() {
}

void JogoDeDamas::encerrarJogo() {
}
