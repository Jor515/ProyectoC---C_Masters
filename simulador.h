#ifndef SIMULADOR_H
#define SIMULADOR_H

#define MAX_HISTORIAL 10

#define G_CONST 6.674e-11
#define MASA_TIERRA_KG 5.972e24
#define MASA_LUNA_KG 7.346e22
#define RADIO_TIERRA_M 6371000.0
#define ALTURA_LEO_M 192000.0
#define DISTANCIA_TIERRA_LUNA_M 384000000.0

#define MASA_ORION_CONSIGNA_KG 26000.0
#define VELOCIDAD_TLI_CONSIGNA_MS 10900.0

typedef struct {
    double masa_kg;
    double velocidad_m_s;
} Mision;

typedef struct {
    double energia_cinetica_j;
    double gravedad_leo_m_s2;
    double punto_equilibrio_m;
    double trabajo_externo_j_kg;
    double trabajo_externo_total_j;
} Resultado;


int calcular_resultados(const Mision *mision, Resultado *resultado);

#endif