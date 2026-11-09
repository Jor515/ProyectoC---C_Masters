#include <math.h>
#include "simulador.h"

int calcular_resultados(const Mision *mision, Resultado *resultado) {
    double radio_orbita_m;
    double distancia_equilibrio_m;
    double distancia_luna_inicio_m;
    double distancia_luna_final_m;
    double potencial_inicio_j_kg;
    double potencial_final_j_kg;
    double delta_potencial_j_kg;
    double energia_cinetica_j_kg;

    if (mision == NULL || resultado == NULL ||
        !isfinite(mision->masa_kg) || !isfinite(mision->velocidad_m_s) ||
        mision->masa_kg <= 0.0 || mision->velocidad_m_s <= 0.0) {
        return 0;
    }

    radio_orbita_m = RADIO_TIERRA_M + ALTURA_LEO_M;
    if (DISTANCIA_TIERRA_LUNA_M <= radio_orbita_m) {
        return 0;
    }

    distancia_equilibrio_m = DISTANCIA_TIERRA_LUNA_M /
        (1.0 + sqrt(MASA_LUNA_KG / MASA_TIERRA_KG));

    distancia_luna_inicio_m = DISTANCIA_TIERRA_LUNA_M - radio_orbita_m;
    distancia_luna_final_m = DISTANCIA_TIERRA_LUNA_M - distancia_equilibrio_m;

    potencial_inicio_j_kg =
        -(G_CONST * MASA_TIERRA_KG / radio_orbita_m)
        -(G_CONST * MASA_LUNA_KG / distancia_luna_inicio_m);

    potencial_final_j_kg =
        -(G_CONST * MASA_TIERRA_KG / distancia_equilibrio_m)
        -(G_CONST * MASA_LUNA_KG / distancia_luna_final_m);

    delta_potencial_j_kg = potencial_final_j_kg - potencial_inicio_j_kg;
    energia_cinetica_j_kg = 0.5 * mision->velocidad_m_s * mision->velocidad_m_s;

    resultado->energia_cinetica_j = energia_cinetica_j_kg * mision->masa_kg;
    resultado->gravedad_leo_m_s2 =
        G_CONST * MASA_TIERRA_KG / (radio_orbita_m * radio_orbita_m);
    resultado->punto_equilibrio_m = distancia_equilibrio_m;

    resultado->trabajo_externo_j_kg = delta_potencial_j_kg - energia_cinetica_j_kg;
    resultado->trabajo_externo_total_j =
        resultado->trabajo_externo_j_kg * mision->masa_kg;

    return 1;
}