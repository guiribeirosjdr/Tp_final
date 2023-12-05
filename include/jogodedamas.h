#ifndef JOGODEDAMAS_H
#define JOGODEDAMAS_H

#include "tabuleiro.h"
#include "jogador.h"
#include "regrasdojogo.h"
#include "interfacegrafica.h"

// Representa um jogo de damas
class JogoDeDamas {
private:
  // Tabuleiro do jogo
  Tabuleiro tabuleiro;

  // Jogador 1
  Jogador jogador1;

  // Jogador 2
  Jogador jogador2;

  // Regras do jogo
  RegrasDoJogo regras;

  // Interface gráfica
  InterfaceGrafica interface;

public:
  // Construtor do jogo
  JogoDeDamas();

  // Inicia o jogo
  void iniciarJogo();

  // Realiza uma rodada do jogo
  void rodadaDeJogo();

  // Verifica se o jogo terminou
  bool jogoTerminou();

  // Verifica o vencedor do jogo
  Cor verificarVencedor();

  // Encerra o jogo
  void encerrarJogo();
};

#endif
