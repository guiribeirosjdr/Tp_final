#include "interfacegrafica.h"
#include <SFML/Graphics.hpp>

InterfaceGrafica::InterfaceGrafica() : window(sf::VideoMode(400, 400), "Jogo de Damas") {
}

void InterfaceGrafica::mostrarTabuleiro(Tabuleiro& tabuleiro) {
    window.clear();

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sf::RectangleShape square(sf::Vector2f(50, 50));
            square.setPosition(i * 50, j * 50);
            square.setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);

            window.draw(square);

            Peca* peca = tabuleiro.getPeca(j, i);
            if (peca != nullptr) {
                sf::CircleShape piece(25);
                piece.setPosition(i * 50 + 12.5, j * 50 + 12.5); // Ajuste a posição conforme necessário
                piece.setFillColor(peca->getCor() == PRETA ? sf::Color::Black : sf::Color::Red);

                window.draw(piece);
            }
        }
    }

    window.display();
}

Jogada InterfaceGrafica::capturarJogada(Jogador& jogador) {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            int mouseX = event.mouseButton.x / 50; 
            int mouseY = event.mouseButton.y / 50;

            return Jogada(mouseY, mouseX); // Reverta a ordem das coordenadas conforme necessário
        }
    }

    // Se não houve evento de clique, retorne uma jogada inválida.
    return Jogada(-1, -1);
}

void InterfaceGrafica::exibirMensagem(std::string mensagem) {
       sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
               return;
    }

    sf::Text text;
    text.setFont(font);
    text.setString(mensagem);
    text.setCharacterSize(24);
    text.setPosition(10, 10); // Posição arbitrária, ajuste conforme necessário
    text.setFillColor(sf::Color::White);

    window.draw(text);
    window.display();
}
