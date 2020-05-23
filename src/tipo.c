#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#include <string.h>

void listarTipos(sTipo* tipos, int longitudTipos) {
	printf("----------Listado de tipos----------\n\n");

	printf("ID           Descripcion\n\n");

	for(int i = 0; i < longitudTipos; i++) {
		printf("%d        %10s\n", tipos[i].id, tipos[i].descripcion);
	}
}

void cargarDescripcionTipo(int idTipo, char* descripcion) {
	switch(idTipo) {
		case 1000:
			strcpy(descripcion, "Ave");
		break;

		case 1001:
			strcpy(descripcion, "Perro");
		break;

		case 1002:
			strcpy(descripcion, "Gato");
		break;

		case 1003:
			strcpy(descripcion, "Roedor");
		break;

		default:
			strcpy(descripcion, "Pez");
	}
}
