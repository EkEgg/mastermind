#pragma once
#include "../fluxos/estruturas.h"
#include "../utilidades/tipos.h"

typedef struct
{
    CONFIGURACAO *configuracao;
    
    ushort *saidaOpcao;

    byte haErro;
    char *erro;
}
ESTADO_TELA_CONFIGURACAO;

void imprimirTelaConfiguracao(ESTADO_TELA_CONFIGURACAO *estado);

void executarTelaConfiguracao(CONFIGURACAO *configuracao, char *erroPrevio, ushort *saidaOpcao);