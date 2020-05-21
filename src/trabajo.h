#include "fecha.h"
#include "servicio.h"
#include "mascota.h"


#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct {
    int id; //comienza en 0, es autoincremental
    int idMascota;
    int idServicio;
    sFecha fecha;
    int isEmpty;
} sTrabajo;

#endif /* TRABAJO_H_ */

/** @brief funcion que inicia el vector de trabajos (flag isEmpty en 1)
 *
 * @param trabajos: vector de trabajos para iniciar
 * @param longTrabajos: longitud del vector trabajos
 */
void initTrabajos(sTrabajo* trabajos, int longTrabajos);

/** @brief funcion que da de alta un trabajo para la mascota indicada
 *
 * @param trabajos: el vector de trabajos al cuál se va asignar un trabajo
 * @param longTrabajos: longitud del vector trabajos
 * @param proximoId: el ID que va a tener el elemento que se va a dar de alta
 * @param mascotas: el vector de mascotas que va a usarse para buscar el ID de alguna de estas y asignarla a un trabajo
 * @param longMascotas: longitud del vector mascotas
 * @param servicios: el vector de servicios disponibles para que el usuario pueda asignar al trabajo
 * @param longServicios: longitud del vector de servicios
 *
 * @return 0 -> si no pudo dar de alta el trabajo. 1 -> en caso de que haya podido darlo de alta
 */
int altaTrabajo(sTrabajo* trabajos, int longTrabajos, int proximoId, sMascota* mascotas, int longMascotas, sServicio* servicios, int longServicios);

/** @brief funcion que lista los trabajos disponibles
 *
 * @param trabajos: el vector de trabajos a mostrar
 * @param longTrabajos: la longitud del vector
 */
void listarTrabajos(sTrabajo* trabajos, int longTrabajos);

/** @brief funcion que se encargará de buscar el primer lugar libre en el vector para asignar un trabajo
 *
 * @param trabajos: el vector de trabajos
 * @param longTrabajos: longitud del vector
 *
 * @return  -1 -> en caso de que el vector esté lleno. Primer indice del vector -> en caso de que haya lugar
 */
int buscarLibreTrabajos(sTrabajo* trabajos, int longTrabajos);

/** @brief funcion que va a mostrar un trabajo puntualmente
 *
 * @param trabajo: el trabajo a listar
 */
void mostrarTrabajo(sTrabajo trabajo);

/** @brief funcion que va a mostrar todos los trabajos que hay en el vector
 *
 * @param trabajos: el vector de trabajos
 * @para longTrabajos: la longitud del vector
 */
void mostrarTrabajos(sTrabajo* trabajos, int longTrabajos);

/** @brief: funcion que va a chequear si hay o no trabajos en el vector
 *
 * @param trabajos: vector de trabajos a recorrer
 * @param longTrabajos: longitud del vector trabajos
 *
 * @return 0 -> en caso de que no haya trabajos. 1 -> en caso de que haya trabajos en el vector
 */
int hayTrabajos(sTrabajo* trabajos, int longTrabajos);

/** @brief funcion que verifica si la fecha pasada por parametro es correcta (que tenga cierta validación entre dia, mes y año)
 *
 * @param dia: dia ingresado
 * @param mes: mes ingresado
 * @param anio: año ingresado
 *
 * @return 0 -> en caso de que sea una fecha incorrecta. 1 -> el caso contrario
 */
int esUnaFechaCorrecta(int dia, int mes, int anio);



