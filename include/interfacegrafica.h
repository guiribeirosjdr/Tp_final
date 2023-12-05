#ifndef INTERFACEGRAFICA_H
#define INTERFACEGRAFICA_H

#include "tabuleiro.h"
#include "jogador.h"
#include <SFML/Graphics.hpp>

// Representa a interface gráfica do jogo
class InterfaceGrafica {
private:
  // Armazena a janela gráfica
  sf::RenderWindow window;

public:
  // Construtor da classe InterfaceGrafica
  InterfaceGrafica();

  // Mostra o tabuleiro na janela gráfica
  void mostrarTabuleiro(Tabuleiro& tabuleiro);

  // Captura uma jogada do jogador
  Jogada capturarJogada(Jogador& jogador);

  // Exibe uma mensagem na janela gráfica
  void exibirMensagem(std::string mensagem);
};

#endif
