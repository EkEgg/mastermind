#include "entrada.h"
#include "strings.h"
#include "tipos.h"
#include <stdio.h>
#include <string.h>

void pularLinha(void)
{
    while(getchar() != '\n');
}

int lerLinha(char *saida, size_t maximoDeCaracteres)
{
    size_t lidos = 0;
    char c = getchar();
    while(c != '\n' && lidos < maximoDeCaracteres)
    {
        saida[lidos] = c;
        c = getchar();
        lidos++;
    }
    saida[lidos] = '\0';
    if(c != '\n')
    {
        pularLinha();
        return 1;
    }
    return 0;
}

int lerUShort(ushort *saida)
{
    char buffer[TAM_MAX_BUFFER_ENTRADA+1];
    if(lerLinha(buffer, TAM_MAX_BUFFER_ENTRADA)) return 1;
    apararPontas(buffer, buffer);
    if(!ehNumero(buffer)) return 2;
    sscanf(buffer, "%hu", saida);
    return 0;
}