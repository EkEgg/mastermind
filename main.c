#include "fluxos/jogo.h"
#include "fluxos/arquivos.h"
#include "fluxos/estruturas.h"
#include "utilidades/console.h"

int main(void)
{
    CONFIGURACAO configuracao;
    carregarConfiguracao(&configuracao);
    executarJogo(&configuracao);
    limparConsole();
    return 0;
}