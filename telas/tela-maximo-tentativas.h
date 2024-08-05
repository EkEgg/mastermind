#pragma once
#include "../utilidades/tipos.h"

typedef struct
{
    ushort *saidaMaximoDeTentativas;

    byte haErro;
    char *erro;
}
ESTADO_TELA_MAXIMO_TENTATIVAS;

void inicializarEstadoTelaMaximoTentativas(ESTADO_TELA_MAXIMO_TENTATIVAS *estado);

void imprimirTelaMaximoTentativas(ESTADO_TELA_MAXIMO_TENTATIVAS *estado);

void executarTelaMaximoTentativas(ushort *saidaMaximoDeTentativas);