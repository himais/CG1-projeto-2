# Projeto #2 - 3º semestre/2016

Projeto desenvolvido para a disciplina CG1 (Computação Gráfica 1) do terceiro semestre do curso de Análise e Desenvolvimento de Sistemas (2016) do Instituto Federal de Educação, Ciência e Tecnologia de São Paulo - Campus São Paulo. 


## Objetivo
Polígono com rotação no eixo Z.

## Descrição
Para esta questão escreva procedimentos em linguagem C utilizando a biblioteca OpenGL que realize as  seguintes tarefas:

a)Faça um procedimento drawFigure(tNo *iniLista) que recebe como parâmetro o início de uma lista encadeada de pontos que formam um polígono ,armazenada em iniLista do tipo tNo,e desenha este polígono. Para este exercício utilize a primitiva glBegin( GL_LINE_LOOP ) ... glEnd(); A estrutura do tNo é apresentada a seguir:


> typedef struct _tNo{ float x, y; struct _tNo *prox;} tNo;


b)Agora assuma que o procedimento drawFigure (tNo *iniLista) é uma função dada (você não pode modificar o procedimento drawFigure(tNo *iniLista) criado inicialmente. Faça um procedimento RotateFigure(tNo *iniLista, float angle) que recebe como parâmetro o início de uma lista encadeada de pontos que formam um polígono, armazenada em iniLista do tipo tNo, e um parâmetro angle do tipo float que contém um ângulo a ser rodado, e desenha este polígono rotacionado de angle graus.

Para rotacionar o objeto você deverá utilizar a tecla ‘A’ rotacionar no sentido horário e a tecla ‘L’ para rotacionar no sentido anti-horário.

## Tecnologias

- OpenGL
