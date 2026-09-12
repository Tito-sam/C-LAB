#include <stdio.h>


// Forma de definir un struct con una palabra identificadora, para quitar el struct al momento de inicializar
typedef struct {
    double x;
    double y;
} Punto;

void mover(Punto *p);

int main() {
    Punto p = {10.0, 20.0};
    printf("x = %.2f, y = %.2f\n",p.x,p.y);
    mover(&p);
    printf("x = %.2f, y = %.2f\n",p.x,p.y);
}


void mover(Punto *p) {
    p ->x += 5;
    p ->y += 10;
}