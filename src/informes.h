#include "mascota.h"
#include "trabajo.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"

#ifndef INFORMES_H_
#define INFORMES_H_


#endif /* INFORMES_H_ */

/** @brief funcion que recibe la respuesta del usuario de menuInformes() y administra que hacer con ese valor
 *
 *  @param mascotas: el vector de mascotas para administrar los informes
 *  @param trabajos: el vector de trabajos para administrar los informes
 *  @param longitud: la longitud del vector de mascotas y trabajos
 *  @param colores: vector de colores
 *  @param tipos: vector de tipos
 *  @param longiutdTiposYColores: la longitud de ambos vectores (color y tipo)
 *  @param servicios: el vector de servicios disponibles
 *  @param longServicios: la longitud del vector de servicios
 *  @param clientes: el vector de clientes para identificar el duenio de la mascota
 *  @param longClientes: longitud del vector clientes
 */
void manejarRespuestaInformes(sMascota* mascotas,
		sTrabajo* trabajos,
		int longitud,
		sColor* colores,
		sTipo* tipos,
		int longitudTiposYColores,
		sServicio* servicios,
		int longServicios,
		sCliente* clientes,
		int longClientes);

/** @brief funcion que le permite al usuario elegir un tipo de mascota y mostrarselas por consola con dicho tipo
 *
 *  @param mascotas: el vector de mascotas para ver el informe
 *  @param longMascotas: longitud del vector de mascotas
 *  @param tipos: el vector de tipos
 *  @param longTipos: la longitud del vector tipos
 *  @param clientes: el vector de clientes para identificar el duenio de la mascota
 *  @param longClientes: longitud del vector clientes
 */
void mostrarMascotasSeleccionadasPorTipo(sMascota* mascotas,
		int longMascotas,
		sTipo* tipos,
		int longTipos,
		sCliente* clientes,
		int longClientes);
/** @brief funcion que le permite al usuario elegir un color de mascota y mostrarselas por consola con dicho color
 *
 * @param mascotas: el vector de mascotas para ver el informe
 * @param longMascotas: longitud del vector de mascotas
 * @param colores: el vector de colores
 * @param longColores: la longitud del vector colores
 * @param clientes: el vector de clientes para identificar el duenio de la mascota
 * @param longClientes: longitud del vector clientes
 */
void mostrarMascotasSeleccionadasPorColor(sMascota* mascotas, int longMascotas, sColor* colores, int longColores, sCliente* clientes, int longClientes);
/** @brief funcion que informará por consola la/s mascotas más jovenes del Sistema
 *
 * @param mascotas: el vector de mascotas para ver el informe
 * @param longMascotas: la longitud del vector
 * @param clientes: el vector de clientes para identificar el duenio de la mascota
 * @param longClientes: longitud del vector clientes
 */
void informarMascotasMasJovenes(sMascota* mascotas, int longMascotas, sCliente* clientes, int longClientes);
/** @brief funcion que informa el total de mascotas, pero separadas por su tipo
 *
 * @param mascotas: el vector de mascotas para ver el informe
 * @param longMascotas: la longitud del vector
 * @param tipos: el vector de tipos
 * @param longTipos: la longitud del vector de tipos
 * @param clientes: el vector de clientes para identificar el duenio de la mascota
 * @param longClientes: longitud del vector clientes
 */
void informarListadoMascotasSeparadoPorTipo(sMascota* mascotas, int longMascotas, sTipo* tipos, int longTipos, sCliente* clientes, int longClientes);
/** @brief funcion que va a informar la cantidad de mascotas que hay según un TIPO y un COLOR seleccionado (deben cumplirse las dos condiciones)
 *
 * @param mascotas: el vector de mascotas para ver el informe
 * @param longMascotas: la longitud del vector
 * @param tipos: el vector de tipos
 * @param colores: el vector de colores
 * @param longitud: la longitud del vector, tanto de colores como tipos.
 */
void informarCantidadMascotasSegunTipoYColor(sMascota* mascotas, int longMascotas, sTipo* tipos, sColor* colores, int longitud);

/** @brief funcion que muestra el/los colores mas popular entre las mascotas del sistema (las que más lo poseen)
 *
 * @param mascotas: el vector de mascotas para ver el informe
 * @param longitud: la longitud del vector de mascotas
 * @param colores: el vector de colores disponibles
 */
void informarColoresConMayorCantidadMascotas(sMascota* mascotas, int longitud, sColor* colores);

/** @brief funcion que va a listar los trabajos que tiene una mascota seleccionada por el usuario
 *
 * @param mascotas: el vector de mascotas para ver el informe
 * @param trabajos: el vector de trabajos para ver el informe
 * @param longitud: la longitud de ambos vectores
 * @param clientes: el vector de clientes para identificar el duenio de la mascota
 * @param longClientes: longitud del vector clientes
 */
void informarTrabajosPorMascotaSeleccionada(sMascota* mascotas, sTrabajo* trabajos, int longitud, sCliente* clientes, int longClientes);

/** @brief funcion que muestra el total de importes que generaron los servicios de una mascota seleccionada por el usuario
 *
 * @param mascotas: el vector de mascotas para ver el informe
 * @param trabajos: el vector de trabajos para ver el informe
 * @param longitud: la longitud de ambos vectores
 * @param servicios: el vector con los servicios disponibles
 * @param longServicios: la longitud de los servicios
 * @param clientes: el vector de clientes para identificar el duenio de la mascota
 * @param longClientes: longitud del vector clientes
 */
void informarImportesServiciosPorMascotaSeleccionada(sMascota* mascotas,
		sTrabajo* trabajos,
		int longitud,
		sServicio* servicios,
		int longServicios,
		sCliente* clientes,
		int longClientes);

/** @brief funcion va a mostrar por consola las mascotas y la fecha en la que se realizó un trabajo según un servicio ingresado por el usuario
 *
 * @param mascotas: el vector de mascotas para ver el informe
 * @param trabajos: el vector de trabajos para ver el informe
 * @param longitud: la longitud de ambos vectores
 * @param servicios: el vector con los servicios disponibles
 * @param longServicios: la longitud de los servicios
 * @param clientes: el vector de clientes para identificar el duenio de la mascota
 * @param longClientes: longitud del vector clientes
 */
void informarMascotasYFechaPorServicioSeleccionado(sMascota* mascotas,
		sTrabajo* trabajos,
		int longitud,
		sServicio* servicios,
		int longServicios,
		sCliente* clientes,
		int longClientes);

/** @brief funcion que va a mostrar los servicios realizados en una fecha seleccionada por el usuario
 *
 * @param trabajos: el vector de trabajos para ver el informe
 * @param longTrabajos: la longitud del vector de trabajos
 * @param servicios: el vector con los servicios disponibles
 * @param longServicios: la longitud de los servicios
 */
void informarServiciosRealizadosPorFechaSeleccionada(sTrabajo* trabajos, int longTrabajos, sServicio* servicios, int longServicios);

