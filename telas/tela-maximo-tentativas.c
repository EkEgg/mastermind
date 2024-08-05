#include "tela-maximo-tentativas.h"
#include "../utilidades/tipos.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include <stdio.h>

void inicializarEstadoTelaMaximoTentativas(ESTADO_TELA_MAXIMO_TENTATIVAS *estado)
{
    estado->haErro = 0;
    estado->erro = "";
}

void imprimirTelaMaximoTentativas(ESTADO_TELA_MAXIMO_TENTATIVAS *estado)
{
    limparConsole();
    puts("");
    puts("    Insira o máximo de tentativas para terminar uma rodada.");
    puts("");
    printf("    Máximo de tentativas: ");
    if(estado->haErro)
    {
        puts("");
        puts("");
        definirAtributoGrafico(ATR_VERMELHO);
        definirAtributoGrafico(ATR_NEGRITO);
        printf("    * %s\n", estado->erro);
        definirAtributoGrafico(ATR_REINICIAR);
        reposicionarCursor(4, 27);
    }
}

void executarTelaMaximoTentativas(ushort *saidaMaximoDeTentativas)
{
    ESTADO_TELA_MAXIMO_TENTATIVAS estado;
    int diagnostico;
    inicializarEstadoTelaMaximoTentativas(&estado);
    estado.saidaMaximoDeTentativas = saidaMaximoDeTentativas;
    while(1)
    {
        imprimirTelaMaximoTentativas(&estado);
        diagnostico = lerUShort(estado.saidaMaximoDeTentativas);
        estado.haErro = 1;
        if(diagnostico == 1)
        {
            estado.erro = "Entrada muito grande. Insira uma entrada menor.";
        }
        else if(diagnostico == 2)
        {
            estado.erro = "Entrada inválida. Insira um número inteiro sem sinal.";
        }
        else if(*estado.saidaMaximoDeTentativas == 0)
        {
            estado.erro = "O máximo de tentativas não pode ser 0.";
        }
        else
        {
            estado.haErro = 0;
            break;
        }
    }
}