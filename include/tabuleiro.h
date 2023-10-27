#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include "peca.h"
#include "regrasdojogo.h"  
#include "interfacegrafica.h" 

using namespace std;

class Tabuleiro {
private:
    vector<vector<Peca *>> _casas;
    Cor _da_vez;
    RegrasDoJogo regras; 
    InterfaceGrafica interface; 

public:
    Tabuleiro();
    ~Tabuleiro();
    void imprime();
    bool movimenta(int linha, int coluna, bool diag_esq);
};

#endif
