#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "validaciones.h"

int esNombreValido(const char* texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (!isalpha(texto[i])) {
            return 0;
        }
    }
    return 1;
}

int esNumeroValido(const char* texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (!isdigit(texto[i])) {
            return 0;
        }
    }
    return 1;
}

int esPlacaValida(const char* placa) {
    int len = strlen(placa);
    if (len != 7) return 0;

    for (int i = 0; i < 3; i++) {
        if (!isalpha(placa[i])) return 0;
    }

    for (int i = 3; i < 7; i++) {
        if (!isdigit(placa[i])) return 0;
    }

    return 1;
}