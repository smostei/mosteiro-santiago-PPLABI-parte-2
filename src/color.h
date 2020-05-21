#ifndef COLOR_H_
#define COLOR_H_

typedef struct {
	int id; //comienza en 5000
	char nombreColor[20];
} sColor;

#endif /* COLOR_H_ */

/** @brief funcion que muestra los colores disponibles al usuario
 *
 * @param colores: vector de colores a mostrar
 * @param longColores: longitud del vector
 */
void listarColores(sColor* colores, int longColores);
