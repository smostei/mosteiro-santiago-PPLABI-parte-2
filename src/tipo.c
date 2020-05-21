#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

void listarTipos(sTipo* tipos, int longitudTipos) {
	printf("----------Listado de tipos----------\n\n");

	printf("ID           Descripcion\n\n");

	for(int i = 0; i < longitudTipos; i++) {
		printf("%d        %10s\n", tipos[i].id, tipos[i].descripcion);
	}
}
