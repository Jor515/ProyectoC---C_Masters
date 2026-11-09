#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int leer_entero_rango(const char *mensaje, int minimo, int maximo, int *salida) {
    char linea[128];
    char *fin;
    long valor;

    if (mensaje == NULL || salida == NULL || minimo > maximo) {
        return 0;
    }

    for (;;) {
        printf("%s", mensaje);
        if (fgets(linea, sizeof linea, stdin) == NULL) {
            return 0;
        }

        errno = 0;
        valor = strtol(linea, &fin, 10);
        while (isspace((unsigned char)*fin)) {
            fin++;
        }

        if (fin == linea || *fin != '\0' || errno == ERANGE ||
            valor < minimo || valor > maximo) {
            printf("Entrada invalida. Ingresa un entero entre %d y %d.\n",
                   minimo, maximo);
            continue;
        }

        *salida = (int)valor;
        return 1;
    }
}

int leer_double_positivo(const char *mensaje, double *salida) {
    char linea[128];
    char *fin;
    double valor;

    if (mensaje == NULL || salida == NULL) {
        return 0;
    }

    for (;;) {
        printf("%s", mensaje);
        if (fgets(linea, sizeof linea, stdin) == NULL) {
            return 0;
        }

        errno = 0;
        valor = strtod(linea, &fin);
        while (isspace((unsigned char)*fin)) {
            fin++;
        }

        if (fin == linea || *fin != '\0' || errno == ERANGE ||
            !isfinite(valor) || valor <= 0.0) {
            printf("Entrada invalida. Ingresa un numero mayor que cero.\n");
            continue;
        }

        *salida = valor;
        return 1;
    }
}