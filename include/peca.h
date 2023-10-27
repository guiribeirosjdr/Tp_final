#ifndef PECA_H
#define PECA_H

#include <string>

using namespace std;

enum Cor {
  PRETA, VERMELHA
};

class Peca {
  private:
    Cor _cor;
    bool _dama;
  public:
    Peca(Cor cor);
    Cor get_cor();
};

#endif