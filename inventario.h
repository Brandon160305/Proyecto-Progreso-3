#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <stdlib.h>
#include "colores.h"

typedef struct Inventario {
    char codigo[100];
    char producto[100];
    char marca[100];
    char modelo[100];
    int year;
    int cantidad;
    float precio;
}Inventario;

void ingresar(Inventario *inventario, int *f);
void editar(Inventario *inventario, int *f);
void eliminar(Inventario *inventario, int *f);


#endif