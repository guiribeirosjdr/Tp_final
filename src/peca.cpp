#include "peca.h"

Peca::Peca(Cor cor) : cor(cor), dama(false) {
   }

Cor Peca::getCor() const {
    return cor;
}

bool Peca::isDama() const {
    return dama;
}

void Peca::promoverDama() {
    dama = true;
}
