#ifndef TabuleiroTp_final
#define TabuleiroTp_final

#include <vector>

#include "peca.h"

using namespace std;

class Tabuleiro {
  private:
    vector<vector<Peca *>> _casas;
    Cor _da_vez;
  public:
    Tabuleiro();
    ~Tabuleiro();
    void imprime();
    bool movimenta(int linha, int coluna, bool diag_esq);
};

#endif