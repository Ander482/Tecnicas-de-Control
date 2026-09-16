
[← Volver al Menú Principal](../README.md)

# Módulo 01: Identificación de la Planta

En este módulo se documenta el proceso experimental para obtener la función de transferencia del motor DC utilizando el método de la curva de reacción y validación con la System Identification Toolbox.

## 1. Función de Transferencia Obtenida
La relación entre el voltaje de armadura $V(s)$ y la velocidad angular $\Omega(s)$ se modeló como un sistema de primer orden con retardo:

$$G(s) = \frac{\Omega(s)}{V(s)} = \frac{K}{\tau s + 1} e^{-\theta s}$$

*(Sustituye aquí los valores numéricos obtenidos)*

## 2. Resultados de la Identificación
A continuación se muestra el ajuste entre los datos experimentales y el modelo estimado:

![Curva de Reacción](./docs/img/step_response_curve.png)

## 3. Scripts y Simulación
* Ejecuta `scripts/run_identification.m` para reproducir el cálculo.
* La sesión exportada del toolbox se encuentra en `models/sys_id_session.sid`.