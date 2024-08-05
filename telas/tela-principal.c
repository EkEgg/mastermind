#include "tela-principal.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include <stdio.h>

void inicializarEstadoTelaPrincipal(ESTADO_TELA_PRINCIPAL *estado)
{
    estado->haErro = 0;
    estado->erro = "";
}

void imprimirTelaPrincipal(ESTADO_TELA_PRINCIPAL *estado)
{
    limparConsole();

    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERDE);
    puts(  ""                                                                           );
    puts(  "    ::::    :::::     :::      ::::::::: :::::::::: :::::::::: :::::::::"   );
    puts(  "    +:+:+: :+:+:+   :+: :+:   :+:    :+:    :+:     :+:        :+:    :+:"  );
    puts(  "    +:+ +:+:+ +:+  +:+   +:+  +:+           +:+     +:+        +:+    +:+"  );
    puts(  "    +#+  +:+  +#+ +#++:++#++: +#++:++#++    +#+     +#++:++#   +#++:++#:"   );
    puts(  "    +#+       +#+ +#+     +#+        +#+    +#+     +#+        +#+    +#+"  );
    puts(  "    #+#       #+# #+#     #+# #+#    #+#    #+#     #+#        #+#    #+#"  );
    puts(  "    ###       ### ###     ###  ########     ###     ########## ###    ###"  );
    definirAtributoGrafico(ATR_AZUL);
    puts(  "                         ::::    ::::: ::::::::::: ::::    ::: :::::::::"   );
    puts(  "                         +:+:+: :+:+:+     :+:     :+:+:   :+: :+:    :+:"  );
    puts(  "                         +:+ +:+:+ +:+     +:+     :+:+:+  +:+ +:+    +:+"  );
    puts(  "                         +#+  +:+  +#+     +#+     +#+ +:+ +#+ +#+    +:+"  );
    puts(  "                         +#+       +#+     +#+     +#+  +#+#+# +#+    +#+"  );
    puts(  "                         #+#       #+#     #+#     #+#   #+#+# #+#    #+#"  );
    puts(  "                         ###       ### ########### ###    #### #########"   );
    definirAtributoGrafico(ATR_REINICIAR);
    puts(  ""                                                                           );
    puts(  "    1. Iniciar"       );
    puts(  "    2. Instruções"    );
    puts(  "    3. Configurações" );
    puts(  "    4. Créditos"      );
    puts(  "    5. Sair"          );
    printf("    Escolha: "        );

    if(estado->haErro)
    {
        puts("");
        puts("");
        definirAtributoGrafico(ATR_VERMELHO);
        definirAtributoGrafico(ATR_NEGRITO);
        printf("    * %s\n", estado->erro);
        definirAtributoGrafico(ATR_REINICIAR);
        reposicionarCursor(22, 14);
    }
}

void executarTelaPrincipal(ushort *saidaOpcao)
{
    ESTADO_TELA_PRINCIPAL estado;
    int diagnostico;
    inicializarEstadoTelaPrincipal(&estado);
    estado.saidaOpcao = saidaOpcao;
    while(1)
    {
        imprimirTelaPrincipal(&estado);
        diagnostico = lerUShort(saidaOpcao);
        estado.haErro = 1;
        if(diagnostico == 1)
        {
            estado.erro = "Entrada muito grande. Insira uma entrada menor.";
        }
        else if(diagnostico == 2)
        {
            estado.erro = "Entrada inválida. Insira um número inteiro sem sinal.";
        }
        else if(*saidaOpcao < 1 || *saidaOpcao > 5)
        {
            estado.erro = "Entrada inválida. Insira uma das opções.";
        }
        else
        {
            estado.haErro = 0;
            break;
        }
    }
}