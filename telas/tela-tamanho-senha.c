#include "tela-tamanho-senha.h"
#include "../utilidades/tipos.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include <stdio.h>

void inicializarEstadoTelaTamanhoSenha(ESTADO_TELA_TAMANHO_SENHA *estado)
{
    estado->haErro = 0;
    estado->erro = "";
}

void imprimirTelaTamanhoSenha(ESTADO_TELA_TAMANHO_SENHA *estado)
{
    limparConsole();
    puts("");
    puts("    Insira o tamanho da senha.");
    puts("");
    printf("    Tamanho da senha: ");
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

void executarTelaTamanhoSenha(ushort *saidaTamanhoDaSenha)
{
    ESTADO_TELA_TAMANHO_SENHA estado;
    int diagnostico;
    inicializarEstadoTelaTamanhoSenha(&estado);
    estado.saidaTamanhoDaSenha = saidaTamanhoDaSenha;
    while(1)
    {
        imprimirTelaTamanhoSenha(&estado);
        diagnostico = lerUShort(estado.saidaTamanhoDaSenha);
        estado.haErro = 1;
        if(diagnostico == 1)
        {
            estado.erro = "Entrada muito grande. Insira uma entrada menor.";
        }
        else if(diagnostico == 2)
        {
            estado.erro = "Entrada inválida. Insira um número inteiro sem sinal.";
        }
        else if(*estado.saidaTamanhoDaSenha == 0)
        {
            estado.erro = "O tamanho da senha não pode ser 0.";
        }
        else
        {
            estado.haErro = 0;
            break;
        }
    }
}