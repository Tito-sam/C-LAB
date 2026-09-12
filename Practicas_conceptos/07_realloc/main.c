#include <stdio.h>
#include <stdlib.h>


int main() {
    int *numeros;
    int cantidad;
    printf("Digite la cantidad de numeros a ingresar: \n");
    scanf("%d", &cantidad);
    numeros = malloc(cantidad*sizeof(int));
    float suma = 0;
    int mayor;
    for (int i = 0; i< cantidad; i++) {
        printf("ingrese el numero: \n");
        scanf("%d", &numeros[i]);
        printf("%d\n",numeros[i]);
        suma =suma + numeros[i];
        if (i == 0) {
            mayor = numeros[i];
        } else if(mayor < numeros[i]) {
            mayor = numeros[i];
        }
    }
    int num_adicionales;
    printf("Cuantos datos quieres agregar de mas?\n");
    scanf("%d",&num_adicionales);
    if(num_adicionales > 0) {
        int *temporal = realloc(numeros, (cantidad+num_adicionales)*sizeof(int));
        if (temporal != NULL) {
            numeros = temporal;
            for(int i = cantidad; i < (cantidad+num_adicionales);i++) {
                printf("ingrese el numero: \n");
                scanf("%d", &numeros[i]);
                printf("%d\n",numeros[i]);
                suma += numeros[i];
                if(mayor < numeros[i]) {
                    mayor = numeros[i];
                }
            }
        } else {
            printf("No se pudieron agregar mas datos\n");
        }
    }
    float promedio = suma/(cantidad+num_adicionales);
    printf("la suma es: %f\n",suma);
    printf("El promedio es: %f\n", promedio);
    printf("El numero mayor es: %d\n", mayor);

    free(numeros);
    return 0;
}
