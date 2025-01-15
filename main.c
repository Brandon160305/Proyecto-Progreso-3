#include <stdio.h>
#include "guardar.h"

int main() {
    int x, f = 0;
    Inventario inv[100]; 
    cargarInventario(inv, &f);
    
    
    do {
        printf(BLUE"\n---------"ORANGE" MENU "BLUE"---------\n"RESET);
        printf("1. Ingresar producto\n2. Editar producto\n3. Eliminar producto\n4. Salir\n");
        printf(BLUE"-------------------------\n"RESET);
        printf("Seleccione una opción: ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                ingresar(inv, &f);
                break;
            case 2:
                editar(inv, &f);
                break;
            case 3:
                eliminar(inv, &f);
                break;
            case 4:
                printf("\nSaliendo del programa.\n");
                break;
            default:
                printf(RED"Ingrese una opción válida.\n");
        }
    } while (x != 4);

    return 0;
}
