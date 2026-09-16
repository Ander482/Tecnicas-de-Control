# Control de Motor DC en MATLAB & Simulink

Repositorio enfocado en la identificación experimental y diseño e implementación de algoritmos de control en simulink sobre un motor de corriente continua accionado mediante un microcontrolador ESP32 en tiempo real .

---

## 💡 ¿Por qué MATLAB & Simulink?

El desarrollo de sistemas de control en ingeniería suele presentar una brecha entre la formulación matemática y la implementación en hardware físico. El entorno MATLAB & Simulink reduce esta brecha gracias a las siguientes ventajas:

1. **Abstracción visual e intuitiva:** El modelado por diagramas de bloques en Simulink permite conceptualizar lazos de realimentación, funciones de transferencia y no linealidades sin perderse en la sintaxis de bajo nivel (configuración manual de registros, interrupciones o temporizadores PWM).
2. **Ecosistema de control unificado:** Integra herramientas industriales en una sola plataforma: desde la estimación paramétrica con *System Identification Toolbox*, hasta el ajuste asistido con *PID Tuner* y la síntesis de controladores avanzados.
3. **Monitoreo y ajuste en tiempo real (*External Mode*):** Permite sintonizar ganancias (*on-the-fly tuning*), registrar variables experimentales y contrastar la respuesta física contra el modelo teórico directamente mientras el motor está en funcionamiento.
4. **Escalabilidad algorítmica:** La misma planta experimental sirve como banco de pruebas modular para avanzar progresivamente desde un control clásico (PID) hacia técnicas modernas e inteligentes (LQR, MPC, Redes Neuronales).

> **Estado del Proyecto:** Repositorio en **desarrollo activo**. Actualmente se encuentran documentadas la base de hardware, la identificación del sistema y el control PID en posición y velocidad. Próximamente se integrarán controladores en espacio de estados y basados en optimización/aprendizaje.

---

## 📌 Mapa de Navegación del Proyecto

| Fase / Módulo | Descripción | Enlace a la Documentación |
| :--- | :--- | :--- |
| **00. Hardware & Setup** | Especificaciones del motor JGA25-371, pinout del ESP32, driver L298N y esquemático eléctrico. | [Ver Módulo 0](./00_documentation/README.md) |
| **01. Identificación** | Curva de reacción, System Identification Toolbox y obtención de la función de transferencia. | [Ver Módulo 1](./01_system_identification/README.md) |
| **02. Control PID** | Lazos de posición y velocidad (cascada, anti-windup y análisis de respuesta transitoria). | [Ver Módulo 2](./02_pid_control/README.md) |
<!--
| **03. Control LQR** | Representación en espacio de estados y regulador cuadrático lineal óptimo. | [Ver Módulo 3](./03_lqr_control/README.md) |
| **04. Control MPC** | Control Predictivo Basado en Modelo considerando restricciones físicas de voltaje y corriente. | [Ver Módulo 4](./04_mpc_control/README.md) |
| **05. Control Neuronal** | Redes neuronales para control adaptativo o compensación no lineal. | [Ver Módulo 5](./05_neural_control/README.md) |
-->

---

## 🛠️ Requisitos de Software

* **MATLAB & Simulink** (R2026a o superior recomendado)
* **Toolboxes requeridos:**
  * Control System Toolbox
  * System Identification Toolbox
* **Hardware Support Packages:**
  * *MATLAB Support Package for Arduino Hardware* (compatible con la arquitectura ESP32 en Simulink)

---

