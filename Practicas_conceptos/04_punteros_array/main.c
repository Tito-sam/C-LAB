#include <stddef.h>
#include <stdio.h>


int numeros[5] = {10, 20, 30, 40 ,50};

void array_puntero(int *num, size_t tam);

int main() {
    size_t tam = sizeof(numeros)/sizeof(numeros[0]);
    int *p = numeros;
    array_puntero(p, tam);
}

void array_puntero(int *num, size_t tam) {
    for(size_t i = 0; i < tam; i++) {
        printf("%d\n", *(num + i));
    }
}
