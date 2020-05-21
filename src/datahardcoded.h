#include "mascota.h"

#ifndef DATAHARDCODED_H_
#define DATAHARDCODED_H_

#endif /* DATAHARDCODED_H_ */

#define TAM 5
#define TAM_MASCOTA 10
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

//Mascotas hardcodeadas para testear las muestras
sMascota mascotasHardcoded[TAM_MASCOTA] = {
		{0, "Homero", 1001, 5001, 10, 0},
		{1, "Mora", 1002, 5004, 11, 0},
		{2, "Ambar", 1001, 5001, 11, 0},
		{3, "Luna", 1003, 5002, 3, 0},
		{4, "Root", 1002, 5000, 9, 0},
		{5, "Mumi", 1000, 5003, 3, 0},
		{6, "Melian", 1003, 5003, 8, 0},
		{7, "Nacho", 1001, 5002, 15, 0},
		{8, "Duke", 1001, 5004, 7, 0},
		{9, "Samanta", 1003, 5002, 14, 0}
};
