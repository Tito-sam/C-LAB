#include <stdio.h>

#include "../include/simulacion.h"





int main(void) {
    int opcion;
    do {
        printf("========================\n");
        printf("          C-LAB\n");
        printf("========================\n");
        printf("\n");
        printf("Bienvenido a nuestro laboratorio.\n");
        printf("1. Simulacion.\n");
        printf("2. Herramientas.\n");
        printf("3. Juegos.\n");
        printf("4. Salir.\n");

        
        printf("Selecciona una opcion: ");
        scanf("%d",&opcion);
        switch (opcion) {
            case  1: 
                simulacion();
                break;
            case 2:
                printf("Seleccionaste Herramientas.\n");
                break;
            case 3:
                printf("Seleccionaste Juegos.\n");
                break;
            case 4:
                printf("Seleccionaste Salir.\n");
                break;
            default:
                printf("seleccionaste una opcion no existente.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}




