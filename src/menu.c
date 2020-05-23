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
	printf("J) Informes\n");
	printf("K) Salir\n");


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

int menuInformes() {
	printf("\n\n");
    printf("------Menu informes------\n\n");

    int opcion;

    printf("1) Mostrar las mascotas de un color seleccionado\n");
    printf("2) Mostrar las mascotas del tipo seleccionado\n");
    printf("3) Informar la/s mascotas mas jovenes\n");
    printf("4) Mostrar un listado de mascotas separadas por tipo\n");
    printf("5) Mostrar la cantidad de mascotas segun el tipo y color\n");
    printf("6) Informar los colores mas populares en las mascotas del Sistema (las mas lo tengan)\n");
    printf("7) Mostrar todos los trabajos que se le hicieron a una mascota seleccionada\n");
    printf("8) Mostrar la suma de los importes de servicios que se le hicieron a una mascota seleccionada\n");
    printf("9) Mostrar fecha y mascotas segun un servicio seleccionado\n");
    printf("10) Mostrar todos los servicios segun la fecha seleccionada\n");
    printf("11) Salir de informes\n\n");


	printf("Ingresa el informe que queres ver: ");
	scanf("%d", &opcion);

    return opcion;
}
