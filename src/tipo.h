#ifndef TIPO_H_
#define TIPO_H_

typedef struct {
	int id; //comienza en 1000
	char descripcion[20];
} sTipo;


#endif /* TIPO_H_ */

/** @brief funcion que muestra los tipos de mascota disponibles al usuario
 *
 * @param tipos: el vector de tipos
 * @param longitudTipos: la longitud del vector de tipos
 */
void listarTipos(sTipo* tipos, int longitudTipos);
