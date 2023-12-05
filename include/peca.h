#ifndef PECA_H
#define PECA_H
#include <string>

using namespace std;

enum Cor {
  PRETA, VERMELHA
};

// Representa uma peça no jogo de damas
class Peca {
private:
  // Cor da peça
  Cor cor;

  // Indica se a peça é uma dama
  bool dama;

public:
  // Construtor da peça
  Peca(Cor cor) : cor(cor) {}

  // Obtém a cor da peça
  Cor& getCor() const { return cor; }

  // Indica se a peça é uma dama
  bool isDama() const { return dama; }

  // Promove a peça a dama
  void promoverDama() { dama = true; }
};

#endif
