#include <stdio.h>

void mostrarMenu();
void registrarValores(int *calificaciones);
float promedio_calificaciones();
int calificacionBaja(int *calificaciones);
void modaCalificaciones(int *calificaciones);

int *p;

int main(){
    mostrarMenu();
    return 0;
}

void mostrarMenu(){
    int opcion;
    int calificaciones[10];
    p = calificaciones;
    do {
        printf("1) Registrar valores\n");
        printf("2) Promedio de calificaciones\n");
        printf("3) Calificacion mas baja\n");
        printf("4) Moda de calificaciones\n");
        printf("5) Salir\n");
        printf("Favor de seleccionar una opcion: ");
        scanf("%d", &opcion);

        if(opcion == 1){
            registrarValores(calificaciones);
        }
        if(opcion == 2){
            float resultado1 = promedio_calificaciones();
            printf("El promedio de las calificaciones es: %.2f\n", resultado1);
        }
        if(opcion == 3){
            int resultado2 = calificacionBaja(calificaciones);
            printf("La calificacion mas baja es: %d\n", resultado2);
        }
        if(opcion == 4){
            modaCalificaciones(calificaciones);
        }
    } while (opcion != 5);

    printf("Gracias por usar el programa. ¡Adios!\n");
}

void registrarValores(int *calificaciones){
    int *cal = calificaciones;
    for (int i = 0; i < 10; i++){
        printf("Ingrese la calificacion %d: ", i+1);
        scanf("%d", cal);
        cal++;
    }
    printf("Calificaciones registradas correctamente.\n");
}

float promedio_calificaciones(){
    int *j = p;
    int suma = 0;
    for(int i = 0; i < 10; i++){
        suma += *j;
        j++;
    }
    float promedio = suma / 10.0; 
    return promedio;
}

int calificacionBaja(int *calificaciones){
    int mincalificacion = 100;
    int *ptr = calificaciones; 
    for (int i = 0; i < 10; i++){
        if (*ptr < mincalificacion){
            mincalificacion = *ptr;
        }
        ptr++; 
    }
    return mincalificacion;
}

void modaCalificaciones(int *calificaciones){
    int *calif = calificaciones;
    int frecuencia[101] = {0}; 
    int moda = -1, maxFrecuencia = 0;

    for (int i = 0; i < 10; i++){
        frecuencia[calif[i]]++;
    }

    for (int i = 0; i <= 100; i++){
        if (frecuencia[i] > maxFrecuencia){
            maxFrecuencia = frecuencia[i];
            moda = i;
        }
    }

    if (maxFrecuencia > 1){
        printf("La moda es: %d (se repite %d veces)\n", moda, maxFrecuencia);
    } else {
        printf("No hay moda, todos los valores son únicos.\n");
    }
}
