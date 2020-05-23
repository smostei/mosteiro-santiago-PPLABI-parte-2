#include "informes.h"
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
#include "ctype.h"
#include "cliente.h"

void manejarRespuestaInformes(sMascota* mascotas,
		sTrabajo* trabajos,
		int longitud,
		sColor* colores,
		sTipo* tipos,
		int longitudTiposYColores,
		sServicio* servicios,
		int longServicios,
		sCliente* clientes,
		int longClientes) {

	char seguir = 's';

	do {
		switch(menuInformes()) {
			case 1:
				mostrarMascotasSeleccionadasPorColor(mascotas, longitud, colores, longitudTiposYColores, clientes, longClientes);
				break;
			case 2:
				mostrarMascotasSeleccionadasPorTipo(mascotas, longitud, tipos, longitudTiposYColores, clientes, longClientes);
				break;
			case 3:
				informarMascotasMasJovenes(mascotas, longitud, clientes, longClientes);
				break;
			case 4:
				informarListadoMascotasSeparadoPorTipo(mascotas, longitud, tipos, longitudTiposYColores, clientes, longClientes);
				break;
			case 5:
				informarCantidadMascotasSegunTipoYColor(mascotas, longitud, tipos, colores, longitudTiposYColores);
				break;
			case 6:
				informarColoresConMayorCantidadMascotas(mascotas, longitud, colores);
				break;
			case 7:
				if(hayTrabajos(trabajos, longitud))
					informarTrabajosPorMascotaSeleccionada(mascotas, trabajos, longitud, clientes, longClientes);
				else
					printf("No hay trabajos dados de alta en el Sistema, no se puede mostrar este informe\n\n");
				break;
			case 8:
				if(hayTrabajos(trabajos, longitud))
					informarImportesServiciosPorMascotaSeleccionada(mascotas, trabajos, longitud, servicios, longServicios, clientes, longClientes);
				else
					printf("No hay trabajos dados de alta en el Sistema, no se puede mostrar este informe\n\n");
				break;
			case 9:
				if(hayTrabajos(trabajos, longitud))
					informarMascotasYFechaPorServicioSeleccionado(mascotas, trabajos, longitud, servicios, longServicios, clientes, longClientes);
				else
					printf("No hay trabajos dados de alta en el Sistema, no se puede mostrar este informe\n\n");
				break;
			case 10:
				if(hayTrabajos(trabajos, longitud))
					informarServiciosRealizadosPorFechaSeleccionada(trabajos, longitud, servicios, longServicios);
				else
					printf("No hay trabajos dados de alta en el Sistema, no se puede mostrar este informe\n\n");
				break;
			case 11:
				seguir = 'n';
				printf("Volviendo al menu principal...\n\n");
				break;
			default:
				printf("Opcion incorrecta, volve a intentarlo\n\n");
		}

	   system( "read -n 1 -s -p \"Presione enter para continuar...\"" );

	} while(seguir == 's');

}

void mostrarMascotasSeleccionadasPorTipo(sMascota* mascotas,
		int longMascotas,
		sTipo* tipos,
		int longTipos,
		sCliente* clientes,
		int longClientes) {

	printf("----------Listado de mascotas por tipo----------\n\n");
	int tipo;

	listarTipos(tipos, longTipos);
	printf("\nIngrese el tipo de mascota: ");
	scanf("%d", &tipo);

	if(tipo < 1000 || tipo > 1004) {
		printf("El tipo ingresado no es correcto!\n");
		return;
	} else {
		int flag = 0;
		printf("ID        Nombre          Tipo            Color    Edad   Nombre del Duenio\n\n");

		for(int i = 0; i < longMascotas; i++) {
			if(!mascotas[i].isEmpty && mascotas[i].idTipo == tipo) {
				flag = 1;
				mostrarMascota(mascotas[i], clientes, longClientes);
			}
		}

		if(!flag)
			printf("No se encontraron mascotas con ese tipo\n\n");
	}
}

void mostrarMascotasSeleccionadasPorColor(sMascota* mascotas, int longMascotas, sColor* colores, int longColores, sCliente* clientes, int longClientes) {
	printf("----------Listado de mascotas por color----------\n\n");
	int color;

	listarColores(colores, longColores);
	printf("\nIngrese el color de la mascota: ");
	scanf("%d", &color);

	if(color < 5000 || color > 5004) {
		printf("El color ingresado no es correcto!\n");
		return;
	} else {
		int flag = 0;
		printf("ID        Nombre          Tipo            Color    Edad  Nombre del Duenio\n\n");

		for(int i = 0; i < longMascotas; i++) {
			if(!mascotas[i].isEmpty && mascotas[i].idColor == color) {
				flag = 1;
				mostrarMascota(mascotas[i], clientes, longClientes);
			}
		}

		if(!flag)
			printf("No se encontraron mascotas con ese color\n\n");
	}

	printf("\n\n");
}


void informarMascotasMasJovenes(sMascota* mascotas, int longMascotas, sCliente* clientes, int longClientes) {
	printf("----------Listado de mascotas mas joven/es----------\n\n");

	int edadMasJoven;
	int flag = 0;

	for(int i = 0; i < longMascotas; i++) {
		if(!mascotas[i].isEmpty && (!flag || mascotas[i].edad < edadMasJoven)) {
			edadMasJoven = mascotas[i].edad;
			flag = 1;
		}
	}

	printf("ID        Nombre          Tipo            Color    Edad   Nombre del Duenio\n\n");

	for(int i = 0; i < longMascotas; i++) {
		if(!mascotas[i].isEmpty && mascotas[i].edad == edadMasJoven)
			mostrarMascota(mascotas[i], clientes, longClientes);
	}

	printf("\n\n");
}

void informarListadoMascotasSeparadoPorTipo(sMascota* mascotas, int longMascotas, sTipo* tipos, int longTipos, sCliente* clientes, int longClientes) {
	printf("----------Listado de mascotas por tipo----------\n\n");

	int flagTipo = 0;

	for(int t = 0; t < longTipos; t++) {
		printf("----------Mascotas tipo %s----------\n\n", tipos[t].descripcion);
		printf("ID        Nombre          Tipo            Color    Edad    Nombre del Duenio\n\n");

		for(int m = 0; m < longMascotas; m++) {
			if(!mascotas[m].isEmpty && mascotas[m].idTipo == tipos[t].id) {
				mostrarMascota(mascotas[m], clientes, longClientes);
				flagTipo = 1;
			}
		}

		printf("\n\n");

		if(!flagTipo)
			printf("No se encontraron mascotas de tipo %s\n\n", tipos[t].descripcion);

		flagTipo = 0;
	}

	printf("\n\n");
}

void informarCantidadMascotasSegunTipoYColor(sMascota* mascotas, int longMascotas, sTipo* tipos, sColor* colores, int longitud) {
	printf("----------Cantidad de mascotas segun el tipo y color dado----------\n\n");

	int tipo;
	int color;
	int flag = 0;
	int cantidad = 0;

	char descripcionTipo[20];
	char descripcionColor[20];

	listarTipos(tipos, longitud);
	printf("\nIngrese el tipo de mascota: ");
	scanf("%d", &tipo);

	while(tipo < 1000 || tipo > 1004) {
		printf("El tipo ingresado no es correcto! Volve a intentarlo: ");
		scanf("%d", &tipo);
	}

	listarColores(colores, longitud);
	printf("\nIngrese el color de la mascota: ");
	scanf("%d", &color);

	while(color < 5000 || color > 5004) {
		printf("El color ingresado no es correcto! Volve a intentarlo: ");
		scanf("%d", &color);
	}

	for(int i = 0; i < longMascotas; i++) {
		if(!mascotas[i].isEmpty && mascotas[i].idTipo == tipo && mascotas[i].idColor == color) {
			cantidad++;
			flag = 1;
		}
	}

	cargarDescripcionTipo(tipo, descripcionTipo);
	cargarDescripcionColor(color, descripcionColor);

	if(flag)
		printf("La cantidad de mascotas de tipo %s y color %s en el Sistema es de: %d\n\n", descripcionTipo, descripcionColor, cantidad);
	else
		printf("No se encontraron mascotas de tipo %s y color %s en el Sistema\n\n", descripcionTipo, descripcionColor);

	printf("\n\n");
}

void informarColoresConMayorCantidadMascotas(sMascota* mascotas, int longitud, sColor* colores) {
	printf("----------Color/es con mas mascotas disponibles----------\n\n");

	//Data
	int cantColores[5] = {}; //Se guarda en este vector, las posibles cantidades de colores
	int longColores = 5;
	int cantColorMaxima;
	char descripcionColor[20];
	int flag = 0;

	//Entrada
	for(int i = 0; i < longColores; i++) {
		for(int j = 0; j < longitud; j++) {
			if(!mascotas[j].isEmpty && mascotas[j].idColor == colores[i].id)
					cantColores[i]++;
		}
	}

	//Proceso
	for(int i = 0; i < longColores; i++) {
		if(!flag || cantColores[i] > cantColorMaxima) {
			flag = 1;
			cantColorMaxima = cantColores[i];
		}
	}

	//Salida
	printf("Color/es que poseen la mayor cantidad de mascotas (la cual es %d): \n\n", cantColorMaxima);

	for(int i = 0; i < longColores; i++) {
		if(cantColorMaxima == cantColores[i]) {
			cargarDescripcionColor(colores[i].id, descripcionColor);
			printf("%s\n", descripcionColor);
		}
	}

	printf("\n\n");
}


void informarTrabajosPorMascotaSeleccionada(sMascota* mascotas, sTrabajo* trabajos, int longitud, sCliente* clientes, int longClientes) {
	printf("----------Listado de trabajos por mascota seleccionada----------\n\n");

	int idMascotaIngresado;
	int flag = 0;

	mostrarMascotas(mascotas, longitud, clientes, longClientes);
	printf("Ingresa el ID de la mascota: ");
	scanf("%d", &idMascotaIngresado);

	if(buscarMascota(mascotas, idMascotaIngresado, longitud) != -1) {
		printf("----------Trabajos----------\n\n");
		printf("ID    ID Mascota   ID Servicio      Servicio     Fecha\n\n");

		for(int i = 0; i < longitud; i++) {
			if(trabajos[i].idMascota == idMascotaIngresado) {
				mostrarTrabajo(trabajos[i]);
				flag = 1;
			}
		}

		if(!flag)
			printf("No hay trabajos con la mascota ingresada\n\n");
	} else
		printf("No existe una mascota con el ID %d\n\n", idMascotaIngresado);

	printf("\n\n");
}


void informarImportesServiciosPorMascotaSeleccionada(sMascota* mascotas,
		sTrabajo* trabajos,
		int longitud,
		sServicio* servicios,
		int longServicios,
		sCliente* clientes,
		int longClientes) {

	printf("----------Acumulación de importes de servicios por Mascota seleccionada----------\n\n");

	int idMascotaIngresado;
	float acumulacionPrecioServicio = 0;

	mostrarMascotas(mascotas, longitud, clientes, longClientes);
	printf("Ingresa el ID de la mascota: ");
	scanf("%d", &idMascotaIngresado);

	int indice = buscarMascota(mascotas, idMascotaIngresado, longitud);

	if(indice != -1) {
		for(int i = 0; i < longitud; i++) {
			if(trabajos[i].idMascota == idMascotaIngresado) {
				int indice = buscarServicioPorId(servicios, longServicios, trabajos[i].idServicio);

				if(indice != -1) {
					acumulacionPrecioServicio += servicios[indice].precio;
				}
			}
		}

		printf("La mascota %s tuvo un costo total de servicios de $%.2f\n\n", mascotas[indice].nombre, acumulacionPrecioServicio);
	} else
		printf("No existe una mascota con el ID %d\n\n", idMascotaIngresado);

	printf("\n\n");
}


void informarMascotasYFechaPorServicioSeleccionado(sMascota* mascotas,
		sTrabajo* trabajos,
		int longitud,
		sServicio* servicios,
		int longServicios,
		sCliente* clientes,
		int longClientes) {

	printf("----------Listado de mascotas y fecha de servicio por uno seleccionado----------\n\n");

	int idServicioIngresado;
	int flag = 0;
	char descripcionServicio[20];

	listarServicios(servicios, longServicios);
	printf("Ingresa el ID del servicio: ");
	scanf("%d", &idServicioIngresado);

	if(idServicioIngresado < 20000 || idServicioIngresado > 20002)
		printf("El servicio ingresado no es correcto! \n\n");
	else {
		cargarDescripcionServicio(idServicioIngresado, descripcionServicio);
		printf("-----Mascotas que tengan el servicio %s-----\n\n", descripcionServicio);

		printf("ID        Nombre          Tipo            Color    Edad   Nombre del Duenio\n\n");

		for(int i = 0; i  < longitud; i++) {
			if(trabajos[i].idServicio == idServicioIngresado) {
				flag = 1;
				int indice = buscarMascota(mascotas, trabajos[i].idMascota, longitud);
				mostrarMascota(mascotas[indice], clientes, longClientes);
				printf("La fecha de este servicio es %02d/%02d/%d\n\n", trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
			}
		}

		if(!flag)
			printf("No se encontraron mascotas a las que se le haya brindado el servicio %s\n\n", descripcionServicio);
	}

	printf("\n\n");
}


void informarServiciosRealizadosPorFechaSeleccionada(sTrabajo* trabajos, int longTrabajos, sServicio* servicios, int longServicios) {
	printf("----------Listado de servicios realizados por fecha seleccionada----------\n\n");

	sFecha fecha;
	int flag = 0;

	printf("Ingrese una fecha: dd/mm/aaaa\n");
	scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    while(!esUnaFechaCorrecta(fecha.dia, fecha.mes, fecha.anio)) {
        printf("La fecha ingresada es incorrecta, reintentar\n: dd/mm/aaaa\n");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    }

    printf("----------Servicios brindados fecha %02d/%02d/%d----------\n\n", fecha.dia, fecha.mes, fecha.anio);

	printf("ID           Descripcion           Precio\n\n");

    for(int i = 0; i < longTrabajos; i++) {
    	if(sonFechasIguales(fecha, trabajos[i].fecha)) {
    		flag = 1;
    		int indiceServicio = buscarServicioPorId(servicios, longServicios, trabajos[i].idServicio);
    		listarServicio(servicios[indiceServicio]);
    	}
    }

    if(!flag)
    	printf("No se encontraron servicios realizados que correspondan a la fecha %02d/%02d/%d\n\n", fecha.dia, fecha.mes, fecha.anio);

	printf("\n\n");
}

