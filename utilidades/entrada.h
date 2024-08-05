#pragma once
#include <stddef.h>
#include "tipos.h"

#define TAM_MAX_BUFFER_ENTRADA 30

void pularLinha(void);

int lerLinha(char *saida, size_t maximoDeCaracteres);

int lerUShort(ushort *saida);