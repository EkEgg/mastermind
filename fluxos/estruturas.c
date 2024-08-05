#include "estruturas.h"
#include "../utilidades/strings.h"
#include <stdlib.h>

void definirConfiguracaoPadrao(CONFIGURACAO *saidaConfiguracao)
{
    saidaConfiguracao->tamanhoDaSenha = TAMANHO_DA_SENHA_PADRAO;
    saidaConfiguracao->maximoDeTentativas = MAXIMO_DE_TENTATIVAS_PADRAO;
    saidaConfiguracao->dicasEspecificamPosicao = DICAS_ESPECIFICAM_POSICAO_PADRAO;
    saidaConfiguracao->permitirLetrasRepetidas = PERMITIR_LETRAS_REPETIDAS_PADRAO;
    saidaConfiguracao->permitirAlfabetoInteiro = PERMITIR_ALFABETO_INTEIRO_PADRAO;
}

void trocarPonteirosDeJogadores(JOGADOR **a, JOGADOR **b)
{
    JOGADOR *c = *a;
    *a = *b;
    *b = c;
}

TENTATIVA *novaTentativa(ushort tamanhoDaSenha)
{
    TENTATIVA *tentativa = (TENTATIVA*) malloc(sizeof(TENTATIVA));
    tentativa->tentativa = novaString(tamanhoDaSenha);
    tentativa->dicas = novaString(tamanhoDaSenha);
    tentativa->proxima = NULL;
    return tentativa;
}

void excluirTentativa(TENTATIVA *tentativa)
{
    free(tentativa->tentativa);
    free(tentativa->dicas);
    free(tentativa);
}

void inicializarListaDeTentativas(LISTA_DE_TENTATIVAS *lista)
{
    lista->primeira = NULL;
    lista->ultima = NULL;
    lista->tamanho = 0;
}

void adicionarTentativaNoInicio(LISTA_DE_TENTATIVAS *lista, TENTATIVA *tentativa)
{
    tentativa->proxima = lista->primeira;
    lista->primeira = tentativa;
    lista->tamanho++;
    if(lista->tamanho == 1) lista->ultima = tentativa;
}

void adicionarTentativaNoFinal(LISTA_DE_TENTATIVAS *lista, TENTATIVA *tentativa)
{
    if(lista->ultima == NULL) adicionarTentativaNoInicio(lista, tentativa);
    else
    {
        lista->ultima->proxima = tentativa;
        tentativa->proxima = NULL;
        lista->ultima = tentativa;
        lista->tamanho++;
    }
}

void removerTentativaNoInicio(LISTA_DE_TENTATIVAS *lista)
{
    TENTATIVA *tentativa = lista->primeira;
    if(tentativa == NULL) return;
    lista->primeira = tentativa->proxima;
    lista->tamanho--;
    if(lista->tamanho == 0) lista->ultima = NULL;
    excluirTentativa(tentativa);
}

void removerTodasAsTentativas(LISTA_DE_TENTATIVAS *lista)
{
    while(possuiTentativas(lista))
    {
        removerTentativaNoInicio(lista);
    }
}

int possuiTentativas(LISTA_DE_TENTATIVAS *lista)
{
    return lista->primeira != NULL;
}