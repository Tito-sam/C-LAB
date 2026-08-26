#ifndef DATOS_H
#define DATOS_H

#include <stdio.h>

struct ResultadosEuler {
    double dt;
    double error;
    double error_porcentual;
};

FILE *crear_archivo_resultados(const char *nombre);
void cerrar_archivo_resultados(FILE *archivo);
void escribir_resultado_euler(FILE *archivo, struct ResultadosEuler resultado);

#endif