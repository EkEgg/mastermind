#include "tela-escolha-criador.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include <stdio.h>

void inicializarEstadoTelaEscolhaCriador(ESTADO_TELA_ESCOLHA_CRIADOR *estado)
{
    estado->haErro = 0;
    estado->erro = "";
}

void imprimirTelaEscolhaCriador(ESTADO_TELA_ESCOLHA_CRIADOR *estado)
{
    limparConsole();

    puts("");
    printf("    Quem será o ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_AZUL);
    printf("criador");
    definirAtributoGrafico(ATR_REINICIAR);
    puts(" primeiro?");
    puts("");
    printf("    1. ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_CIANO);
    puts(estado->nomeDoJogador1);
    definirAtributoGrafico(ATR_REINICIAR);
    printf("    2. ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERMELHO);
    puts(estado->nomeDoJogador2);
    definirAtributoGrafico(ATR_REINICIAR);
    puts("    3. Sortear");
    printf("    Escolha: ");

    if(estado->haErro)
    {
        puts("");
        puts("");
        definirAtributoGrafico(ATR_VERMELHO);
        definirAtributoGrafico(ATR_NEGRITO);
        printf("    * %s\n", estado->erro);
        definirAtributoGrafico(ATR_REINICIAR);
        reposicionarCursor(7, 14);
    }
}

void executarTelaEscolhaCriador(char *nomeDoJogador1, char *nomeDoJogador2, ushort *saidaOpcao)
{
    ESTADO_TELA_ESCOLHA_CRIADOR estado;
    int diagnostico;
    inicializarEstadoTelaEscolhaCriador(&estado);
    estado.nomeDoJogador1 = nomeDoJogador1;
    estado.nomeDoJogador2 = nomeDoJogador2;
    estado.saidaOpcao = saidaOpcao;
    while(1)
    {
        imprimirTelaEscolhaCriador(&estado);
        diagnostico = lerUShort(saidaOpcao);
        estado.haErro = 1;
        if(diagnostico == 1)
        {
            estado.erro = "Entrada muito grande. Insira uma entrada menor.";
        }
        else if(diagnostico == 2)
        {
            estado.erro = "Entrada inválida. Insira um número inteiro sem sinal.";
        }
        else if(*saidaOpcao < 1 || *saidaOpcao > 3)
        {
            estado.erro = "Entrada inválida. Insira uma das opções.";
        }
        else
        {
            estado.haErro = 0;
            break;
        }
    }
}