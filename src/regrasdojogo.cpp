#include "regrasdojogo.h"
#include <cmath>

bool RegrasDoJogo::jogadaValida(Tabuleiro& tabuleiro, int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
  // Verifica se há uma peça na posição de origem
    Peca* pecaOrigem = tabuleiro.getPeca(linhaOrigem, colunaOrigem);
    if (pecaOrigem == nullptr) {
        return false;
    }

        if (abs(linhaDestino - linhaOrigem) == 1 && abs(colunaDestino - colunaOrigem) == 1) {
        return true;
    }

    return false; // A jogada não é válida
}

bool RegrasDoJogo::jogoTerminou(Tabuleiro& tabuleiro) {
    // Verifica se não há mais peças da cor atual no tabuleiro
    Cor corAtual = tabuleiro.getDaVez();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Peca* peca = tabuleiro.getPeca(i, j);
            if (peca != nullptr && peca->getCor() == corAtual) {
                return false; // Ainda há peças da cor atual no tabuleiro, o jogo não terminou
            }
        }
    }

    return true; // Todas as peças da cor atual foram capturadas ou bloqueadas
}

void RegrasDoJogo::promoverPecaADama(Tabuleiro& tabuleiro, int linha, int coluna) {
    // Verifica se a peça existe e não é uma dama
    Peca* peca = tabuleiro.getPeca(linha, coluna);
    if (peca != nullptr && !peca->isDama()) {
        // Obtém a cor da peça para determinar a última linha do tabuleiro
        Cor corPeca = peca->getCor();

        // Verifica se a peça atingiu a última linha do tabuleiro
        if ((corPeca == PRETA && linha == 7) || (corPeca == VERMELHA && linha == 0)) {
            // Promove a peça a dama
            peca->promoverDama();
        }
    }
}
