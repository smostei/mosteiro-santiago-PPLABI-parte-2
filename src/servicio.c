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
