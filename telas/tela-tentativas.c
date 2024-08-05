#include "tela-tentativas.h"
#include "../utilidades/tipos.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include "../utilidades/strings.h"
#include <stdio.h>
#include <string.h>

void inicializarEstadoTelaTentativas(ESTADO_TELA_TENTATIVAS *estado)
{
    estado->tipoDeErro = 0;
}

void imprimirTentativa(char *tentativa, byte permitirAlfabetoInteiro)
{
    ushort i;
    unsigned atributo;
    if(permitirAlfabetoInteiro) printf("%s", tentativa);
    else
    {
        definirAtributoGrafico(ATR_NEGRITO);
        for(i = 0; tentativa[i] != '\0'; i++)
        {
            switch(tentativa[i])
            {
                case 'A': atributo = ATR_VERMELHO; break;
                case 'B': atributo = ATR_VERDE;    break;
                case 'C': atributo = ATR_MARROM;   break;
                case 'D': atributo = ATR_AZUL;     break;
                case 'E': atributo = ATR_MAGENTA;  break;
                case 'F': atributo = ATR_CIANO;    break;
                default:  atributo = ATR_BRANCO;   break;
            }
            definirAtributoGrafico(atributo);
            putchar(tentativa[i]);
        }
        definirAtributoGrafico(ATR_REINICIAR);
    }
}

void imprimirDicas(char *dicas)
{
    ushort i;
    unsigned atributo;
    definirAtributoGrafico(ATR_NEGRITO);
    for(i = 0; dicas[i] != '\0'; i++)
    {
        switch(dicas[i])
        {
            case '*': atributo = ATR_VERDE;    break;
            case '~': atributo = ATR_AZUL;     break;
            case '.': atributo = ATR_VERMELHO; break;
            default:  atributo = ATR_BRANCO;   break;
        }
        definirAtributoGrafico(atributo);
        putchar(dicas[i]);
    }
    definirAtributoGrafico(ATR_REINICIAR);
}

void imprimirTelaTentativas(ESTADO_TELA_TENTATIVAS *estado)
{
    TENTATIVA *tentativa;
    byte terminou, acertouASenha;
    ushort tentativasRestantes = estado->configuracao->maximoDeTentativas - estado->tentativas->tamanho;
    limparConsole();
    puts("");
    printf("    ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERDE);
    printf("%s", estado->nomeDoQuebrador);
    definirAtributoGrafico(ATR_REINICIAR);
    printf(", você é o ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERMELHO);
    printf("quebrador");
    definirAtributoGrafico(ATR_REINICIAR);
    puts(". Tente adivinhar a senha.");
    puts("");
    if(tentativasRestantes == 0) puts("    Acabaram as tentativas.");
    else
    {
        printf("    Resta%s ", tentativasRestantes > 1 ? "m" : "");
        definirAtributoGrafico(ATR_NEGRITO);
        printf("%hu", tentativasRestantes);
        definirAtributoGrafico(ATR_REINICIAR);
        printf(" tentativa%s.\n", tentativasRestantes > 1 ? "s" : "");
    }
    puts("");
    printf("    Tentativas: ");
    for(tentativa = estado->tentativas->primeira; tentativa != NULL; tentativa = tentativa->proxima)
    {
        imprimirTentativa(tentativa->tentativa, estado->configuracao->permitirAlfabetoInteiro);
        putchar(' ');
        imprimirDicas(tentativa->dicas);
        puts("");
        printf("                ");
    }
    acertouASenha = estado->tentativas->tamanho > 0 && strcmp(estado->tentativas->ultima->tentativa, estado->senha) == 0;
    terminou = estado->tentativas->tamanho == estado->configuracao->maximoDeTentativas || acertouASenha;
    if(terminou)
    {
        puts("");
        printf("         Senha: ");
        imprimirTentativa(estado->senha, estado->configuracao->permitirAlfabetoInteiro);
        puts("");
        puts("");

        definirAtributoGrafico(ATR_NEGRITO);
        if(acertouASenha)
        {
            definirAtributoGrafico(ATR_VERDE);
            puts("    Você acertou a senha.");
        }
        else
        {
            definirAtributoGrafico(ATR_VERMELHO);
            puts("    Você não acertou a senha.");
        }
        definirAtributoGrafico(ATR_REINICIAR);
        puts("");

        printf("    Pressione ");
        definirAtributoGrafico(ATR_NEGRITO);
        printf("[ENTER]");
        definirAtributoGrafico(ATR_REINICIAR);
        printf(" para continuar. ");
    }
    else if(estado->tipoDeErro)
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
        reposicionarCursor(6 + estado->tentativas->tamanho, 17);
    }
}

void executarTelaTentativas(CONFIGURACAO *configuracao, char *nomeDoQuebrador, char *senha, LISTA_DE_TENTATIVAS *tentativas, char *saidaTentativa)
{
    ESTADO_TELA_TENTATIVAS estado;
    int diagnostico;
    byte acertouASenha, terminou;
    inicializarEstadoTelaTentativas(&estado);
    estado.tentativas = tentativas;
    estado.nomeDoQuebrador = nomeDoQuebrador;
    estado.senha = senha;
    estado.configuracao = configuracao;
    estado.saidaTentativa = saidaTentativa;
    while(1)
    {
        imprimirTelaTentativas(&estado);
        acertouASenha = estado.tentativas->tamanho > 0 && strcmp(estado.tentativas->ultima->tentativa, estado.senha) == 0;
        terminou = estado.tentativas->tamanho == estado.configuracao->maximoDeTentativas || acertouASenha;
        if(!terminou)
        {
            diagnostico = lerLinha(estado.saidaTentativa, estado.configuracao->tamanhoDaSenha);
            if(diagnostico == 1 || strlen(estado.saidaTentativa) < estado.configuracao->tamanhoDaSenha)
            {
                estado.tipoDeErro = 1;
            }
            else
            {
                emCaixaAlta(estado.saidaTentativa, estado.saidaTentativa);
                if(!estahEmIntervalo(estado.saidaTentativa, 'A', estado.configuracao->permitirAlfabetoInteiro ? 'Z' : 'F'))
                {
                    estado.tipoDeErro = 2;
                }
                else if(!estado.configuracao->permitirLetrasRepetidas && contemRepeticao(estado.saidaTentativa))
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
        else
        {
            pularLinha();
            estado.tipoDeErro = 0;
            break;
        }
    }
}