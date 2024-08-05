#include "arquivos.h"
#include "../utilidades/tipos.h"
#include <stdio.h>

void carregarConfiguracao(CONFIGURACAO *saidaConfiguracao)
{
    byte naoConseguiuLer = 0;
    FILE *arquivo = fopen(CAMINHO_ARQUIVO_CONFIGURACAO, "rb");
    if(arquivo == NULL) naoConseguiuLer = 1;
    else
    {
        if(fread(saidaConfiguracao, sizeof(CONFIGURACAO), 1, arquivo) < 1)
        {
            naoConseguiuLer = 1;
        }
        fclose(arquivo);
    }
    if(naoConseguiuLer)
    {
        definirConfiguracaoPadrao(saidaConfiguracao);
        salvarConfiguracao(saidaConfiguracao);
    }
}

void salvarConfiguracao(CONFIGURACAO *configuracao)
{
    FILE *arquivo = fopen(CAMINHO_ARQUIVO_CONFIGURACAO, "wb");
    if(arquivo != NULL)
    {
        fwrite(configuracao, sizeof(CONFIGURACAO), 1, arquivo);
        fclose(arquivo);
    }
}