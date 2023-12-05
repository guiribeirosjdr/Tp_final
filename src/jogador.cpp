#include "jogador.h"
#include "interfacegrafica.h"

// Representa um jogador no jogo de damas
class Jogador {
private:
  // A cor do jogador
  Cor cor;

public:
  // Construtor do jogador
  Jogador(Cor cor) : cor(cor) {
    // Cria um jogador com a cor especificada
  }

  // Realiza uma jogada no tabuleiro
  Jogada realizarJogada(Tabuleiro& tabuleiro) {
    // Captura a jogada do jogador usando a interface gráfica

    // Cria uma interface gráfica
    InterfaceGrafica interface;

    // Captura a jogada
    Jogada jogada = interface.capturarJogada(*this);

    // Verifica se a jogada é válida
    if (!tabuleiro.jogadaValida(jogada)) {
      // A jogada é inválida, então retorna uma jogada inválida
      return Jogada(-1, -1);
    }

    // A jogada é válida, então retorna a jogada
    return jogada;
  }
};
