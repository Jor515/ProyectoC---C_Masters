#include <stdio.h>
#include "reportes.h"

void mostrar_resultados(const Mision *mision, const Resultado *resultado) {
    if (mision == NULL || resultado == NULL) {
        printf("No hay resultados para mostrar.\n");
        return;
    }

    printf("\n--- Reporte de Misión TLI ---\n");
    printf("Masa de Orion: %.2f kg\n", mision->masa_kg);
    printf("Velocidad TLI: %.2f m/s\n", mision->velocidad_m_s);
    printf("Energia cinetica inicial: %.3e J\n", resultado->energia_cinetica_j);
    printf("Gravedad terrestre en LEO: %.3f m/s^2\n",
           resultado->gravedad_leo_m_s2);
    printf("Punto de equilibrio aproximado: %.2f km desde el centro terrestre\n",
           resultado->punto_equilibrio_m / 1000.0);

    if (resultado->trabajo_externo_j_kg >= 0.0) {
        printf("Trabajo externo adicional (por kg): %.3e J/kg\n",
               resultado->trabajo_externo_j_kg);
        printf("Trabajo externo adicional (nave completa): %.3e J\n",
               resultado->trabajo_externo_total_j);
    } else {
        printf("No haria falta trabajo externo adicional para llegar al punto\n");
        printf("y quedar en reposo; el excedente a disipar seria %.3e J/kg.\n",
               -resultado->trabajo_externo_j_kg);
    }

    printf("Modelo simplificado sobre la linea Tierra-Luna; llegada en reposo.\n");
}

void mostrar_analisis(void) {
    printf("\n--- Analisis Conceptual ---\n");
    printf("a) Al apagarse los motores, la nave conserva su movimiento por inercia.\n");
    printf("   La gravedad terrestre atrae la nave y reduce su rapidez radial\n");
    printf("   mientras se aleja. Esa atraccion disminuye al aumentar la distancia.\n");
    printf("\n");
    printf("d) La Tierra tiene un campo gravitatorio mucho mas intenso que la Luna,\n");
    printf("   por eso salir de la Tierra requiere mas energia por unidad de masa.\n");
    printf("   No se puede calcular la masa exacta de combustible sin datos del motor.\n");
}

void mostrar_historial(const Resultado historial[], size_t cantidad) {
    size_t i;

    if (cantidad == 0) {
        printf("Todavia no hay calculos guardados.\n");
        return;
    }

    printf("\n--- Historial de Calculos ---\n");
    for (i = 0; i < cantidad; i++) {
        printf("%zu. Energia cinetica: %.3e J | Trabajo adicional: %.3e J\n",
               i + 1,
               historial[i].energia_cinetica_j,
               historial[i].trabajo_externo_total_j);
    }
}
