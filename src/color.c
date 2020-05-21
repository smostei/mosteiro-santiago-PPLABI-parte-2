#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

void listarColores(sColor* colores, int longColores) {
	printf("----------Listado de colores----------\n\n");

	printf("ID           Nombre del color\n\n");

	for(int i = 0; i < longColores; i++) {
		printf("%d        %10s\n", colores[i].id, colores[i].nombreColor);
	}
}
