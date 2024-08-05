#include "tela-creditos.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include <stdio.h>

void imprimirTelaCreditos(void)
{
    limparConsole();
    puts("");
    definirAtributoGrafico(ATR_VERDE);
    definirAtributoGrafico(ATR_NEGRITO);
    puts("    CRÉDITOS");
    definirAtributoGrafico(ATR_REINICIAR);
    puts("");
    puts("    Feito por:");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_AZUL);
    puts("        ERICK GAIOTE DOS SANTOS");
    definirAtributoGrafico(ATR_CIANO);
    puts("        GABRIEL DUARTE SOARES");
    definirAtributoGrafico(ATR_VERDE);
    puts("        JOÃO PEDRO DE CARVALHO SOUZA");
    definirAtributoGrafico(ATR_REINICIAR);
    puts("");
    puts("    Orientado por:");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERMELHO);
    puts("        PROFA. VALÉRIA MENEZES BASTOS");
    definirAtributoGrafico(ATR_REINICIAR);
    puts("");
    puts("    Somos alunos do Bacharelado em Ciência da Computação da UFRJ. Fizemos este jogo como traba-");
    puts("    lho final da disciplina Computação I no período de 2022.1.");
    puts("");
    
    printf("    Pressione ");
    definirAtributoGrafico(ATR_NEGRITO);
    printf("[ENTER]");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" para voltar. ");
}

void executarTelaCreditos(void)
{
    imprimirTelaCreditos();
    pularLinha();
}