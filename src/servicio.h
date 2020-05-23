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

/** @brief funcion que imprime por consola un servicio en especifico
 *
 * @param servicio: el servicio a mostrar
 */
void listarServicio(sServicio servicio);

/** @brief funcion que busca un servicio por su ID
 *
 * @param servicios: vector de servicios disponibles
 * @param longServicios: longitud del vector de servicios
 * @param id: el id por el cuál se va a buscar el servicio
 *
 * @return -1 en caso de no encontrar un servicio. El indice del servicio, en caso de encontrarlo
 */
int buscarServicioPorId(sServicio* servicios, int longServicios, int id);

/** @brief funcion que carga la descripción de un servicio para poder mejorar la experiencia al leerlo
 *
 * @param idServicio: el ID por el cual se mapeara el servicio a cargar
 * @param descripcion: el vector de caracteres al cuál se cargara la información del servicio
 */
void cargarDescripcionServicio(int idServicio, char* descripcion);
