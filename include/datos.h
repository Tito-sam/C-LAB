#ifndef DATOS_H
#define DATOS_H

#include <stdio.h>

typedef struct {
    double dt;
    double error;
    double error_porcentual;
} ResultadosEuler;

FILE *crear_archivo_resultados(const char *nombre);
void cerrar_archivo_resultados(FILE *archivo);
void escribir_resultado_euler(FILE *archivo, ResultadosEuler resultado[], size_t tam_array);

#endif