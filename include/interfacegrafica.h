#ifndef INTERFACEGRAFICA_H
#define INTERFACEGRAFICA_H

#include "tabuleiro.h"
#include "jogador.h"
#include <SFML/Graphics.hpp>

class InterfaceGrafica {
private:
    sf::RenderWindow window;

public:
    InterfaceGrafica();
    void mostrarTabuleiro(Tabuleiro& tabuleiro);
    Jogada capturarJogada(Jogador& jogador);
    void exibirMensagem(std::string mensagem);
};

#endif
