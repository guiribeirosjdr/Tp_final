#include <iostream>
#include "tabuleiro.h"
#include "jogador.h"
#include "regrasdojogo.h"
#include "interfacegrafica.h"
#include "jogodedamas.h"

using namespace std;

int main() {
    JogoDeDamas jogo; // Crie uma instância do jogo de Damas

    jogo.iniciarJogo(); // Inicie o jogo

    while (!jogo.jogoTerminou()) {
        jogo.rodadaDeJogo();
    }

    Cor vencedor = jogo.verificarVencedor();
    jogo.encerrarJogo();

    cout << "O jogador " << (vencedor == PRETA ? "PRETO" : "VERMELHO") << " venceu!" << endl;

    return 0;
}