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

double calcular_alcance( ParametrosSimulacion parametros) {
    return (parametros.velocidad*parametros.velocidad*sin(2*transformar_a_radianes(parametros.angulo)))/parametros.gravedad;
}

double calcular_tiempo_vuelo( ParametrosSimulacion parametros) {
    return (2*parametros.velocidad*sin(transformar_a_radianes(parametros.angulo)))/parametros.gravedad;
}

double calcular_altura_maxima( ParametrosSimulacion parametros) {
    return (pow(parametros.velocidad*sin(transformar_a_radianes(parametros.angulo)), 2))/(2*parametros.gravedad);
}

double calcular_x( ParametrosSimulacion parametros, double tiempo) {
    return parametros.velocidad*cos(transformar_a_radianes(parametros.angulo))*tiempo;
}

double calcular_y( ParametrosSimulacion parametros, double tiempo) {
    return parametros.velocidad*sin(transformar_a_radianes(parametros.angulo))*tiempo - 0.5*parametros.gravedad*tiempo*tiempo;
}

double calcular_velocidad_y(double velocidad_y, ParametrosSimulacion parametros, double dt) {
    return velocidad_y - parametros.gravedad*dt;
}

double calcular_x_euler(double x, double velocidad_x, double dt) {
    return x + velocidad_x*dt;
}

double calcular_y_euler(double y, double velocidad_y, double dt) {
    return y + velocidad_y*dt;
}