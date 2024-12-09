#include <stdio.h>
#define N 7

void menu();
float promedio();
void registroTemperaturas();
int diaExtremo(int *p);
void tendencia(int *p);

int *arreglo;

int main() {
    menu();
    return 0;
}

void menu() {
    int temperaturas[N] = {0}; // Inicializa con ceros
    arreglo = temperaturas;
    int opcion = 0;

    do {
        puts("1) Promedio Semanal");
        puts("2) Registrar Temperaturas");
        puts("3) Dia mas frio y calido");
        puts("4) Tendencia");
        puts("5) Salir");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Promedio semanal: %.2f\n", promedio());
                break;
            case 2:
                registroTemperaturas();
                break;
            case 3:
                diaExtremo(temperaturas);
                break;
            case 4:
                tendencia(temperaturas);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 5);
}

void registroTemperaturas() {
    int *p;
    for (p = arreglo; p < (arreglo + N); p++) {
        printf("Ingrese temperatura: ");
        scanf("%d", p);
    }
    printf("Temperaturas registradas:\n");
    for (p = arreglo; p < (arreglo + N); p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

float promedio() {
    int *p;
    int suma = 0;
    for (p = arreglo; p < (arreglo + N); p++) {
        suma += *p;
    }
    return (float)suma / N;
}

int diaExtremo(int *p) {
    int min = 100, max = -100;
    int diaMin = 0, diaMax = 0;
    int opcion;

    puts("1) Dia mas calido");
    puts("2) Dia mas frio");
    scanf("%d", &opcion);

    for (int i = 0; i < N; i++) {
        if (p[i] > max) {
            max = p[i];
            diaMax = i + 1; // Guardar el día (índice + 1)
        }
        if (p[i] < min) {
            min = p[i];
            diaMin = i + 1; // Guardar el día (índice + 1)
        }
    }

    if (opcion == 1) {
        printf("Dia mas calido: Dia %d con %d grados\n", diaMax, max);
    } else if (opcion == 2) {
        printf("Dia mas frio: Dia %d con %d grados\n", diaMin, min);
    } else {
        printf("Opción no válida.\n");
    }

    return 0;
}

void tendencia(int *p) {
    int contadorAumento = 0, maxAumento = 0;
    int contadorDecremento = 0, maxDecremento = 0;
    int aux = *p;

    for (p = arreglo + 1; p < (arreglo + N); p++) {
        if (*p > aux) {
            contadorAumento++;
            maxDecremento = (contadorDecremento > maxDecremento) ? contadorDecremento : maxDecremento;
            contadorDecremento = 0;
        } else if (*p < aux) {
            contadorDecremento++;
            maxAumento = (contadorAumento > maxAumento) ? contadorAumento : maxAumento;
            contadorAumento = 0;
        }
        aux = *p;
    }

    maxAumento = (contadorAumento > maxAumento) ? contadorAumento : maxAumento;
    maxDecremento = (contadorDecremento > maxDecremento) ? contadorDecremento : maxDecremento;

    printf("Dias consecutivos de aumento: %d\n", maxAumento);
    printf("Dias consecutivos de decremento: %d\n", maxDecremento);
}
