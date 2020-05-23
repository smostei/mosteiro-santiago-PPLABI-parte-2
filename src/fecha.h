#ifndef FECHA_H_
#define FECHA_H_

typedef struct {
	int dia;
	int mes;
	int anio;
} sFecha;

#endif /* FECHA_H_ */

/** @brief funcion que verifica si la fecha pasada por parametro es correcta (que tenga cierta validación entre dia, mes y año)
 *
 * @param dia: dia ingresado
 * @param mes: mes ingresado
 * @param anio: año ingresado
 *
 * @return 0 -> en caso de que sea una fecha incorrecta. 1 -> el caso contrario
 */
int esUnaFechaCorrecta(int dia, int mes, int anio);

/** @brief funcion que compara dos fechas para chequear si son iguales o no
 *
 * @param primerFecha: primer fecha a comparar
 * @param segundaFecha: segunda fecha a comparar
 *
 * @return 0 -> si no son iguales. 1 -> en caso de ser iguales
 */
int sonFechasIguales(sFecha primerFecha, sFecha segundaFecha);
