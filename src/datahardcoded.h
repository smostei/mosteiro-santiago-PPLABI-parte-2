#include "mascota.h"
#include "trabajo.h"
#include "cliente.h"

#ifndef DATAHARDCODED_H_
#define DATAHARDCODED_H_

#endif /* DATAHARDCODED_H_ */

#define TAM 5 //Comparte la misma longitud tanto para tipos como colores
#define TAM_MASCOTA 10 //Comparte la misma longitud que los trabajos y clientes
#define TAM_DESCRIPCION 20
#define TAM_SERVICIOS 3
#define TAM_DESCRIPCION_SERVICIOS 25

//Tipos
int idsTipos[TAM] = {1000, 1001, 1002, 1003, 1004};
char descripcionTipos[TAM][TAM_DESCRIPCION] = {"Ave", "Perro", "Gato", "Roedor", "Pez"};

//Colores
int idsColores[TAM] = {5000, 5001, 5002, 5003, 5004};
char nombreColores[TAM][TAM_DESCRIPCION] = {"Negro", "Blanco", "Gris", "Rojo", "Azul"};

//Servicios
int idsServicios[TAM_SERVICIOS] = {20000, 20001, 20002};
char descripcionServicios[TAM_SERVICIOS][TAM_DESCRIPCION_SERVICIOS] = {"Corte", "Desparasitado", "Castrado"};
float precios[] = {250, 300, 400};

//Mascotas hardcodeadas para testear los informes
sMascota mascotasHardcoded[TAM_MASCOTA] = {
		{0, "Homero", 105, 1001, 5001, 10, 0},
		{1, "Mora", 101, 1002, 5004, 11, 0},
		{2, "Ambar", 105, 1001, 5001, 11, 0},
		{3, "Luna", 103, 1003, 5002, 3, 0},
		{4, "Root", 102, 1002, 5003, 9, 0},
		{5, "Mumi", 109, 1000, 5003, 3, 0},
		{6, "Melian", 105, 1003, 5003, 8, 0},
		{7, "Nacho", 104, 1001, 5002, 15, 0},
		{8, "Duke", 107, 1001, 5004, 7, 0},
		{9, "Samanta", 106, 1003, 5002, 14, 0}
};

//trabajos hardcodeados para testear los informes
sTrabajo trabajosHardcoded[TAM_MASCOTA] = {
		{0, 1, 20000, {5, 6, 2020}, 0},
		{1, 0, 20002, {12, 6, 2020}, 0},
		{2, 1, 20000, {25, 5, 2020}, 0},
		{3, 1, 20000, {6, 6, 2020}, 0},
		{4, 2, 20001, {10, 7, 2020}, 0},
		{5, 2, 20002, {15, 6, 2020}, 0},
		{6, 7, 20002, {15, 7, 2020}, 0},
		{7, 8, 20001, {25, 5, 2020}, 0},
		{8, 3, 20000, {10, 7, 2020}, 0},
		{9, 5, 20000, {9, 7, 2020}, 0}
};

//clientes hardcodeados para testear
sCliente clientesHardcoded[TAM_MASCOTA] = {
		{100, "Juan", 'm'},
		{101, "Francisco", 'm'},
		{102, "Sofia", 'f'},
		{103, "Carlos", 'm'},
		{104, "Juan Jose", 'm'},
		{105, "Santiago", 'm'},
		{106, "Valeria", 'f'},
		{107, "Maria", 'f'},
		{108, "Augusto", 'm'},
		{109, "Carla", 'f'}
};
