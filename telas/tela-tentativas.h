#pragma once
#include "../utilidades/tipos.h"
#include "../fluxos/estruturas.h"

typedef struct
{
    char *nomeDoQuebrador;
    CONFIGURACAO *configuracao;
    LISTA_DE_TENTATIVAS *tentativas;
    char *senha;
    
    char *saidaTentativa;

    byte tipoDeErro;
}
ESTADO_TELA_TENTATIVAS;

void inicializarEstadoTelaTentativas(ESTADO_TELA_TENTATIVAS *estado);

void imprimirTentativa(char *tentativa, byte permitirAlfabetoInteiro);

void imprimirDicas(char *dicas);

void imprimirTelaTentativas(ESTADO_TELA_TENTATIVAS *estado);

void executarTelaTentativas(CONFIGURACAO *configuracao, char *nomeDoQuebrador, char *senha, LISTA_DE_TENTATIVAS *tentativas, char *saidaTentativa);