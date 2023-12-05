#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include "peca.h"
#include "regrasdojogo.h"  
#include "interfacegrafica.h" 

using namespace std;

// Representa o tabuleiro do jogo de damas
class Tabuleiro {
private:
  // Representa as casas do tabuleiro
  std::vector<std::vector<Peca *>> casas;

  // Representa a cor do jogador que está na vez
  Cor daVez;

public:
  // Construtor do tabuleiro
  Tabuleiro();

  // Destrutor do tabuleiro
  ~Tabuleiro();

  // Imprime o tabuleiro
  void imprime();

  // Move uma peça no tabuleiro
  bool movimenta(int linha, int coluna, bool diag_esq);

  // Obtém a cor do jogador que está na vez
  Cor getDaVez() const;

  // Obtém a peça na casa especificada
  Peca* getPeca(int linha, int coluna) const;

  // Realiza uma jogada no tabuleiro
  void realizarJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);

  // Verifica se uma jogada é válida
  bool jogadaValida(int linhaOrigem, int colunaOrigem, bool diag_esq);
};

#endif
