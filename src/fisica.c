#include <math.h>
#include "../include/fisica.h"

double calcular_orden(double error1, double error2,double dt1, double dt2)
{
    return log(error1 / error2) /log(dt1 / dt2);
}

double transformar_a_radianes(double angulo) {
    return PI * angulo / 180;
}
double calcular_error(double valor_exacto, double valor_aproximado){
    return fabs(valor_exacto-valor_aproximado);
}

double calcular_alcance(double velocidad, double angulo, double gravedad) {
    return (velocidad*velocidad*sin(2*transformar_a_radianes(angulo)))/gravedad;
}

double calcular_tiempo_vuelo(double velocidad, double angulo, double gravedad) {
    return (2*velocidad*sin(transformar_a_radianes(angulo)))/gravedad;
}

double calcular_altura_maxima(double velocidad, double angulo, double gravedad) {
    return (pow(velocidad*sin(transformar_a_radianes(angulo)), 2))/(2*gravedad);
}

double calcular_x(double velocidad, double angulo, double tiempo) {
    return velocidad*cos(transformar_a_radianes(angulo))*tiempo;
}

double calcular_y(double velocidad, double angulo, double tiempo, double gravedad) {
    return velocidad*sin(transformar_a_radianes(angulo))*tiempo - 0.5*gravedad*tiempo*tiempo;
}

double calcular_velocidad_y(double velocidad_y,double gravedad, double dt) {
    return velocidad_y - gravedad*dt;
}

double calcular_x_euler(double x, double velocidad_x, double dt) {
    return x + velocidad_x*dt;
}

double calcular_y_euler(double y, double velocidad_y, double dt) {
    return y + velocidad_y*dt;
}