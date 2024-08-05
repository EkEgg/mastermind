#include "tela-senha.h"
#include "../utilidades/tipos.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include "../utilidades/strings.h"
#include <stdio.h>
#include <string.h>

void inicializarEstadoTelaSenha(ESTADO_TELA_SENHA *estado)
{
    estado->tipoDeErro = 0;
}

void imprimirTelaSenha(ESTADO_TELA_SENHA *estado)
{
    limparConsole();
    puts("");

    printf("    ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERDE);
    printf("%s", estado->nomeDoCriador);
    definirAtributoGrafico(ATR_REINICIAR);
    printf(", você é o ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_AZUL);
    printf("criador");
    definirAtributoGrafico(ATR_REINICIAR);
    puts(". Insira a senha.");
    
    puts("");
    printf("    Senha: ");
    if(estado->tipoDeErro)
    {
        puts("");
        puts("");
        definirAtributoGrafico(ATR_VERMELHO);
        definirAtributoGrafico(ATR_NEGRITO);
        printf("    * ");
        switch(estado->tipoDeErro)
        {
            case 1: printf("A senha deve ter %hu letras.\n", estado->configuracao->tamanhoDaSenha); break;
            case 2: printf("A senha deve conter apenas letras de A a %c.\n", estado->configuracao->permitirAlfabetoInteiro ? 'Z' : 'F'); break;
            case 3: printf("A senha não deve ter letras repetidas.\n"); break;
        }
        definirAtributoGrafico(ATR_REINICIAR);
        reposicionarCursor(4, 12);
    }
}

void executarTelaSenha(CONFIGURACAO *configuracao, char *nomeDoCriador, char *saidaSenha)
{
    ESTADO_TELA_SENHA estado;
    int diagnostico;
    inicializarEstadoTelaSenha(&estado);
    estado.saidaSenha = saidaSenha;
    estado.nomeDoCriador = nomeDoCriador;
    estado.configuracao = configuracao;
    while(1)
    {
        imprimirTelaSenha(&estado);
        diagnostico = lerLinha(estado.saidaSenha, estado.configuracao->tamanhoDaSenha);
        if(diagnostico == 1 || strlen(estado.saidaSenha) < estado.configuracao->tamanhoDaSenha)
        {
            estado.tipoDeErro = 1;
        }
        else
        {
            emCaixaAlta(estado.saidaSenha, estado.saidaSenha);
            if(!estahEmIntervalo(estado.saidaSenha, 'A', estado.configuracao->permitirAlfabetoInteiro ? 'Z' : 'F'))
            {
                estado.tipoDeErro = 2;
            }
            else if(!estado.configuracao->permitirLetrasRepetidas && contemRepeticao(estado.saidaSenha))
            {
                estado.tipoDeErro = 3;
            }
            else
            {
                estado.tipoDeErro = 0;
                break;
            }
        }
    }
}