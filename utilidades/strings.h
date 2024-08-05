#pragma once

#include <stddef.h>

void emCaixaAlta(char *destino, char *origem);

void apararPontas(char *destino, char *origem);

void simplificarEspacos(char *destino, char *origem);

int ehVazia(char *string);

int ehNumero(char *string);

int contemRepeticao(char *string);

int estahEmIntervalo(char *string, char minimo, char maximo);

char *novaString(size_t numeroDeCaracteres);

int ehIdentificadorValido(char *string);