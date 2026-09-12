#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Forma de definir un struct con una palabra identificadora, para quitar el struct al momento de inicializar
typedef struct {
    char nombre[30];
    double nota;
} Estudiante;

void mostrar_estudiantes(Estudiante estudiantes[], size_t cantidad_estudiantes);

int main() {
    Estudiante *estudiantes;
    int cantidad_estudiantes;
    printf("Cuantos estudiantes quieres ingresar?\n");
    scanf("%d",&cantidad_estudiantes);
    estudiantes = malloc(cantidad_estudiantes * sizeof(Estudiante));
    if (estudiantes == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }
    double nota_alta;
    char nombre[30];
    for (int i = 0 ; i < cantidad_estudiantes; i++) {
        printf("Digita el nombre del estudiante: ");
        scanf("%s", estudiantes[i].nombre);
        printf("Digita su nota: \n");
        scanf("%lf",&estudiantes[i].nota);
        if (i == 0) {
            nota_alta = estudiantes[i].nota;
            strcpy(nombre, estudiantes[i].nombre);
        } else if (nota_alta < estudiantes[i].nota) {
            nota_alta = estudiantes[i].nota;
            strcpy(nombre, estudiantes[i].nombre);
        }
    }
    printf("Lista de estudiantes\n");
    mostrar_estudiantes(estudiantes, cantidad_estudiantes);
    printf("Nota mas alta: %.2f\nEstudiante: %s\n",nota_alta, nombre);
    free(estudiantes);
    return 0;
}

void mostrar_estudiantes(Estudiante *estudiantes, size_t cantidad_estudiantes) {
    for (size_t i = 0; i < cantidad_estudiantes; i++) {
        printf("%s nota: %.2f\n",(estudiantes+i)->nombre, (estudiantes+i)->nota);
    }
}