#ifndef REPORTES_H
#define REPORTES_H

#include <stddef.h>
#include "simulador.h"

void mostrar_resultados(const Mision *mision, const Resultado *resultado);
void mostrar_analisis(void);
void mostrar_historial(const Resultado historial[], size_t cantidad);

#endif