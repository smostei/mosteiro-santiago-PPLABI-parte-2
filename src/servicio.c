#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void listarServicios(sServicio* servicios, int longServicios) {
	printf("----------Listado de Servicios----------\n\n");

	printf("ID           Descripcion           Precio\n\n");

	for(int i = 0; i < longServicios; i++) {
		printf("%d        %13s        %.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
	}
}

void listarServicio(sServicio servicio) {
	printf("%d        %13s        %.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

int buscarServicioPorId(sServicio* servicios, int longServicios, int id) {
	int respuesta = -1;

	for(int i = 0; i < longServicios; i++) {
		if(servicios[i].id == id) {
			respuesta = i;
			break;
		}
	}

	return respuesta;
}

void cargarDescripcionServicio(int idServicio, char* descripcion) {
	switch(idServicio) {
		case 20000:
			strcpy(descripcion, "Corte");
			break;

		case 20001:
			strcpy(descripcion, "Desparasitado");
			break;

		default:
			strcpy(descripcion, "Castrado");
			break;
	}
}
