#ifndef REGRASDOJOGO_H
#define REGRASDOJOGO_H

#include "tabuleiro.h"

// Representa as regras do jogo de damas
class RegrasDoJogo {
public:
  // Verifica se uma jogada é válida
  bool jogadaValida(Tabuleiro& tabuleiro, int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
  // Verifica se o jogo terminou
  bool jogoTerminou(Tabuleiro& tabuleiro);
  // Promove uma peça a dama
  void promoverPecaADama(Tabuleiro& tabuleiro, int linha, int coluna);

private:
  // Verifica se uma jogada é válida, retornando um código de erro
  ErroJogada verificarJogada(Tabuleiro& tabuleiro, int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};

enum ErroJogada {
  JOGADAREPETIDA,
  PECAINVALIDA,
  CASAINVALIDA,
  CAPTURAINVALIDA,
};

// Verifica se uma jogada é válida, retornando um código de erro
ErroJogada RegrasDoJogo::verificarJogada(Tabuleiro& tabuleiro, int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
  // Verifica se a jogada é repetida
  if (tabuleiro.getPeca(linhaOrigem, colunaOrigem) == tabuleiro.getPeca(linhaDestino, colunaDestino)) {
    return ErroJogada::JOGADAREPETIDA;
  }

  // Verifica se a peça é válida
  Peca pecaOrigem = tabuleiro.getPeca(linhaOrigem, colunaOrigem);
  if (pecaOrigem.getCor() == Cor::NENHUMA) {
    return ErroJogada::PECAINVALIDA;
  }

  // Verifica se a casa de destino é válida
  if (linhaDestino < 0 || linhaDestino >= tabuleiro.getTamanho() || colunaDestino < 0 || colunaDestino >= tabuleiro.getTamanho()) {
    return ErroJogada::CASAINVALIDA;
  }

  // Verifica se a captura é válida
  if (pecaOrigem.isDama()) {
    // Damas podem capturar qualquer peça na diagonal
    if (abs(linhaOrigem - linhaDestino) != abs(colunaOrigem - colunaDestino)) {
      return ErroJogada::CAPTURAINVALIDA;
    }
  } else {
    // Peças comuns podem capturar apenas peças na diagonal em uma única casa
    if (abs(linhaOrigem - linhaDestino) != 1 || abs(colunaOrigem - colunaDestino) != 1) {
      return ErroJogada::CAPTURAINVALIDA;
    }

    // Verifica se a peça a ser capturada existe
    if (tabuleiro.getPeca(linhaDestino, colunaDestino).getCor() == Cor::NENHUMA) {
      return ErroJogada::CAPTURAINVALIDA;
    }
  }

  // A jogada é válida
  return ErroJogada::NENHUM;
}

#endif
