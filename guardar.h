#ifndef GUARDAD_H
#define GUARDAD_H

#include "inventario.h"

void encabezado();
void cargarInventario(Inventario *inventario, int *f);
void ordenarInventario(Inventario *inventario, int *f);
void guardarInventario(Inventario *inventario, int *f);
void guardar1Inventario(Inventario *inventario, int *f);

#endif 




