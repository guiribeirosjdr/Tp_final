# TrabalhoFinal
 Tp_Final Jogo de Damas

# Autores
- Guilherme Augusto Ribeiro da Silva - 2023427503
- João Victor Moraes de Abreu Ribeiro - 2021014236

# Jogo de Damas

Bem-vindo ao jogo de damas! 
Este é um Trabalho Prático para a disciplina de Programação e Desenvolvimento de Software II - 2023/2

1. **Apresentação do Problema:**
   
   O jogo de damas é um jogo de tabuleiro clássico que oferece entretenimento e desafio intelectual. Este projeto tem como objetivo criar uma implementação digital do jogo de damas, permitindo que os jogadores joguem online, praticando suas habilidades estratégicas e táticas.

2. **Visão Geral da Solução:**
   
   A solução consiste em uma aplicação de jogo de damas desenvolvida em c++. Os jogadores podem se enfrentar em um tabuleiro virtual, movendo suas peças de acordo com as regras do jogo. O programa inclui uma interface gráfica simples para facilitar a jogabilidade. Os movimentos das peças são validados, e o jogo pode detectar automaticamente quando um jogador vence.

3. **Estrutura do Projeto:**
   
   A estrutura do projeto é a seguinte:
   
   - `src`: Este diretório contém o código-fonte do jogo de damas.
   - `include`: Aqui, você pode encontrar a documentação de cabeçalho do projeto.
   - `cartaoCRC`: As classes estão descritas neste diretório.
   - `main.cpp`: Contém a função principal do programa.

## Como Jogar

1. **Instruções de Compilação**:
   - Certifique-se de que você possui um compilador C++ instalado.
   - Compile o jogo executando `g++ -o jogo main.cpp tabuleiro.cpp jogador.cpp regrasdojogo.cpp interfacegrafica.cpp jogodedamas.cpp`.

2. **Instruções de Execução**:
   - Após a compilação, execute o jogo com `./jogo`.

3. **Regras do Jogo**:
   - O jogo segue as regras tradicionais das damas.
   - As peças movem-se diagonalmente em direção ao campo adversário.
   - O objetivo é capturar todas as peças do adversário ou bloquear seus movimentos.

4. **Controles**:
   - Use as coordenadas do tabuleiro para selecionar as peças a mover.
   - Siga as instruções apresentadas no jogo para fazer seus movimentos.

5. **Vitória**:
   - O jogo termina quando um jogador captura todas as peças do adversário ou bloqueia seus movimentos.
