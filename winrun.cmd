@echo off

set nome-do-executavel=mastermind

:: Página de código de UTF-8 necessária para executar o jogo.
set pagina-de-codigo-correta=65001

:: Determina a página de código atual do usuário para retornar a ela após a execução do jogo.
for /f "tokens=*" %%i in ('chcp') do set chcp-string=%%i
for %%i in (%chcp-string%) do set pagina-de-codigo-anterior=%%i

chcp %pagina-de-codigo-correta%
%nome-do-executavel%
chcp %pagina-de-codigo-anterior%
