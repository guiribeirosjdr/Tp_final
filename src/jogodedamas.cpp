#include "jogodedamas.h"
#include <cstdlib>

JogoDeDamas::JogoDeDamas() : jogador1(PRETA), jogador2(VERMELHA) {
   }

void JogoDeDamas::iniciarJogo() {
    interface.mostrarTabuleiro(tabuleiro);
}

void JogoDeDamas::rodadaDeJogo() {
    Jogador& jogadorAtual = (tabuleiro.getDaVez() == PRETA) ? jogador1 : jogador2;
    Jogada jogada = jogadorAtual.realizarJogada(tabuleiro);

    if (regras.jogadaValida(tabuleiro, jogada.linhaOrigem, jogada.colunaOrigem, jogada.linhaDestino, jogada.colunaDestino)) {
        tabuleiro.realizarJogada(jogada.linhaOrigem, jogada.colunaOrigem, jogada.linhaDestino, jogada.colunaDestino);
        interface.mostrarTabuleiro(tabuleiro);

        if (jogoTerminou()) {
            Cor vencedor = verificarVencedor();
            interface.exibirMensagem("Fim de Jogo! O vencedor é: " + ((vencedor == PRETA) ? "PRETA" : "VERMELHA"));
            encerrarJogo();
        }
    } else {
        interface.exibirMensagem("Jogada inválida, tente novamente.");
    }
}

bool JogoDeDamas::jogoTerminou() {
    return regras.jogoTerminou(tabuleiro);
}

Cor JogoDeDamas::verificarVencedor() {
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

void JogoDeDamas::encerrarJogo() {
        exit(0);
}
