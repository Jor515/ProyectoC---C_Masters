# Simulador Artemis - Situacion 3: Inyeccion Translunar - TLI e Inercia en Trayectoria Libre (1.ª Ley de Newton y Energía) 

## Integrantes

- Gariboglio, Matías Adriel
- Ramirez, Lautaro Agustin
- Torres Ocampo, Franco Joaquin
- Varela, Juan Diego
- Zapatero, Jorge Ezequiel

### Comision: 
- ISI C

## Descripcion

Este programa de consola representa simplificada pero bien hecha, algunos calculos de la situacion 3 de la Situación 3: la inyeccion translunar (TLI) de la nave Orion y su movimiento luego del apagado de los motores .

El menu permite calcular con los datos de la consigna o ingresar una masa y una velocidad TLI diferentes, luego el programa informa la energia cinetica inicial, la gravedad terrestre estimada en LEO y un calculo simplificado del trabajo externo hasta un punto de equilibrio Tierra-Luna. Tambien muestra una explicacion conceptual de los incisos a y d y conserva un historial de hasta diez calculos.

## Modelo fisico y supuestos

Se usan los datos de la consigna: masa de Orion de 26.000 kg, velocidad TLI de 10.900 m/s, altura LEO de 192.000 m, distancia media Tierra-Luna de 384.000.000 m, masa terrestre de 5,972 x 10^24 kg, radio terrestre de 6.371.000 m y constante gravitatoria G = 6,674 x 10^-11 N m^2/kg^2.

La consigna no especifica la masa lunar. Para el calculo del inciso c se adopto el valor aproximado de 7,346 x 10^22 kg, publicado por [NASA NSSDC](https://nssdc.gsfc.nasa.gov/planetary/factsheet/moonfact.html).

El calculo del punto de equilibrio supone que la nave, la Tierra y la Luna estan sobre una misma linea y busca el punto donde las magnitudes de las fuerzas gravitatorias se igualan. Es una aproximacion didactica; no calcula el punto L1 en el sistema rotante Tierra-Luna ni integra una trayectoria real de retorno libre.

Para el trabajo externo del inciso c se supone que la nave llega al punto calculado y queda en reposo. Se aplica el balance entre el cambio de energia potencial gravitatoria y la energia cinetica inicial. Si se modifican los supuestos o la velocidad, el resultado tambien cambia.

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

## Compilacion y ejecucion

Se necesita un compilador de C con soporte para C11, por ejemplo GCC.
En Windows con GCC, desde la carpeta del proyecto (en PowerShell o desde la consola del Visual Studio Code):

~~~bash
gcc -std=c11 -Wall -Wextra main.c simulador.c validaciones.c reportes.c -o artemis.exe -lm
~~~

~~~powershell
.\artemis.exe
~~~
