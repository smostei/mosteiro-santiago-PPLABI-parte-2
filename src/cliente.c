#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int buscarClientePorId(sCliente* clientes, int longClientes, int id) {
    int indice = -1;

    for(int i = 0; i < longClientes; i++) {
        if(clientes[i].id == id) {
            indice = i;
            break;
        }
    }

    return indice;
}

void mostrarClientes(sCliente* clientes, int longClientes) {
	printf("----------Listado de clientes----------\n\n");

	printf("ID           Nombre     Sexo\n\n");

	for(int i = 0; i < longClientes; i++) {
		printf("%d     %10s       %c\n", clientes[i].id, clientes[i].nombre, clientes[i].sexo);
	}
}
