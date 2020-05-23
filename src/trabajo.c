#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "mascota.h"
#include "servicio.h"
#include "fecha.h"
#include "cliente.h"

void initTrabajos(sTrabajo* trabajos, int longTrabajos) {
    for(int i = 0; i < longTrabajos; i++) {
        trabajos[i].isEmpty = 1;
    }
}


int altaTrabajo(sTrabajo* trabajos,
		int longTrabajos,
		int proximoId,
		sMascota* mascotas,
		int longMascotas,
		sServicio* servicios,
		int longServicios,
		sCliente* clientes,
		int longClientes) {

	int retorno = 0;

 	sTrabajo trabajo;
    int lugarLibre = buscarLibreTrabajos(trabajos, longTrabajos);

    if(lugarLibre != -1) {
            trabajo.id = proximoId;

            mostrarMascotas(mascotas, longMascotas, clientes, longClientes);
            printf("\nIngrese el ID de la mascota para el trabajo: \n");
            scanf("%d", &trabajo.idMascota);

            while(buscarMascota(mascotas, trabajo.idMascota, longMascotas) == -1) {
                printf("el ID ingresado no pertenece a una de las mascotas, ingresalo nuevamente:\n");
                scanf("%d", &trabajo.idMascota);
            }

            printf("Ingrese el ID del servicio que vas a brindarle: \n");
            listarServicios(servicios, longServicios);
            scanf("%d", &trabajo.idServicio);

            while(trabajo.idServicio < 20000 || trabajo.idServicio > 20002) {
                printf("el ID ingresado no pertenece a uno de nuestros servicios, ingresalo nuevamente\n");
                scanf("%d", &trabajo.idServicio);
            }

            printf("Ingrese la fecha del trabajo: dd/mm/aaaa\n");
            scanf("%d/%d/%d", &trabajo.fecha.dia, &trabajo.fecha.mes, &trabajo.fecha.anio);

            while(!esUnaFechaCorrecta(trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio)) {
                printf("La fecha ingresada es incorrecta, reintentar: dd/mm/aaaa\n");
                scanf("%d/%d/%d", &trabajo.fecha.dia, &trabajo.fecha.mes, &trabajo.fecha.anio);
            }

            trabajo.isEmpty = 0;

            trabajos[lugarLibre] = trabajo;

            printf("Trabajo dado de alta con exito!\n\n");

            retorno = 1;

        } else printf("Los trabajos estan completos!\n\n");

    return retorno;
}

int buscarLibreTrabajos(sTrabajo* trabajos, int longTrabajos) {
    int indice = -1;

    for(int i = 0; i < longTrabajos; i++) {
        if(trabajos[i].isEmpty) {
            indice = i;
            break;
        }
    }

    return indice;
}

int hayTrabajos(sTrabajo* trabajos, int longTrabajos) {
	int retorno = 0;

    for(int i = 0; i < longTrabajos; i++) {
        if(!trabajos[i].isEmpty)
            retorno = 1;
    }

    return retorno;
}


void mostrarTrabajo(sTrabajo trabajo) {
	char descripcionServicio[20];
	cargarDescripcionServicio(trabajo.idServicio, descripcionServicio);

	if(!trabajo.isEmpty)
		printf("%d       %d            %d    %15s  %02d/%02d/%d\n",
				trabajo.id,
				trabajo.idMascota,
				trabajo.idServicio,
				descripcionServicio,
				trabajo.fecha.dia,
				trabajo.fecha.mes,
				trabajo.fecha.anio);
}


void mostrarTrabajos(sTrabajo* trabajos, int longTrabajos) {
    printf("\n------Lista de trabajos--------\n\n");

	printf("ID    ID Mascota   ID Servicio    Servicio       Fecha\n\n");

    int flag = 0;

    for(int i = 0; i < longTrabajos; i++) {
    	if(!trabajos[i].isEmpty) {
    		mostrarTrabajo(trabajos[i]);
            flag = 1;
        }
    }

    if(!flag) printf("\nNo hay trabajos para mostrar\n");
}

