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

void cargarDescripcionColor(int idColor, char* descripcion) {
	switch(idColor) {
		case 5000:
			strcpy(descripcion, "Negro");
		break;

		case 5001:
			strcpy(descripcion, "Blanco");
		break;

		case 5002:
			strcpy(descripcion, "Gris");
		break;

		case 5003:
			strcpy(descripcion, "Rojo");
		break;

		default:
			strcpy(descripcion, "Azul");
	}
}
