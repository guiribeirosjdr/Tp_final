#include "interfacegrafica.h"
#include <iostream>

void InterfaceGrafica::mostrarTabuleiro(Tabuleiro& tabuleiro) {
       tabuleiro.imprime();
}

Jogada InterfaceGrafica::capturarJogada(Jogador& jogador) {
      int linhaOrigem, colunaOrigem, linhaDestino, colunaDestino;
    
    std::cout << "Jogador " << (jogador.getCor() == PRETA ? "PRETO" : "VERMELHO") << ", faça sua jogada:" << std::endl;
    std::cout << "Linha de origem: ";
    std::cin >> linhaOrigem;
    std::cout << "Coluna de origem: ";
    std::cin >> colunaOrigem;
    std::cout << "Linha de destino: ";
    std::cin >> linhaDestino;
    std::cout << "Coluna de destino: ";
    std::cin >> colunaDestino;

    return Jogada(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
}

void InterfaceGrafica::exibirMensagem(std::string mensagem) {
       std::cout << mensagem << std::endl;
}
