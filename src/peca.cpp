#include "peca.h"

// Representa uma peça no jogo de damas
class Peca {
private:
  // A cor da peça
  Cor cor;

  // O status de dama da peça
  bool dama;

public:
  // Construtor da peça
  Peca(Cor cor) : cor(cor), dama(false) {
    // Inicializa a peça com a cor especificada
  }

  // Retorna a cor da peça
  Cor getCor() const {
    // Retorna a cor da peça
    return cor;
  }

  // Retorna o status de dama da peça
  bool isDama() const {
    // Retorna o status de dama da peça
    return dama;
  }

  // Promove a peça a dama
  void promoverDama() {
    // Promove a peça a dama
    dama = true;
  }
};
