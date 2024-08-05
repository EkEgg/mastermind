#include "tela-placar.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include <stdio.h>
#include <string.h>

void imprimirTelaPlacar(ESTADO_TELA_PLACAR *estado)
{
    ushort espacamento1, espacamento2, tamanho1, tamanho2;
    tamanho1 = strlen(estado->jogador1->nome);
    tamanho2 = strlen(estado->jogador2->nome);
    if(tamanho1 < tamanho2)
    {
        espacamento1 = tamanho2 - tamanho1 + 1;
        espacamento2 = 1;
    }
    else
    {
        espacamento1 = 1;
        espacamento2 = tamanho1 - tamanho2 + 1;
    }
    limparConsole();
    puts("");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERDE);
    puts("    Placar");
    definirAtributoGrafico(ATR_REINICIAR);
    puts("");
    printf("    Pontuação máxima para terminar o jogo: ");
    definirAtributoGrafico(ATR_NEGRITO);
    printf("%hu", estado->pontuacaoMaxima);
    definirAtributoGrafico(ATR_REINICIAR);
    puts("");
    puts("");
    printf("    ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_CIANO);
    printf("%s", estado->jogador1->nome);
    definirAtributoGrafico(ATR_REINICIAR);
    printf(":");
    while(espacamento1--) putchar(' ');
    definirAtributoGrafico(ATR_NEGRITO);
    printf("%hu\n", estado->jogador1->pontuacao);
    definirAtributoGrafico(ATR_REINICIAR);
    printf("    ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERMELHO);
    printf("%s", estado->jogador2->nome);
    definirAtributoGrafico(ATR_REINICIAR);
    printf(":");
    while(espacamento2--) putchar(' ');
    definirAtributoGrafico(ATR_NEGRITO);
    printf("%hu\n", estado->jogador2->pontuacao);
    definirAtributoGrafico(ATR_REINICIAR);
    puts("");
    
    printf("    Pressione ");
    definirAtributoGrafico(ATR_NEGRITO);
    printf("[ENTER]");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" para continuar. ");
}

void executarTelaPlacar(JOGADOR *jogador1, JOGADOR *jogador2, ushort pontuacaoMaxima)
{
    ESTADO_TELA_PLACAR estado;
    estado.jogador1 = jogador1;
    estado.jogador2 = jogador2;
    estado.pontuacaoMaxima = pontuacaoMaxima;
    imprimirTelaPlacar(&estado);
    pularLinha();
}