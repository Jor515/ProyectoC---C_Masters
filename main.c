#include <stdio.h>
#include <stddef.h>

#include "simulador.h"
#include "validaciones.h"
#include "reportes.h"

int main(void) {
    int opcion;
    int calcular;
    size_t cantidad_historial = 0;
    Resultado historial[MAX_HISTORIAL];
    Mision mision;
    Resultado resultado;

    for (;;) {
        printf("\n=== Simulador Artemis: Situación N°3 ===\n");
        printf("1. Calcular con los datos de la consigna\n");
        printf("2. Ingresar otros valores\n");
        printf("3. Ver explicacion de los incisos a y d\n");
        printf("4. Ver historial de energias\n");
        printf("0. Salir\n");

        if ((!leer_entero_rango("Elegí una opción: ", 0, 4, &opcion))) {
        printf("\nNo se pudo leer la opción. Cerrando el programa. \n");
        return 1;


        if (opcion == 0) {
            break;
        }

        calcular = 0;

        switch (opcion) {
            case 1:
                mision.masa_kg = MASA_ORION_CONSIGNA_KG;
                mision.velocidad_m_s = VELOCIDAD_TLI_CONSIGNA_MS;
                calcular = 1;
                break;

            case 2:
                if (!leer_double_positivo("Masa de Orion en kg: ",
                                          &mision.masa_kg) ||
                    !leer_double_positivo("Velocidad TLI en m/s: ",
                                          &mision.velocidad_m_s)) {
                    printf("No se pudieron leer los datos. Cerrando el programa.\n");
                    return 1;
                }
                calcular = 1;
                break;

            case 3:
                mostrar_analisis();
                break;

            case 4:
                mostrar_historial(historial, cantidad_historial);
                continue;;
        }

        if (calcular) {
        if (!calcular_energia(&mision, &resultado)) {
            printf("No se pudo calcular. Revisa los valores sean positivos. \n");
            continue;
            }   
        }

        mostrar_resultados(&mision, &resultado);

        if (cantidad_historial < MAX_HISTORIAL) {
            historial[cantidad_historial] = resultado;
            cantidad_historial++;
        } else {
            printf("El historial está lleno. Este calculo no se guardó. \n");
        }
    }  


    printf("Simulador finalizada.\n");
    return 0;
}


