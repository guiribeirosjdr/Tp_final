#include "interfacegrafica.h"
#include <SFML/Graphics.hpp>

// Representa a interface gráfica do jogo de damas
class InterfaceGrafica {
private:
  // A janela do jogo
  sf::RenderWindow window;

public:
  // Construtor da interface gráfica
  InterfaceGrafica() : window(sf::VideoMode(400, 400), "Jogo de Damas") {
    // Cria uma janela com o título "Jogo de Damas"
  }

  // Mostra o tabuleiro na janela
  void mostrarTabuleiro(Tabuleiro& tabuleiro) {
    // Limpa a janela
    window.clear();

    // Desenha os quadrados
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        // Desenha um quadrado preto ou branco
        sf::RectangleShape square(sf::Vector2f(50, 50));
        square.setPosition(i * 50, j * 50);
        square.setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);

        window.draw(square);

        // Desenha a peça, se houver
        Peca* peca = tabuleiro.getPeca(j, i);
        if (peca != nullptr) {
          // Desenha uma peça preta ou branca
          sf::CircleShape piece(25);
          piece.setPosition(i * 50 + 12.5, j * 50 + 12.5); // Ajuste a posição conforme necessário
          piece.setFillColor(peca->getCor() == PRETA ? sf::Color::Black : sf::Color::Red);

          window.draw(piece);
        }
      }
    }

    // Exibe a janela
    window.display();
  }

  // Captura uma jogada do jogador
  Jogada capturarJogada(Jogador& jogador) {
    // Loop enquanto houver eventos
    while (window.pollEvent(event)) {
      // Se o evento for o fechamento da janela, fecha o jogo
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Se o evento for um clique do mouse, capture a jogada
      else if (event.type == sf::Event::MouseButtonPressed) {
        // Obtém as coordenadas do clique
        int mouseX = event.mouseButton.x / 50;
        int mouseY = event.mouseButton.y / 50;

        // Retorna a jogada
        return Jogada(mouseY, mouseX); 
      }
    }

    // Se não houve evento de clique, retorne uma jogada inválida
    return Jogada(-1, -1);
  }

  // Exibe uma mensagem na janela
  void exibirMensagem(std::string mensagem) {
    // Carrega a fonte
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
      return;
    }

    // Cria o texto
    sf::Text text;
    text.setFont(font);
    text.setString(mensagem);
    text.setCharacterSize(24);
    text.setPosition(10, 10);
    text.setFillColor(sf::Color::White);

    // Desenha o texto na janela
    window.draw(text);
    window.display();
  }
};
