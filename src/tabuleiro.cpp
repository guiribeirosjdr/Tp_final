#include "tabuleiro.h"
#include "peca.h"
#include "regrasdojogo.h"
#include "interfacegrafica.h"
#include <iostream>

Tabuleiro::Tabuleiro() {
    // Inicialize o tabuleiro aqui
    daVez = PRETA;
}

Tabuleiro::~Tabuleiro() {
    // Limpeza de memória, se necessário
}

void Tabuleiro::imprime() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (_casas[i][j] == nullptr) {
                std::cout << "  "; // Espaço em branco para casas vazias
            } else if (_casas[i][j]->get_cor() == PRETA) {
                std::cout << "P"; // Peça preta
            } else {
                std::cout << "V"; // Peça vermelha
            }
            std::cout << " "; // Espaço em branco entre as casas
        }
        std::cout << std::endl; // Nova linha para a próxima linha do tabuleiro
    }
}

bool Tabuleiro::movimenta(int linha, int coluna, int linha_destino, int coluna_destino) {
    if (!movimentoValido(linha, coluna, linha_destino, coluna_destino)) {
        return false; // Movimento inválido
    }

    // Realize o movimento, movendo a peça da posição atual para a posição de destino
    _casas[linha_destino][coluna_destino] = _casas[linha][coluna];
    _casas[linha][coluna] = nullptr;

    // Atualize a vez do próximo jogador
    _da_vez = (_da_vez == PRETA) ? VERMELHA : PRETA;

    return true; // Movimento válido
}

Cor Tabuleiro::getDaVez() const {
    return daVez;
}

Peca* Tabuleiro::getPeca(int linha, int coluna) const {
    if (linha < 0 || linha >= 8 || coluna < 0 || coluna >= 8) {
        return nullptr; // Fora dos limites do tabuleiro
    }
    return _casas[linha][coluna];
}

void Tabuleiro::realizarJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // Mova a peça no tabuleiro
    movimenta(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);

    // Verifique se a peça movida deve ser promovida a dama
    regras.promoverPecaADama(*this, linhaDestino, colunaDestino);
}
