#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct {
	int id;
	char nombre[25];
	char sexo;
}sCliente;

#endif /* CLIENTE_H_ */

/** @brief funcion que busca un cliente por id
 *
 * @param clientes: el vector de clientes
 * @param longClientes: la longitud del vector
 * @param id: el criterio por el cual se va a buscar el cliente
 *
 * @return -1 -> si no encuentra nada. indice del vector -> en caso de que lo encuentre
 */
int buscarClientePorId(sCliente* clientes, int longClientes, int id);

/** @brief funcion que muestra los clientes disponibles
 *
 * @param clientes: el vector de clientes a recorrer
 * @param longClientes: la longitud del vector
 */
void mostrarClientes(sCliente* clientes, int longClientes);
