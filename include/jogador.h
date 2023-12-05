#ifndef JOGADOR_H
#define JOGADOR_H

#include "tabuleiro.h"

class Jogador {
protected:
  // Cor do jogador
  Cor cor;

  // Nome do jogador
  std::string nome;

  // Nível de habilidade do jogador
  int nivelHabilidade;

public:
  // Construtor do jogador
  Jogador(Cor cor, std::string nome, int nivelHabilidade);

  // Realiza uma jogada do jogador
  virtual Jogada realizarJogada(Tabuleiro& tabuleiro) = 0;
};

class Humano : public Jogador {
public:
  Humano(Cor cor, std::string nome, int nivelHabilidade) : Jogador(cor, nome, nivelHabilidade) {}

  // Realiza uma jogada do jogador humano
  Jogada realizarJogada(Tabuleiro& tabuleiro) override {
    // ...
    return jogada;
  }
};

#endif
