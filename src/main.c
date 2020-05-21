#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "trabajo.h"
#include "servicio.h"
#include "fecha.h"
#include "datahardcoded.h"
#include "ctype.h"

#define TAM_MASCOTA 10
#define TAM_TRABAJO 10

#define TAM 5
#define TAM_SERVICIOS 3
#define TAM_DESCRIPCION_SERVICIOS 25
#define TAM_DESCRIPCION 20

int main() {

	//Loop -----------
	char seguir = 's';
	char confirmaSalir;
	//----------------

	//Data
	sMascota mascotas[TAM_MASCOTA] = {};

	sTrabajo trabajos[TAM_TRABAJO] = {};

	int proxIdMascota = 0;
	int proxIdTrabajos = 0;

	//Llenar tipos, colores, servicios -----------
	sTipo tipos[TAM] = {};
	sColor colores[TAM] = {};
	sServicio servicios[TAM_SERVICIOS] = {};

 	for(int i = 0; i < TAM; i++) {
 		tipos[i].id = idsTipos[i];
 		strcpy(tipos[i].descripcion, descripcionTipos[i]);

 		colores[i].id = idsColores[i];
 		strcpy(colores[i].nombreColor, nombreColores[i]);

 		if(i < TAM_SERVICIOS) {
 	 		servicios[i].id = idsServicios[i];
 	 		strcpy(servicios[i].descripcion, descripcionServicios[i]);
 	 		servicios[i].precio = precios[i];
 		}
	}
	//----------------------------------------------


 	//Iniciando vectores-----------------------------
 	initMascotas(mascotas, TAM_MASCOTA);
 	initTrabajos(trabajos, TAM_TRABAJO);
 	//-----------------------------------------------

 	printf("----------Bienvenido!----------\n\n");

 		do {
 			switch(menuPrincipal()) {
 				case 'a':
 	                if(altaMascota(mascotas, TAM_MASCOTA, proxIdMascota, tipos, colores, TAM))
 	                	proxIdMascota++;
 					break;
 				case 'b':
 					if(hayMascotas(mascotas, TAM_MASCOTA))
 						modificarMascota(mascotas, TAM_MASCOTA, tipos, colores, TAM);
 					else
 						printf("No hay mascotas agregadas en el Sistema. No se puede modificar\n\n");
 					break;
 				case 'c':
 					if(hayMascotas(mascotas, TAM_MASCOTA))
 						bajaMascota(mascotas, TAM_MASCOTA, tipos, colores, TAM);
 					 else
  						printf("No hay mascotas agregadas en el Sistema. No se puede dar de baja\n\n");
 					break;
 				case 'd':
 					if(hayMascotas(mascotas, TAM_MASCOTA))
 	 					ordenarMascotasPorTipoYNombre(mascotas, TAM_MASCOTA);
 					else
 						printf("No hay mascotas para mostrar\n\n");
 					break;
 				case 'e':
 					listarTipos(tipos, TAM);
 					break;
 				case 'f':
 					listarColores(colores, TAM);
 					break;
 				case 'g':
 					listarServicios(servicios, TAM_SERVICIOS);
 					break;
 				case 'h':
 					if(hayMascotas(mascotas, TAM_MASCOTA)) {
 						if(altaTrabajo(trabajos, TAM_TRABAJO, proxIdTrabajos, mascotas, TAM_MASCOTA, servicios, TAM_SERVICIOS))
 							proxIdTrabajos++;
 					} else
 						printf("No se pueden dar de alta trabajos si no hay mascotas en el sistema!\n\n");
 					break;
 				case 'i':
 					if(hayMascotas(mascotas, TAM_MASCOTA))
 						if(hayTrabajos(trabajos, TAM_TRABAJO))
 	 						mostrarTrabajos(trabajos, TAM_TRABAJO);
 						else
 	 						printf("No hay trabajos para mostrar\n\n");
 					else
 						printf("No se pueden mostrar trabajos si no hay mascotas en el sistema!\n\n");
 					break;
 				case 'j':
 					printf("Desea salir? s/n\n");
 					fflush(stdin);
 					scanf("%c", &confirmaSalir);
 					if(confirmaSalir == 's')
 						seguir = 'n';
 					printf("\nSaliste del programa");
 					break;
 				default:
 					printf("Opcion invalida, intenta de nuevo\n\n");
 			}

 	        system( "read -n 1 -s -p \"Presione enter para continuar...\"" );

 		} while(seguir == 's');

 		return 0;
}
