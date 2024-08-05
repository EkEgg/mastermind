#include "tela-pontuacao-maxima.h"
#include "../utilidades/tipos.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include <stdio.h>

void inicializarEstadoTelaPontuacaoMaxima(ESTADO_TELA_PONTUACAO_MAXIMA *estado)
{
    estado->haErro = 0;
    estado->erro = "";
}

void imprimirTelaPontuacaoMaxima(ESTADO_TELA_PONTUACAO_MAXIMA *estado)
{
    limparConsole();
    puts("");
    puts("    Insira a pontuação máxima para terminar o jogo.");
    puts("");
    printf("    Pontuação máxima: ");
    if(estado->haErro)
    {
        puts("");
        puts("");
        definirAtributoGrafico(ATR_VERMELHO);
        definirAtributoGrafico(ATR_NEGRITO);
        printf("    * %s\n", estado->erro);
        definirAtributoGrafico(ATR_REINICIAR);
        reposicionarCursor(4, 23);
    }
}

void executarTelaPontuacaoMaxima(ushort *saidaPontuacaoMaxima)
{
    ESTADO_TELA_PONTUACAO_MAXIMA estado;
    int diagnostico;
    inicializarEstadoTelaPontuacaoMaxima(&estado);
    estado.saidaPontuacaoMaxima = saidaPontuacaoMaxima;
    while(1)
    {
        imprimirTelaPontuacaoMaxima(&estado);
        diagnostico = lerUShort(estado.saidaPontuacaoMaxima);
        estado.haErro = 1;
        if(diagnostico == 1)
        {
            estado.erro = "Entrada muito grande. Insira uma entrada menor.";
        }
        else if(diagnostico == 2)
        {
            estado.erro = "Entrada inválida. Insira um número inteiro sem sinal.";
        }
        else if(*estado.saidaPontuacaoMaxima == 0)
        {
            estado.erro = "A pontuação máxima não pode ser 0.";
        }
        else
        {
            estado.haErro = 0;
            break;
        }
    }
}