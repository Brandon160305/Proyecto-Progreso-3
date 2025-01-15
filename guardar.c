#include <stdio.h>
#include <string.h>
#include "inventario.h"

void encabezado(FILE *archivo){
          fprintf(archivo,  "------------------------------------------------------------------------------------------------\n");
          fprintf(archivo, "| %-6s | %-18s | %-15s | %-15s | %-4s | %-8s | %-8s |\n", 
                        "Codigo", "Producto", "Marca", "Modelo", "Año ", "Cantidad", "Precio");
          fprintf(archivo, "------------------------------------------------------------------------------------------------\n");
}


void cargarInventario(Inventario *inventario, int *f) {
    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        archivo = fopen("inventario.txt", "a");
        encabezado(archivo);
        
    }

    *f = 0; // Reinicia el contador
    char linea[256];
    fgets(linea, sizeof(linea), archivo); // Saltar encabezado
    fgets(linea, sizeof(linea), archivo);
    while (fgets(linea, sizeof(linea), archivo)) {
        if (sscanf(linea, "| %6s | %18[^|] | %15[^|] | %15[^|] | %4d | %8d | %8f |",
                   inventario[*f].codigo, inventario[*f].producto, inventario[*f].marca,
                   inventario[*f].modelo, &inventario[*f].year, &inventario[*f].cantidad,
                   &inventario[*f].precio) == 7) {
            (*f)++;
        }
    }
    fclose(archivo);
}


void ordenarInventario(Inventario *inventario, int *f){
    Inventario aux;
    for (int i = 0; i < *f - 1; i++) {
        for (int j = i + 1; j < *f; j++) {
            if (strcmp(inventario[i].producto, inventario[j].producto) > 0 ||
                (strcmp(inventario[i].producto, inventario[j].producto) == 0 &&
                 strcmp(inventario[i].modelo, inventario[j].modelo) > 0) ||
                (strcmp(inventario[i].producto, inventario[j].producto) == 0 &&
                 strcmp(inventario[i].modelo, inventario[j].modelo) == 0 &&
                 strcmp(inventario[i].marca, inventario[j].marca) > 0)) {

                aux = inventario[i];
                inventario[i] = inventario[j];
                inventario[j] = aux;
            }
        }
    }
}


void guardarInventario(Inventario *inventario, int *f) {
    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
       printf(RED"Error al abrir el archivo.\n");
       exit(1);
    } else {
        archivo = fopen("inventario.txt", "w");
        
        encabezado(archivo);
        
        for (int j = 0; j < *f+1; j++) {
            fprintf(archivo, "| %-6s | %-18s | %-15s | %-15s | %-4d | %-8d | %-8.2f |\n", inventario[j].codigo, inventario[j].producto, inventario[j].marca, inventario[j].modelo, inventario[j].year, inventario[j].cantidad, inventario[j].precio);
            fprintf(archivo, "------------------------------------------------------------------------------------------------\n");
        }
        fclose(archivo);

    }
}





void guardar1Inventario(Inventario *inventario, int *f) {
    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
       printf(RED"Error al abrir el archivo.\n");
       exit(1);
    } else {
        archivo = fopen("inventario.txt", "w");

        encabezado(archivo);

        for (int j = 0; j < *f; j++) {
            fprintf(archivo, "| %-6s | %-18s | %-15s | %-15s | %-4d | %-8d | %-8.2f |\n", inventario[j].codigo, inventario[j].producto, inventario[j].marca, inventario[j].modelo, inventario[j].year, inventario[j].cantidad, inventario[j].precio);
            fprintf(archivo, "------------------------------------------------------------------------------------------------\n");
        }
        fclose(archivo);

    }
}