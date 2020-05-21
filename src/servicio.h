#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct {
	int id; //comienza en 20000
	char descripcion[25];
	float precio;
} sServicio;


#endif /* SERVICIO_H_ */

/** @brief funcion que muestra los servicios disponibles
 *
 * @param servicios: vector de servicios a mostrar
 * @param longServicios: longitud del vector de servicios
 */
void listarServicios(sServicio* servicios, int longServicios);
