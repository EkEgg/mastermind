#pragma once
#include "../utilidades/tipos.h"

typedef struct
{
    char *nomeDoVencedor;
}
ESTADO_TELA_VENCEDOR;

void imprimirTelaVencedor(ESTADO_TELA_VENCEDOR *estado);

void executarTelaVencedor(char *nomeDoVencedor);