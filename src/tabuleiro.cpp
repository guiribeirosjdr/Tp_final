#include "tabuleiro.h"
#include "peca.h"
#include "regrasdojogo.h"
#include "interfacegrafica.h"
#include <iostream>

Tabuleiro::Tabuleiro() {
 // Inicialize o tabuleiro com peças pretas na primeira fileira e peças vermelhas na última fileira
 for (int i = 0; i < 8; i++) {
  for (int j = 0; j < 8; j++) {
   if (i == 0 || i == 7) {
    _casas[i][j] = new Peca(Cor::PRETA, i, j);
   } else {
    _casas[i][j] = nullptr;
   }
  }
 }
 daVez = PRETA;
}

Tabuleiro::~Tabuleiro() {
 // Limpeza de memória, se necessário
 for (int i = 0; i < 8; i++) {
  for (int j = 0; j < 8; j++) {
   if (_casas[i][j] != nullptr) {
    delete _casas[i][j];
   }
  }
 }
}

void Tabuleiro::imprime() {
 for (int i = 0; i < 8; i++) {
  for (int j = 0; j < 8; j++) {
   if (_casas[i][j] == nullptr) {
    std::cout << " "; // Espaço em branco para casas vazias
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

bool Tabuleiro::movimentoValido(int linha, int coluna, int linha_destino, int coluna_destino) {
 // Verifica se há uma peça na posição de origem
 Peca* pecaOrigem = getPeca(linha, coluna);
 if (pecaOrigem == nullptr) {
  return false;
 }

 // Verifica se a peça é da cor atual
 if (pecaOrigem->get_cor() != daVez) {
  return false;
 }

 // Verifica se o movimento é válido de acordo com as regras do jogo
 if (abs(linha - linha_destino) == 1 && abs(coluna - coluna_destino) == 1) {
  // Movimento diagonal
  if (_casas[linha_destino][coluna_destino] == nullptr) {
   // Movimento para uma casa vazia
   return true;
  } else {
   // Movimento para uma casa ocupada pelo adversário
   return true;
  }
 } else if (abs(linha - linha_destino) == 2 && abs(coluna - coluna_destino) == 2) {
  // Captura diagonal
  if (_casas[linha_destino][coluna_destino] != nullptr && pecaOrigem->get_cor() != _casas[linha_destino][coluna_destino]->get_cor()) {
   // Captura uma peça do adversário
   // Verifica se a peça capturada pode ser promovida a dama
   if (pecaOrigem->get_linha() == 0 || pecaOrigem->get_linha() == 7) {
    pecaOrigem->promoverDama();
   }
   return true;
  }
 }
 return false;
}

// Métodos adicionais

Peca* Tabuleiro::getPeca(int linha, int coluna) const {
 if (linha < 0 || linha >= 8 || coluna < 0 || coluna >= 8) {
