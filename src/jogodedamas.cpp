#include "jogodedamas.h"
#include <cstdlib>

// Representa um jogo de damas
class JogoDeDamas {
private:
  // A interface gráfica
  InterfaceGrafica interface;

  // O tabuleiro
  Tabuleiro tabuleiro;

  // Os jogadores
  Jogador jogador1;
  Jogador jogador2;

public:
  // Construtor do jogo
  JogoDeDamas() : jogador1(PRETA), jogador2(VERMELHA) {
    // Inicializa os jogadores com as cores preta e vermelha
  }

  // Inicia o jogo
  void iniciarJogo() {
    // Exibe o tabuleiro
    interface.mostrarTabuleiro(tabuleiro);
  }

  // Realiza uma rodada do jogo
  void rodadaDeJogo() {
    // Captura a jogada do jogador atual
    Jogada jogada = jogadorAtual.realizarJogada(tabuleiro);

    // Verifica se a jogada é válida
    if (regras.jogadaValida(tabuleiro, jogada.linhaOrigem, jogada.colunaOrigem, jogada.linhaDestino, jogada.colunaDestino)) {
      // Verifica se a jogada captura uma peça
      if (tabuleiro.existePeca(jogada.linhaDestino, jogada.colunaDestino) && tabuleiro.getPeca(jogada.linhaDestino, jogada.colunaDestino)->getCor() != jogadorAtual.getCor()) {
        // Captura a peça
        tabuleiro.removerPeca(jogada.linhaDestino, jogada.colunaDestino);
      }

      // Realiza a jogada
      tabuleiro.realizarJogada(jogada.linhaOrigem, jogada.colunaOrigem, jogada.linhaDestino, jogada.colunaDestino);

      // Verifica se o jogo terminou
      if (jogoTerminou()) {
        // Exibe o vencedor
        interface.exibirMensagem("Fim de Jogo! O vencedor é: " + ((vencedor == PRETA) ? "PRETA" : "VERMELHA"));
        encerrarJogo();
      }
    } else {
      // A jogada é inválida, então exibe uma mensagem
      interface.exibirMensagem("Jogada inválida, tente novamente.");
    }
  }

  // Verifica se o jogo terminou
  bool jogoTerminou() {
    return regras.jogoTerminou(tabuleiro);
  }

  // Verifica quem é o vencedor do jogo
  Cor verificarVencedor() {
    int contagemPretas = 0;
    int contagemVermelhas = 0;

    // Contar as peças restantes no tabuleiro
    for (int linha = 0; linha < 8; linha++) {
      for (int coluna = 0; coluna < 8; coluna++) {
        Peca* peca = tabuleiro.getPeca(linha, coluna);
        if (peca != nullptr) {
          if (peca->getCor() == PRETA) {
            contagemPretas++;
          } else if (peca->getCor() == VERMELHA) {
            contagemVermelhas++;
          }
        }
      }
    }

    if (contagemPretas > contagemVermelhas) {
      return PRETA; // Jogador com as peças pretas vence
    } else if (contagemPretas < contagemVermelhas) {
      return VERMELHA; // Jogador com as peças vermelhas vence
    } else {
      return NENHUM; // Empate
    }
  }

  // Encerra o jogo
  void encerrarJogo() {
    exit(0);
  }
};
