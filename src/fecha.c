#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"

int esUnaFechaCorrecta(int dia, int mes, int anio) {
	int respuesta = 0;

	if(anio >= 1900 && anio <= 2020)  {
		if(mes >= 1 && mes <= 12) {
			if(dia >= 1 && dia <= 31) {
				respuesta = 1;
			}
		}
	}

	return respuesta;
}

int sonFechasIguales(sFecha primerFecha, sFecha segundaFecha) {
	int respuesta = 0;

	if(primerFecha.anio == segundaFecha.anio) {
		if(primerFecha.mes == segundaFecha.mes) {
			if(primerFecha.dia == segundaFecha.dia) {
				respuesta = 1;
			}
		}
	}

	return respuesta;
}
