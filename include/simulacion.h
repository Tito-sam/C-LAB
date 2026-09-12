#ifndef SIMULACION_H
#define SIMULACION_H

#include "fisica.h"
typedef struct {
    double x;
    double y;
    double velocidad_x;
    double velocidad_y;
} Estado;


void simulacion(void);

void posiciones_exacta(ParametrosSimulacion parametros,double dt,double tiempo_vuelo);

void posiciones_euler(double dt,ParametrosSimulacion parametros);

double posicion_tiempo_exacto_euler(double dt,ParametrosSimulacion parametros,double tiempo_exacto);

void actualizar_estado(Estado *estado,double dt,ParametrosSimulacion parametros);

#endif