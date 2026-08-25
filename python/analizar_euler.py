import csv
import math
import matplotlib.pyplot as plt
import numpy as np

pasos = []
errores = []
errores_por = []

with open("resultados_euler.csv", "r") as archivo:
    lector = csv.DictReader(archivo)
    for fila in lector:
        dt = float(fila["dt"])
        pasos.append(dt)
        error = float(fila["error"])
        errores.append(error)
        error_porcentual = float(fila["error_porcentual"])
        errores_por.append(error_porcentual)

        print(f"dts = {pasos} \n errores = {errores}\n errores porcentual = {errores_por}\n")

for i in range(1,len(pasos)):
    orden = math.log(errores[i-1] / errores[i]) / math.log(pasos[i-1] / pasos[i])

    print(f"dt = {pasos[i]:.3f} | orden = {orden:.4f}")

log_pasos = []
log_errores = []

for paso in pasos:
    log_pasos.append(math.log(paso))

for error in errores:
    log_errores.append(math.log(error))

p = (log_errores[-1] - log_errores[0]) / (log_pasos[-1] - log_pasos[0])

print(f"Orden aproximado: {p:.4f}")


plt.plot(pasos, errores, marker="o")


plt.xlabel("Paso de tiempo Δt (s)")
plt.ylabel("Error absoluto (m)")
plt.title("Error de Euler vs. paso de tiempo")

plt.xscale("log")
plt.yscale("log")

plt.grid()
plt.show()

pasos_np = np.array(pasos)
errores_np = np.array(errores)
errores_por_np = np.array(errores_por)

print(type(pasos))
print(type(pasos_np))

print(pasos)
print(pasos *2)
print(pasos_np)
print(pasos_np *2)

log_pasos = np.log(pasos_np)
log_errores = np.log(errores_np)

print(log_pasos)
print(log_errores)

coeficientes = np.polyfit(log_pasos, log_errores, 1)
print(coeficientes)

p = coeficientes[0]
b = coeficientes[1]

ajuste = p*np.array(log_pasos) + b

plt.figure()

plt.plot(log_pasos, log_errores, marker="o")
plt.plot(log_pasos, ajuste)

plt.xlabel("ln(Δt)")
plt.ylabel("ln(Error)")
plt.title("Regresión lineal del error de Euler")

plt.grid()
plt.show()