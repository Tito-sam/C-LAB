#include <stdio.h>
#include <string.h>

struct Estudiante {
    char nombre[30];
    double nota;
};

void mostrar_estudiantes(struct Estudiante estudiantes[], int cantidad_estudiantes);

int main() {
    struct Estudiante estudiantes[3];
    strcpy(estudiantes[0].nombre, "Ana");
    estudiantes[0].nota = 4.5;
    strcpy(estudiantes[1].nombre, "Carlos");
    estudiantes[1].nota = 3.8;
    strcpy(estudiantes[2].nombre, "Luis");
    estudiantes[2].nota = 4.2;

    int cantidad_estudiantes = sizeof(estudiantes) / sizeof(estudiantes[0]);
    mostrar_estudiantes(estudiantes, cantidad_estudiantes);
    return 0;
}

void mostrar_estudiantes(struct Estudiante estudiantes[], int cantidad_estudiantes) {
    for (int i = 0; i < cantidad_estudiantes; i++) {
        printf("%s nota: %.2f\n",estudiantes[i].nombre, estudiantes[i].nota);
    }
}