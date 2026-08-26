#include <stddef.h>
#include <stdio.h>
#include <math.h>

#include "../include/fisica.h"
#include "../include/simulacion.h"

void simulacion(void) {
    double velocidad;
    double angulo;
    double gravedad;
    printf("========================\n");
    printf("-------Simulacion-------.\n");
    printf("========================\n");
    FILE *archivo = fopen("datos/resultados_euler.csv", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo \n");
        return;
    }
    printf("Digita la velocidad en m/s: ");
    scanf("%lf",&velocidad);
    printf("Digita el angulo en °: ");
    scanf("%lf",&angulo);
    printf("Digita la gravedad en m/s²: ");
    scanf("%lf",&gravedad);
    // mostrar_datos( velocidad, angulo, gravedad);
    // modificar_velocidad(&velocidad);
    // printf("Velocidad despues de modificar: %.2f", velocidad);
    
    double alcance = calcular_alcance(velocidad,angulo,gravedad);
    double tiempo_vuelo = calcular_tiempo_vuelo(velocidad,angulo,gravedad);
    double altura_maxima = calcular_altura_maxima(velocidad,angulo,gravedad);

    printf("========================\n");
    printf("Resultados de la simulacion.\n");
    printf("========================\n");

    printf("El alcance es de: %.2f m\n", alcance);
    printf("El tiempo de vuelo es de: %.2f s\n", tiempo_vuelo);
    printf("La altura máxima es de: %.2f m\n", altura_maxima);
    double dt = 0.1;
    posiciones_exacta(velocidad, angulo,dt, gravedad, tiempo_vuelo);
    dt = 0.1;
    posiciones_euler(velocidad, angulo,dt, gravedad);

    double pasos[] = {0.1,0.05,0.01, 0.005, 0.001};
    printf("Posicion Exacta    Euler      Error       Error Porcentual\n");
    printf("==========================================================\n");
    fprintf(archivo, "dt,error,error_porcentual\n");
    double error_previo = 0;
    double posicion_y_exacta;
    double posicion_final_x_euler;
    double error_nuevo;
    double orden;
    double tiempo_comparacion = 1.4;
    size_t cantidad_pasos = sizeof(pasos)/sizeof(pasos[0]);
    for (size_t i = 0; i < cantidad_pasos; i++) {
        posicion_y_exacta = calcular_y(velocidad, angulo, tiempo_comparacion, gravedad);
        posicion_final_x_euler = posicion_tiempo_exacto_euler( velocidad, angulo, pasos[i], gravedad, tiempo_comparacion);
        error_nuevo = calcular_error(posicion_y_exacta, posicion_final_x_euler);
        double error_porcentual = error_nuevo*100/posicion_y_exacta;
        fprintf(archivo,"%.3f,%.3f,%.3f\n",pasos[i],error_nuevo,error_porcentual);
        printf("%.3f m   %.3f m    %.3f     %.3f\n", posicion_y_exacta, posicion_final_x_euler, error_nuevo, error_porcentual);
        if (i!= 0){
            orden = calcular_orden(error_previo,error_nuevo,pasos[i-1],pasos[i]);
            printf("Orden experimental: %.4f\n", orden);
        }
        error_previo = error_nuevo;
    }
    fclose(archivo);
}

void actualizar_estado(struct Estado *estado, double dt, double gravedad) {

    estado->x += estado->velocidad_x * dt;

    estado->y += estado->velocidad_y * dt;

    estado->velocidad_y -= gravedad * dt;
}


void posiciones_exacta(double velocidad,double angulo, double dt, double gravedad, double tiempo_vuelo) {
    printf("Tabla de posicion exacta con un intervalo de %.1f \n", dt);
    printf("Tiempo       X         Y       \n");
    printf("-------------------------------\n");
    double tiempo = 0.0;
    while (tiempo <= tiempo_vuelo) {
        double posicion_x = calcular_x(velocidad, angulo,tiempo);
        double posicion_y = calcular_y(velocidad, angulo, tiempo, gravedad);
        printf(" %.2f      %.2f      %.2f   \n", tiempo, posicion_x, posicion_y);
        tiempo += dt;
    }
}


void posiciones_euler(double velocidad,double angulo, double dt, double gravedad) {
    struct Estado proyectil;
    proyectil.x = 0.0;
    proyectil.y = 0.0;
    proyectil.velocidad_x = velocidad *cos(transformar_a_radianes(angulo));
    proyectil.velocidad_y = velocidad *sin(transformar_a_radianes(angulo));
    printf("\nEstado inicial:\n");
    printf("x  = %.3f m\n", proyectil.x);
    printf("y  = %.3f m\n", proyectil.y);
    printf("vx = %.3f m/s\n", proyectil.velocidad_x);
    printf("vy = %.3f m/s\n", proyectil.velocidad_y);
    
    /**
    struct Estado *estado = &proyectil;

    printf("%.2f\n", estado->x);

      actualizar_estado(&proyectil, dt, gravedad);

    printf("\nDespues de %.2f s:\n", dt);
    printf("x  = %.3f m\n", proyectil.x);
    printf("y  = %.3f m\n", proyectil.y);
    printf("vx = %.3f m/s\n", proyectil.velocidad_x);
    printf("vy = %.3f m/s\n", proyectil.velocidad_y);
    
    */
    double tiempo = 0;
    printf("Tabla de posicion calculada con Euler con un intervalo de %.3f \n", dt);
    printf("Tiempo       X         Y       \n");
    printf("-------------------------------\n");
    while(proyectil.y >= 0) {
        printf(" %.2f      %.3f      %.3f   \n", tiempo, proyectil.x, proyectil.y);
        actualizar_estado(&proyectil, dt, gravedad);
        tiempo += dt;
    }
}

double posicion_tiempo_exacto_euler(double velocidad,double angulo, double dt, double gravedad, double tiempo_exacto) {
    struct Estado proyectil;
    // Definimos Valor inicial de la velocidad tanto en X como en Y con el valor de velocidad inicial que nos ingresaron
    proyectil.velocidad_y = velocidad*sin(transformar_a_radianes(angulo));
    double tiempo = 0;
    while(tiempo <= tiempo_exacto) {
        actualizar_estado(&proyectil,dt, gravedad);
        tiempo += dt;
    }
    return proyectil.y;
}