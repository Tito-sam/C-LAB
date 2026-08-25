# C-LAB

Laboratorio personal de programación científica e ingeniería.

## Descripción

C-LAB es un laboratorio personal de programación científica desarrollado
como parte del aprendizaje de programación aplicada a la ingeniería mecánica.

El proyecto busca implementar modelos físicos y métodos numéricos utilizando
principalmente C y Python, relacionando conceptos de programación con
problemas de mecánica, transferencia de calor, fluidos y otras áreas de la
ingeniería.

## Objetivos


- Fortalecer los fundamentos del lenguaje C.
- Aprender C++ mediante proyectos de ingeniería.
- Desarrollar posteriormente herramientas de análisis científico en Python.
- Implementar métodos numéricos desde cero.
- Comparar soluciones analíticas y numéricas.
- Analizar errores y convergencia.
- Aplicar conceptos de matemáticas, física e ingeniería mediante programación.
- Desarrollar herramientas que puedan evolucionar hacia simuladores educativos.

## Proyecto 01 - Simulación de proyectil con método de Euler

### Problema

Se estudia el movimiento de un proyectil lanzado con una velocidad inicial
y un ángulo determinado, considerando únicamente la aceleración producida
por la gravedad.

El objetivo es comparar la solución analítica del movimiento con una solución
numérica obtenida mediante el método de Euler y estudiar el error producido
por diferentes tamaños de paso temporal.

### Modelo matemático

Para un proyectil sin resistencia del aire:

$$
x(t) = v_0 \cos(\theta)t
$$

$$
y(t) = v_0 \sin(\theta)t - \frac{1}{2}gt^2
$$

donde:

- $v_0$ es la velocidad inicial.
- $\theta$ es el ángulo de lanzamiento.
- $g$ es la aceleración gravitacional.
- $t$ es el tiempo.

### Método de Euler

Para resolver numéricamente el movimiento se utiliza el método de Euler.

La posición se actualiza mediante:

$$
x_{n+1}=x_n+v_{x,n}\Delta t
$$

$$
y_{n+1}=y_n+v_{y,n}\Delta t
$$

y la velocidad vertical mediante:

$$
v_{y,n+1}=v_{y,n}-g\Delta t
$$

El tamaño del paso $\Delta t$ se modifica para estudiar cómo afecta la
precisión de la solución.

### Análisis del error

El error absoluto se calcula mediante:

$$
E=|y_{\text{exacta}}-y_{\text{Euler}}|
$$

También se calcula experimentalmente el orden de convergencia mediante:

$$
p =
\frac{\ln(E_1/E_2)}
{\ln(\Delta t_1/\Delta t_2)}
$$

Finalmente, se utiliza Python y NumPy para realizar un ajuste lineal
en escala logarítmica:

$$
\ln(E)=\ln(C)+p\ln(\Delta t)
$$

La pendiente de esta recta permite estimar experimentalmente el orden
de convergencia del método.

### Resultados

Los resultados obtenidos fueron:

| Δt | Error (m) | Error (%) |
|---:|---:|---:|
| 0.100 | 0.687 | 6.742 |
| 0.050 | 0.343 | 3.371 |
| 0.010 | 0.069 | 0.674 |
| 0.005 | 0.036 | 0.357 |
| 0.001 | 0.007 | 0.071 |

El ajuste mediante NumPy produjo:

$$
p \approx 0.9933
$$

El resultado es cercano al valor teórico:

$$
p=1
$$

por lo que los resultados experimentales son consistentes con el
comportamiento esperado para el método de Euler.

### Tecnologías utilizadas

- C
- GCC
- Python
- NumPy
- Matplotlib
- CSV
- Linux

### Resultados

### Análisis

## Estructura del proyecto

## Tecnologías utilizadas