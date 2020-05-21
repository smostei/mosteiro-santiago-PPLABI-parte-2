#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringutils.h"
#include <ctype.h>

void concatenarNombreYApellido(char* nombre, char* apellido, char* nombreCompleto) {
    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwrLinux(nombreCompleto);
    nombreCompleto[0] = (char) toupper(nombreCompleto[0]);

    for(int i = 0; i < strlen(nombreCompleto); i++) {
        if(nombreCompleto[i] == ' ') {
            nombreCompleto[i+1] = (char) toupper(nombreCompleto[i+1]);
        }
    }
}

void strlwrLinux(char* cadena) {
    int i = 0;

    while(cadena[i] != '\0') {
        cadena[i] = (char) tolower(cadena[i]);
        i++;
    }
}

