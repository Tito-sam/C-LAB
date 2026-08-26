#include <stdio.h>
#include "../include/datos.h"

FILE *crear_archivo_resultados(const char *nombre) {

    FILE *archivo = fopen(nombre, "w");

    if (archivo == NULL) {
        printf("Error al crear el archivo\n");
        return NULL;
    }

    return archivo;
}

void cerrar_archivo_resultados(FILE *archivo) {
    if (archivo != NULL) {
        fclose(archivo);
    }
}

void escribir_resultado_euler(FILE *archivo, struct ResultadosEuler resultado) {
            fprintf(archivo,"%.3f,%.3f,%.3f\n",resultado.dt,resultado.error,resultado.error_porcentual);

}