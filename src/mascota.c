#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "cliente.h"

void initMascotas(sMascota* mascotas, int longMascotas) {
    for(int i = 0; i < longMascotas; i++) {
        mascotas[i].isEmpty = 1; //va a significar que este elemento del array esta desocupado
    }
}


void mostrarMascota(sMascota mascota, sCliente* clientes, int longClientes) {

	char mascotaTipo[20];
	char mascotaColor[20];
	int indiceDuenio = buscarClientePorId(clientes, longClientes, mascota.idCliente);

	cargarDescripcionTipo(mascota.idTipo, mascotaTipo);
	cargarDescripcionColor(mascota.idColor, mascotaColor);

	printf("%d     %10s     %10s      %10s     %d       %s\n",
			mascota.id,
			mascota.nombre,
			mascotaTipo,
			mascotaColor,
			mascota.edad,
			clientes[indiceDuenio].nombre);
}


void mostrarMascotas(sMascota* mascotas, int longMascotas, sCliente* clientes, int longClientes) {
    printf("\n------Lista de mascotas--------\n\n");

	printf("ID        Nombre          Tipo            Color    Edad       Nombre del duenio\n\n");

    int flag = 0;

    for(int i = 0; i < longMascotas; i++) {
    	if(!mascotas[i].isEmpty) {
    		mostrarMascota(mascotas[i], clientes, longClientes);
            flag = 1;
        }
    }

    if(!flag)
    	printf("\nNo hay mascotas para mostrar\n");
}


int altaMascota(sMascota* mascotas, int longMascotas, int proximoId, sTipo* tipos, sColor* colores, int longitud, sCliente* clientes, int longClientes) {
		int retorno = 0;

	 	sMascota mascota;
	    int lugarLibre = buscarLibre(mascotas, longMascotas);

	    if(lugarLibre != -1) {
	            mascota.id = proximoId;

	            printf("Ingrese el nombre de la mascota: \n");
	            fflush(stdin);
	            gets(mascota.nombre);

	            printf("Ingrese el tipo de la mascota: \n");
	            listarTipos(tipos, longitud);
	            scanf("%d", &mascota.idTipo);

                while(mascota.idTipo < 1000 || mascota.idTipo > 1004) {
                	printf("Error. Ingresar Tipo nuevamente: \n");
                    scanf("%d", &mascota.idTipo);
                }

	            printf("Ingrese el color de la mascota: \n");
	            listarColores(colores, longitud);
	            scanf("%d", &mascota.idColor);

                while(mascota.idColor < 5000 || mascota.idColor > 5004) {
                	printf("Error. Ingresar color nuevamente: \n");
                    scanf("%d", &mascota.idColor);
                }

	            printf("Ingrese la edad de la mascota: \n");
	            scanf("%d", &mascota.edad);

                while(mascota.edad < 1) {
                	printf("Error. Ingresar edad nuevamente: \n");
                    scanf("%d", &mascota.edad);
                }

	            printf("Ingrese el ID del duenio de la mascota: \n");
	            mostrarClientes(clientes, longClientes);
	            scanf("%d", &mascota.idCliente);

	        	int indiceDuenio = buscarClientePorId(clientes, longClientes, mascota.idCliente);

	        	while(indiceDuenio == -1) {
		            printf("No existe un duenio con ese ID\nIngreselo nuevamente: \n");
		            scanf("%d", &mascota.idCliente);

		            indiceDuenio = buscarClientePorId(clientes, longClientes, mascota.idCliente);
	        	}

	            mascota.isEmpty = 0;

	            mascotas[lugarLibre] = mascota;

	            printf("Mascota dada de alta con exito!\n\n");

	            retorno = 1;

	        } else printf("El sistema de mascotas ya esta completo!\n\n");

	    return retorno;
}


void modificarMascota(sMascota* mascotas, int longMascotas, sTipo* tipos, sColor* colores, int longitud, sCliente* clientes, int longClientes) {
    int indice;
    int id;
    char respuesta;

    printf("Ingrese el id de la mascota a modificar: \n");
    mostrarMascotas(mascotas, longMascotas, clientes, longClientes);
    scanf("%d", &id);

    indice = buscarMascota(mascotas, id, longMascotas);

    if(indice != -1) {
        mostrarMascota(mascotas[indice], clientes, longClientes);

        printf("Queres modificar a esta mascota? s/n\n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
            manejarModificacionMascota(&mascotas[indice], tipos, longitud);
        else
        	printf("Se ha cancelado la operacion\n");

    } else printf("No existe una mascota con el ID %d\n", id);
}

void manejarModificacionMascota(sMascota* mascota, sTipo* tipos, int longTipos) {
    char confirmarCampo = 's';

    do {
        switch(menuModificacionMascota()) {
            case 1:
                printf("Ingrese el nuevo tipo:\n");
                listarTipos(tipos, longTipos);
                scanf("%d", &mascota->idTipo);

                while(mascota->idTipo < 1000 || mascota->idTipo > 1004) {
                	printf("Error. Ingresar Tipo nuevamente: \n");
                    scanf("%d", &mascota->idTipo);
                }

                printf("Se ha modificado el tipo con exito!\n\n");

                break;
            case 2:
                printf("Ingrese la nueva edad:\n");
                scanf("%d", &mascota->edad);

                while(mascota->edad < 0) {
                	printf("La edad no puede ser <= 0. Ingresarla nuevamente: \n");
                    scanf("%d", &mascota->edad);
                }
                break;
            case 3:
            	confirmarCampo = 'n';
            	break;
            default:
                printf("Opcion invalida, ingresar nuevamente el campo a modificar\n");
        }
    } while(confirmarCampo == 's');

    printf("Mascota modificada con exito!\n");
}

void bajaMascota(sMascota* mascotas, int longMascotas, sTipo* tipos, sColor* colores, int longitud, sCliente* clientes, int longClientes) {
    int indice;
    int id;
    char respuesta;

    printf("Ingrese el ID de la mascota: \n");
    mostrarMascotas(mascotas, longMascotas, clientes, longClientes);
    scanf("%d", &id);

    indice = buscarMascota(mascotas, id, longMascotas);

    if(indice != -1) {
        mostrarMascota(mascotas[indice], clientes, longClientes);

        printf("Estas seguro/a que queres dar de baja a la mascota? s/n\n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's') {
            mascotas[indice].isEmpty = 1;
            printf("Mascota dada de baja con exito!\n");
        } else
        	printf("Se ha cancelado la operacion\n");

    } else printf("No existe una mascota con el ID %d\n", id);
}

int buscarMascota(sMascota* mascotas, int id, int longMascotas) {
    int indice = -1;

    for(int i = 0; i < longMascotas; i++) {
        if(mascotas[i].id == id && !mascotas[i].isEmpty) {
            indice = i;
            break;
        }
    }

    return indice;
}


int buscarLibre(sMascota* mascotas, int longMascotas) {
    int indice = -1;

    for(int i = 0; i < longMascotas; i++) {
        if(mascotas[i].isEmpty) {
            indice = i;
            break;
        }
    }

    return indice;
}

int hayMascotas(sMascota* mascotas, int longMascotas) {
	int retorno = 0;

    for(int i = 0; i < longMascotas; i++) {
        if(!mascotas[i].isEmpty)
            retorno = 1;
    }

    return retorno;
}

void ordenarMascotasPorTipoYNombre(sMascota* mascotas, int longMascotas, sCliente* clientes, int longClientes) {
    sMascota auxMascota;

    for(int i = 0; i < longMascotas - 1; i++) {
        for(int j = i + 1; j < longMascotas; j++) {
            if(mascotas[i].idTipo > mascotas[j].idTipo) {
                auxMascota = mascotas[i];
                mascotas[i] = mascotas[j];
                mascotas[j] = auxMascota;

                if(mascotas[i].idTipo == mascotas[j].idTipo && strcmp(mascotas[i].nombre, mascotas[j].nombre) > 0) {
             	   auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
            }
        }
    }



    mostrarMascotas(mascotas, longMascotas, clientes, longClientes);
}

