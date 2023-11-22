#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include "peca.h"
#include "regrasdojogo.h"  
#include "interfacegrafica.h" 

using namespace std;

class Tabuleiro {
private:
    std::vector<std::vector<Peca *>> casas;
    Cor daVez;

public:
    Tabuleiro();
    ~Tabuleiro();
    void imprime();
    bool movimenta(int linha, int coluna, bool diag_esq);
    Cor getDaVez() const;
    Peca* getPeca(int linha, int coluna) const;
    void realizarJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};

#endif
