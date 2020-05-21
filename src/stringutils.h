
#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_


#endif /* STRINGUTILS_H_ */

/** @brief funcion que concatena un nombre con su apellido de la siguiente manera: Apellido, Nombre
 *	@param nombre: Nombre pasado
 *	@param apellido: Apellido pasado
 *	@param nombreCompleto: Vector de caracteres en el cual se va a almacenar el resultado final
 */
void concatenarNombreYApellido(char* nombre, char* apellido, char* nombreCompleto);

/** @brief funcion que hace de "strlwr" pero para LINUX/MAC, pasa todos los caracteres a mayuscula.
 * @param cadena: vector de caracteres que va a convertir todos sus caracteres en mayuscula
 */
void strlwrLinux(char* cadena);
