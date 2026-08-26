#ifndef FISICA_H
#define FISICA_H

#define PI 3.14159265358979323846

double transformar_a_radianes(double angulo);

double calcular_alcance(double velocidad,
                        double angulo,
                        double gravedad);

double calcular_tiempo_vuelo(double velocidad,
                             double angulo,
                             double gravedad);

double calcular_altura_maxima(double velocidad,
                              double angulo,
                              double gravedad);

double calcular_x(double velocidad,
                  double angulo,
                  double tiempo);

double calcular_y(double velocidad,
                double angulo,
                double tiempo,
                double gravedad);

double calcular_error(double valor_exacto,
                    double valor_aproximado);

double calcular_orden(double error1,
                    double error2,
                    double dt1,
                    double dt2);

double calcular_velocidad_y(double velocidad_y,
                        double gravedad, 
                        double dt);
double calcular_x_euler(double x,
                    double velocidad_x,
                    double dt);
double calcular_y_euler(double y, 
                    double velocidad_y, 
                    double dt);

#endif