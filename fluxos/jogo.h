#pragma once
#include "../utilidades/tipos.h"
#include "estruturas.h"

void executarJogo(CONFIGURACAO *configuracao);

void executarPartida(CONFIGURACAO *configuracao);

void executarRodada(CONFIGURACAO *configuracao, ESTADO_PARTIDA *estadoPartida);

void atribuirDicas(TENTATIVA *tentativa, char *senha, byte dicasEspecificamPosicao);

void executarConfiguracao(CONFIGURACAO *configuracao);