#include <stddef.h>
#include <stdio.h>
#include <string.h>


// Forma de definir un struct con una palabra identificadora, para quitar el struct al momento de inicializar
typedef struct {
    char nombre[30];
    double nota;
} Estudiante;

void mostrar_estudiantes(Estudiante *estudiantes, size_t cantidad_estudiantes);

int main() {
    Estudiante estudiantes[3];
    strcpy(estudiantes[0].nombre, "Ana");
    estudiantes[0].nota = 4.5;
    strcpy(estudiantes[1].nombre, "Carlos");
    estudiantes[1].nota = 3.8;
    strcpy(estudiantes[2].nombre, "Luis");
    estudiantes[2].nota = 4.2;

    size_t cantidad_estudiantes = sizeof(estudiantes) / sizeof(estudiantes[0]);
    Estudiante *puntero = estudiantes;
    mostrar_estudiantes(puntero, cantidad_estudiantes);
    return 0;
}

void mostrar_estudiantes(Estudiante *estudiantes, size_t cantidad_estudiantes) {
    for (size_t i = 0; i < cantidad_estudiantes; i++) {
        printf("%s nota: %.2f\n",(estudiantes + i)->nombre, (estudiantes +i )->nota);
    }
}