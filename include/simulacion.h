#ifndef SIMULACION_H
#define SIMULACION_H

struct Estado {
    double x;
    double y;
    double velocidad_x;
    double velocidad_y;
};

void simulacion(void);

void posiciones_exacta(double velocidad,
                       double angulo,
                       double dt,
                       double gravedad,
                       double tiempo_vuelo);

void posiciones_euler(double velocidad,
                      double angulo,
                      double dt,
                      double gravedad);

double posicion_tiempo_exacto_euler(double velocidad,
                                    double angulo,
                                    double dt,
                                    double gravedad,
                                    double tiempo_exacto);

void actualizar_estado(struct Estado *estado,
                       double dt,
                       double gravedad);

#endif