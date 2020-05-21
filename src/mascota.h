#include "tipo.h"
#include "color.h"

#ifndef MASCOTA_H_
#define MASCOTA_H_

typedef struct {
    int id; //Comienza en 0, es autoincremental
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
} sMascota;

#endif /* MASCOTA_H_ */

/** @brief funcion que inicia el vector de mascotas para que puedan ser dadas de alta
 *
 * @param mascotas: vector de mascotas
 * @param longMascotas: longitud del vector de mascotas
 */
void initMascotas(sMascota* mascotas, int longMascotas);

/** @brief funcion que muestra una mascota
 *
 * @param mascota: mascota que será mostrada
 */
void mostrarMascota(sMascota mascota);

/** @brief funcion que muestra todas las mascotas de la lista
 *
 * @param mascotas: vector de mascotas a mostrar
 * @param longMascotas: longitud del vector
 */
void mostrarMascotas(sMascota* mascotas, int longMascotas);

/** @brief funcion que da de alta una mascota
 *
 * @param mascotas: vector de mascotas al cuál se va a agregr la mascota
 * @param longMascotas: longitud del vector de mascotas
 * @param proximoId: el id que se le va a asignar a dicha mascota
 * @param tipos: vector de tipos (a la mascota se le asigna un elemento de estos)
 * @param colores: vector de colores (a la mascota se le asigna un elemento de estos)
 * @param longitud: la longitud del vector de tipos y colores
 *
 * @return 0 -> si no pudo dar de alta la mascota. 1 -> si pudo darla de alta
 */
int altaMascota(sMascota* mascotas, int longMascotas, int proximoId, sTipo* tipos, sColor* colores, int longitud);

/** @brief funcion que modifica una mascota seleccionada del vector
 *
 * @param mascotas: vector de mascotas al cuál se va a agregr la mascota
 * @param longMascotas: longitud del vector de mascotas
 * @param tipos: vector de tipos
 * @param colores: vector de colores
 * @param longitud: la longitud del vector de tipos y colores
 */
void modificarMascota(sMascota* mascotas, int longMascotas, sTipo* tipos, sColor* colores, int longitud);

/** @brief funcion da de baja una mascota seleccionada del vector
 *
 * @param mascotas: vector de mascotas al cuál se va a agregr la mascota
 * @param longMascotas: longitud del vector de mascotas
 * @param tipos: vector de tipos
 * @param colores: vector de colores
 * @param longitud: la longitud del vector de tipos y colores
 */
void bajaMascota(sMascota* mascotas, int longMascotas, sTipo* tipos, sColor* colores, int longitud);

/** @brief funcion que busca el primer espacio libre que haya en el vector de mascotas
 *
 * @param mascotas: el vector de mascotas
 * @param longMascotas: la longitud del vector
 *
 * @return -1 -> Si no hay lugar en el vector. Primer indice libre -> en caso de que haya lugar
 */
int buscarLibre(sMascota* mascotas, int longMascotas);

/** @brief funcion que busca una mascota por su id
 *
 * @param mascotas: el vector de mascotas en el cual se realizará la busqueda
 * @param id: el id por el cual se buscará a la mascota
 * @param longMascotas: la longitud del vector
 *
 * @return -1 -> Si no encontró la mascota. Indice del vector en el cuál se encuentra ese ID -> en caso contrario
 */
int buscarMascota(sMascota* mascotas, int id, int longMascotas);

/** @brief funcion que maneja la respuesta del usuario ante
 *
 * @param mascota: direccón de memoria de la mascota que se va a modificar
 * @param tipos: vector de tipos
 * @param longTipos: longitud del vector de tipos
 */
void manejarModificacionMascota(sMascota* mascota, sTipo* tipos, int longTipos);

/** @brief funcion que verifica si hay mascotas en el vector o no (chequea el flag isEmpty)
 *
 * @param mascotas: vector de mascotas a recorrer
 * @param longitud del vector de mascotas
 *
 * @return 0 -> si no hay mascotas disponibles. 1 -> si hay mascotas en el vector
 */

int hayMascotas(sMascota* mascotas, int longMascotas);

/** @brief funcion que ordena las mascotas por tipo, y dentro de esos tipos las ordena por nombre
 *
 * @param mascotas: vector de mascotas a ordenar
 * @param longMascotas: longitud del vector de mascotas
 */
void ordenarMascotasPorTipoYNombre(sMascota* mascotas, int longMascotas);
