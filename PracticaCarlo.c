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
    int calificaciones [10];
    p = calificaciones;
    do{
        printf("Favor de seleccionar una opcion:");
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
        }while (opcion!= 5);

    }
void registrarValores(int *calificaciones){
    int *cal = calificaciones;
    int *liam;
    liam = calificaciones;
    for (int i = 0; i < 10; i++){
        scanf("%d", cal);
        cal++;
    }
    for (int j = 0; j< 10; j++){
        printf("%d ", *liam);
        liam++;
    }
    printf("\n");
}
float promedio_calificaciones(){
    int *j;
    j = p;
    int suma = 0;
    for(int i = 0; i < 10; i++){
    suma+= *j;
    j++;
    }
    int promedio =suma/10;
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