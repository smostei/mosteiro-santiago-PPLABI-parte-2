#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

char menuPrincipal() {
	char opcion;

	printf("A) Alta de mascota\n");
	printf("B) Modificar mascota\n");
	printf("C) Baja de mascota\n");
	printf("D) Listar mascotas\n");
	printf("E) Listar tipos disponibles\n");
	printf("F) Listar colores disponibles\n");
	printf("G) Listar servicios disponibles\n");
	printf("H) Alta de trabajo\n");
	printf("I) Listar trabajos\n");
	printf("J) Salir\n\n");


	printf("Elige una opcion: ");
	fflush(stdin);
	scanf("%c", &opcion);

	return opcion;
}


int menuModificacionMascota() {
    printf("------Selecciona el atributo a modificar------\n");
    printf("1) Tipo\n");
    printf("2) Edad\n");
    printf("3) Salir de modificacion\n");

    int resultado;
    fflush(stdin);
    scanf("%d", &resultado);

    return resultado;
}
