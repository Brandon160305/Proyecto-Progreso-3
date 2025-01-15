#include <stdio.h>
#include <string.h>
#include "guardar.h"

void ingresar(Inventario *inventario, int *f) {
int x;
    if (*f >= 100) {
        printf("No se pueden agregar más productos.\n");

    }else{
        printf(BLUE"\nINGRESAR PRODUCTOS:\n"RESET);
        getchar();
        printf("Ingrese el código del producto: ");
        do{
            x=0;
            fgets(inventario[*f].codigo, sizeof(inventario[*f].codigo), stdin);
            inventario[*f].codigo[strcspn(inventario[*f].codigo, "\n")] = '\0';
            for (int j = 0; j < *f; j++) {
                if (strcmp(inventario[*f].codigo, inventario[j].codigo)==0){
                    printf(RED"El codigo ingresado ya existe, ingrese otro: "RESET);
                    x=1;
                }
            }
        }while(x==1);

        printf("Ingrese el nombre del producto: ");
        fgets(inventario[*f].producto, sizeof(inventario[*f].producto), stdin);
        inventario[*f].producto[strcspn(inventario[*f].producto, "\n")] = '\0';

        printf("Ingrese la marca del producto: ");
        fgets(inventario[*f].marca, sizeof(inventario[*f].marca), stdin);
        inventario[*f].marca[strcspn(inventario[*f].marca, "\n")] = '\0';

        printf("Ingrese el modelo del producto: ");
        fgets(inventario[*f].modelo, sizeof(inventario[*f].modelo), stdin);
        inventario[*f].modelo[strcspn(inventario[*f].modelo, "\n")] = '\0';

        do {
            printf("Ingrese el año del producto: ");
            scanf("%d", &inventario[*f].year);
        } while (inventario[*f].year < 1970 || inventario[*f].year > 2025);

        do {
            printf("Ingrese la cantidad de productos: ");
            scanf("%d", &inventario[*f].cantidad);
        } while (inventario[*f].cantidad < 0);

        do {
            printf("Ingrese el precio del producto en dólares: ");            
            scanf("%f", &inventario[*f].precio);
        } while (inventario[*f].precio < 0);

        ordenarInventario(inventario, f);
        guardarInventario(inventario, f);


        printf(GREEN"Producto agregado.\n");

        (*f)++;
    }
}



void editar(Inventario *inventario, int *f) {
    char codigo[100], y = 0;
    printf(BLUE"\nEDITAR PRODUCTOS:\n"RESET);
    getchar();
    printf("Ingrese el código del repuesto a editar: ");
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';
    
    for (int i = 0; i < *f; i++) {
        if (strcmp(inventario[i].codigo, codigo)==0) {
            y = 1;

            printf("Ingrese los nuevos valores:\n");
            
            printf("Nombre: ");
            fgets(inventario[i].producto, sizeof(inventario[i].producto), stdin);
            inventario[i].producto[strcspn(inventario[i].producto, "\n")] = '\0';

            printf("Marca: ");
            fgets(inventario[i].marca, sizeof(inventario[i].marca), stdin);
            inventario[i].marca[strcspn(inventario[i].marca, "\n")] = '\0';

            printf("Modelo: ");
            fgets(inventario[i].modelo, sizeof(inventario[i].modelo), stdin);
            inventario[i].modelo[strcspn(inventario[i].modelo, "\n")] = '\0';

            do {
                printf("Año: ");
                scanf("%d", &inventario[i].year);
            } while (inventario[i].year < 1970 || inventario[i].year > 2025);

            do {
                printf("Cantidad: ");
                scanf("%d", &inventario[i].cantidad);
            } while (inventario[i].cantidad < 0);

            do {
                printf("Precio: ");
                scanf("%f", &inventario[i].precio);
            } while (inventario[i].precio < 0);

            printf(GREEN"Producto actualizado.\n");
            
        }
    }

    if (y == 0) {
        printf(RED"Producto no encontrado.\n");
    }
    guardar1Inventario(inventario, f);
}

void eliminar(Inventario *inventario, int *f) {
    char codigo[100];
    int y = 0;

    printf(BLUE"\nELIMINAR PRODUCTOS:\n"RESET);
    getchar();
    printf("Ingrese el código del producto a eliminar: ");
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    for (int i = 0; i < *f; i++) {
        if (strcmp(inventario[i].codigo, codigo) == 0) {
            for (int j = i; j < *f - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            (*f)--;
            printf(GREEN"Producto eliminado.\n");
            y = 1;
        }
    }
    if (y == 0) {
        printf(RED"Producto no encontrado.\n"RESET);
    }
    guardar1Inventario(inventario, f);
}
