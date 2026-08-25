#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

int suma(int a, int b);
double calcular_alcance(double velocidad, double angulo, double gravedad);
double transformar_a_radianes(double angulo);
double calcular_tiempo_vuelo(double velocidad, double angulo, double gravedad);
double calcular_altura_maxima(double velocidad, double angulo, double gravedad);
double calcular_x(double velocidad, double angulo, double tiempo);
double calcular_y(double velocidad, double angulo, double tiempo, double gravedad);
double calcular_velocidad_y(double velocidad_y,double gravedad, double dt);
double calcular_x_euler(double x, double velocidad_x, double dt);
double calcular_y_euler(double y, double velocidad_y, double dt);
double calcular_error(double valor_exacto, double valor_aproximado);
void posiciones_exacta(double velocidad,double angulo, double dt, double gravedad, double tiempo_vuelo);
void posiciones_euler(double velocidad,double angulo, double dt, double gravedad);
double posicion_tiempo_exacto_euler(double velocidad,double angulo, double dt, double gravedad, double tiempo_exacto);
double calcular_orden(double error1, double error2,double dt1, double dt2);

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
                printf("========================\n");
                printf("Simulacion.\n");
                printf("========================\n");
                double velocidad;
                double angulo;
                double gravedad;
                FILE *archivo = fopen("resultados_euler.csv","w");
                if (archivo == NULL) {
                    printf("Error al crear el archivo \n");
                    return 1;
                }
                printf("Digita la velocidad en m/s: ");
                scanf("%lf",&velocidad);
                printf("Digita el angulo en °: ");
                scanf("%lf",&angulo);
                printf("Digita la gravedad en m/s²: ");
                scanf("%lf",&gravedad);
                
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
                dt = 0.001;
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
                for (int i = 0; i < sizeof(pasos)/sizeof(pasos[0]); i++) {
                    posicion_y_exacta = calcular_y(velocidad, angulo, 1.4, gravedad);
                    posicion_final_x_euler = posicion_tiempo_exacto_euler( velocidad, angulo, pasos[i], gravedad, 1.4);
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
    
    
    /*
    Punteros
    & devuelve la direccion de memoria
    printf("%p\n", (void *)&opcion);
    * vuelve una variable puntero y se utiliza para referenciar el valor de la direccion 
    guardada del puntero
    int *puntero;
    puntero = &opcion;

    printf("Valor usando puntero es %d\n", *puntero);

    *puntero = 5;
    printf("Valor cambiado usando puntero es: %d\n",*puntero);
    printf("Valor cambiado usando variable opcion: %d\n", opcion);
    */

    return 0;
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
    double x_euler = 0.0;
    double y_euler = 0.0;
    // Definimos Valor inicial de la velocidad tanto en X como en Y con el valor de velocidad inicial que nos ingresaron
    double vx = velocidad*cos(transformar_a_radianes(angulo));
    double vy = velocidad*sin(transformar_a_radianes(angulo));
    double tiempo = 0;
    printf("Tabla de posicion calculada con Euler con un intervalo de %.3f \n", dt);
    printf("Tiempo       X         Y       \n");
    printf("-------------------------------\n");
    while(y_euler >= 0) {
        printf(" %.2f      %.2f      %.2f   \n", tiempo, x_euler, y_euler);
        x_euler = calcular_x_euler(x_euler, vx, dt);
        y_euler = calcular_y_euler(y_euler, vy, dt);
        vy = calcular_velocidad_y(vy, gravedad, dt);
        tiempo += dt;
    }
}

double posicion_tiempo_exacto_euler(double velocidad,double angulo, double dt, double gravedad, double tiempo_exacto) {
    double y_euler = 0.0;
    // Definimos Valor inicial de la velocidad tanto en X como en Y con el valor de velocidad inicial que nos ingresaron
    double vy = velocidad*sin(transformar_a_radianes(angulo));
    double tiempo = 0;
    while(tiempo <= tiempo_exacto) {
        y_euler = calcular_y_euler(y_euler, vy, dt);
        vy = calcular_velocidad_y(vy, gravedad, dt);
        tiempo += dt;
    }
    return y_euler;
}

double calcular_orden(double error1, double error2,double dt1, double dt2)
{
    return log(error1 / error2) /log(dt1 / dt2);
}


int suma(int a, int b) {
    return a + b;
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