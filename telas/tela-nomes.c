#include "tela-nomes.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include "../utilidades/strings.h"
#include "../fluxos/jogo.h"
#include <string.h>
#include <stdio.h>

void inicializarEstadoTelaNomes(ESTADO_TELA_NOMES *estado)
{
    estado->nomeDoJogador1Preenchido = 0;
    estado->nomeDoJogador2Preenchido = 0;
    estado->haErro = 0;
    estado->erro = "";
}

void imprimirTelaNomes(ESTADO_TELA_NOMES *estado)
{
    limparConsole();
    puts("");
    puts("    Insira o nome dos jogadores.");
    puts("");
    printf("    Jogador 1: %s\n", estado->nomeDoJogador1Preenchido ? estado->saidaNomeDoJogador1 : "");
    printf("    Jogador 2: %s\n", estado->nomeDoJogador2Preenchido ? estado->saidaNomeDoJogador2 : "");
    if(estado->haErro)
    {
        puts("");
        definirAtributoGrafico(ATR_VERMELHO);
        definirAtributoGrafico(ATR_NEGRITO);
        printf("    * %s\n", estado->erro);
        definirAtributoGrafico(ATR_REINICIAR);
    }
    if(!estado->nomeDoJogador1Preenchido) reposicionarCursor(4, 16);
    else reposicionarCursor(5, 16);
}

void executarTelaNomes(char *saidaNomeDoJogador1, char *saidaNomeDoJogador2)
{
    ESTADO_TELA_NOMES estado;
    char *nomeLido;
    byte *nomeLidoPreenchido;
    int diagnostico;
    inicializarEstadoTelaNomes(&estado);
    estado.saidaNomeDoJogador1 = saidaNomeDoJogador1;
    estado.saidaNomeDoJogador2 = saidaNomeDoJogador2;
    while(1)
    {
        imprimirTelaNomes(&estado);
        estado.haErro = 1;
        if(!estado.nomeDoJogador1Preenchido)
        {
            nomeLido = estado.saidaNomeDoJogador1;
            nomeLidoPreenchido = &estado.nomeDoJogador1Preenchido;
        }
        else
        {
            nomeLido = estado.saidaNomeDoJogador2;
            nomeLidoPreenchido = &estado.nomeDoJogador2Preenchido;
        }
        diagnostico = lerLinha(nomeLido, TAM_MAX_NOME);
        if(diagnostico == 1)
        {
            estado.erro = "Entrada muito grande. Insira uma entrada menor.";
        }
        else
        {
            apararPontas(nomeLido, nomeLido);
            simplificarEspacos(nomeLido, nomeLido);
            if(ehVazia(nomeLido))
            {
                estado.erro = "O nome não pode ser vazio.";
            }
            else if(!ehIdentificadorValido(nomeLido))
            {
                estado.erro = "Nome inválido. Use apenas letras sem acento, números e espaços.";
            }
            else if(estado.nomeDoJogador1Preenchido && strcmp(saidaNomeDoJogador1, saidaNomeDoJogador2) == 0)
            {
                estado.erro = "Os nomes dos jogadores não podem ser iguais.";
            }
            else
            {
                *nomeLidoPreenchido = 1;
                estado.haErro = 0;
                if(estado.nomeDoJogador2Preenchido) break;
            }
        }
    }
}