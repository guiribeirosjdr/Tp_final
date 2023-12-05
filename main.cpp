// Inclui as bibliotecas Qt necessárias para criar a interface gráfica
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

// Inclui as classes necessárias para implementar o jogo de damas
#include "tabuleiro.h"
#include "jogador.h"
#include "regrasdojogo.h"
#include "interfacegrafica.h"
#include "jogodedamas.h"

// Declara que a biblioteca padrão do C++ será usada
using namespace std;

int main() {

  // Instancia um novo jogo de damas
  JogoDeDamas jogo;

  // Inicia o jogo
  jogo.iniciarJogo();

  // Executa o jogo até que ele termine
  while (!jogo.jogoTerminou()) {

    //Realiza uma rodada do jogo
    jogo.rodadaDeJogo();
  }

  // Verifica o vencedor do jogo
  Cor vencedor = jogo.verificarVencedor();

  // Imprime o vencedor do jogo
  cout << "O jogador " << (vencedor == PRETA ? "PRETO" : "VERMELHO") << " venceu!" << endl;

  // Encerra o jogo
  jogo.encerrarJogo();

  // Retorna o valor 0 para indicar que o programa terminou com sucesso**
  return 0;
}
