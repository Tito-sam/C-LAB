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
    float promedio = suma/cantidad;
    printf("la suma es: %f\n",suma);
    printf("El promedio es: %f\n", promedio);
    printf("El numero mayor es: %d\n", mayor);

    free(numeros);
    return 0;
}
