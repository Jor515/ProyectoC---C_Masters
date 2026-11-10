# Simulador Artemis - Situacion 3: Inyeccion Translunar - TLI e Inercia en Trayectoria Libre (1.ª Ley de Newton y Energía) 

## Integrantes

- Ramirez, Lautaro Agustin
-
- 
- Varela, Juan Diego
- Zapatero, Jorge Ezequiel

### Comision: 
- ISI C

## Descripcion

Este programa de consola representa simplificada pero bien hecha, algunos calculos de la situacion 3 de la Situación 3: la inyeccion translunar (TLI) de la nave Orion y su movimiento luego del apagado de los motores .

El menu permite calcular con los datos de la consigna o ingresar una masa y una velocidad TLI diferentes, luego el programa informa la energia cinetica inicial, la gravedad terrestre estimada en LEO y un calculo simplificado del trabajo externo hasta un punto de equilibrio Tierra-Luna. Tambien muestra una explicacion conceptual de los incisos a y d y conserva un historial de hasta diez calculos.

## Situacion y reglas

En la situacion asignada, la etapa ICPS impulsa a Orion hasta 10.900 m/s para iniciar la inyeccion translunar y luego se desacopla, los motores principales quedan apagados. La nave continua moviendose por inercia mientras la gravedad modifica su velocidad. Tambien se pide analizar su energia y comparar cualitativamente la energia necesaria para viajar desde la Tierra con la del regreso desde la Luna.
Reglas de uso del programa:

1. El usuario elige si calcular con los valores de la consigna o ingresar masa y velocidad propias.
2. Los valores ingresados deben ser numeros finitos mayores que cero.
3. El programa muestra los resultados y los agrega al historial, hasta un maximo de diez calculos.
4. El usuario puede consultar el analisis conceptual, revisar el historial o salir.

## Archivos

- `main.c`: el archivo que define el menu principal, el flujo del programa y el historial.
- `simulador.c` y `simulador.h`: las estructuras, las constantes y los calculos fisicos.
- `validaciones.c` y `validaciones.h`: la lectura validada de opciones, masa y velocidad.
- `reportes.c` y `reportes.h`: reporte de resultados, las explicaciones y el historial.

## Uso

1. Opción 1: calcula con los valores de la consigna.
2. Opcion 2: el usuario debe ingresar masa y velocidad propias, ambas mayores que cero.
3. Opcion 3: para consultar la explicacion conceptual de los incisos a y d.
4. Opcion 4: el historial, donde se ve los calculos guardados durante la ejecucion.
5. Opcion 0: salir del programa.

## Uso de inteligencia artificial

Se utilizo `ChatGPT Work 6 (Luna)` como apoyo para interpretar la consigna que se nos asignó, nos ayudó a organizar la modularizacion en C, revisar las formulas propuestas y preparar borradores de los archivos fuente (mas que nada como para verificar el funcionamiento del código), como tambien ayudar a redactar el README.

Consultas (prompts) realizadas durante el trabajo:

- "Mi situacion es la situacion 3, me podes dar un planteo para tener una guia e interpretar la consigna."
- "Como puedo organizar mejor cada archivo .c y .h?"
- "Te pasé un `readme.txt` como puedo mejorar la redacción antes de subirlo a github."
