#include "regrasdojogo.h"
#include <cmath>

// Representa as regras do jogo de damas
class RegrasDoJogo {
public:
  // Verifica se a jogada é válida
  bool jogadaValida(Tabuleiro& tabuleiro, int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // Verifica se há uma peça na posição de origem
    Peca* pecaOrigem = tabuleiro.getPeca(linhaOrigem, colunaOrigem);
    if (pecaOrigem == nullptr) {
      // A jogada não é válida, pois não há peça na posição de origem
      return false;
    }

    // Verifica se a peça é da cor atual
    if (pecaOrigem->getCor() != tabuleiro.getDaVez()) {
      // A jogada não é válida, pois a peça não é da cor atual
      return false;
    }

    // Verifica se a jogada é válida de acordo com as regras do jogo
    if (abs(linhaDestino - linhaOrigem) != 1) {
      // A jogada não é válida, pois a peça só pode se mover uma casa diagonalmente
      return false;
    }

    if (abs(colunaDestino - colunaOrigem) != 1) {
      // A jogada não é válida, pois a peça só pode se mover uma casa diagonalmente
      return false;
    }

    // Verifica se a peça está se movendo para uma casa vazia
    if (!tabuleiro.existePeca(linhaDestino, colunaDestino)) {
      // A jogada é válida, pois a peça está se movendo para uma casa vazia
      return true;
    }

    // A jogada não é válida, pois a peça não está se movendo para uma casa vazia
    return false;
  }

  // Verifica se o jogo terminou
  bool jogoTerminou(Tabuleiro& tabuleiro) {
    // Verifica se não há mais peças da cor atual no tabuleiro
    Cor corAtual = tabuleiro.getDaVez();
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        Peca* peca = tabuleiro.getPeca(i, j);
        if (peca != nullptr && peca->getCor() == corAtual) {
          // Ainda há peças da cor atual no tabuleiro, o jogo não terminou
          return false;
        }
      }
    }

    // Todas as peças da cor atual foram capturadas ou bloqueadas, o jogo terminou
    return true;
  }

  // Promove uma peça a dama
  void promoverPecaADama(Tabuleiro& tabuleiro, int linha, int coluna) {
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
};
