# include <stdio.h>
# define N 3
# define DIAS 7

int *puntero;
void menu();
void registro(int *p);
int *totalSemanal();
int masVendido(int *p);
void noVendidos();
void superaMitad();
int main(){
    menu();
    return 0;
}

void menu(){
    int ventas[DIAS][N];
    puntero = &ventas[0][0];
    int opcion = 0;
    int *totalS;
    do{
        puts("1) Registro");
        puts("2) Total Semanal");
        puts("3) Mas Vendidos");
        puts("4) No Vendidos");
        puts("5) Salir");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                registro(&ventas[0][0]);
                superaMitad();
                break;
            case 2:
                totalS = totalSemanal();
                for(int i = 0; i < N; i++){
                    printf("Producto %d: %d ",i+1, *totalS);
                    totalS++;
                }
                printf("\n");
                break;
            case 3:
                printf("El Producto %d fue el mas vendido\n", masVendido(&ventas[0][0]));
                break;
            case 4:
                noVendidos();
                break;
        }        
    }while(opcion != 5);
}

void registro(int *p){
    int *puntero1, *puntero2;
    puntero1 = p;
    puntero2 = p;
    for(int i = 0; i < DIAS; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", puntero1);
            puntero1++;
        }
    }
    for(int i = 0; i < DIAS; i++){
        for(int j = 0; j < N; j++){
            printf("%d", *puntero2);
            puntero2++;
        }
        printf("\n");
    }
}

int *totalSemanal(){
    int *puntero1 = puntero;
    int static totalesSemanales[N] = {0};
    for(int i = 0; i < DIAS; i++){
        for(int j = 0; j < N; j++){
            totalesSemanales[j] += *puntero1;
            puntero1++;
        }
    }
    return totalesSemanales;
}

int masVendido(int *p){
    int *puntero1 = p;
    int totales[N] = {0};
    for(int i = 0; i < DIAS; i++){
        for(int j = 0; j < N; j++){
            totales[j] += *puntero1;
            puntero1++;
        }
    }
    int max = totales[0];
    int count = 1;
    for(int k = 1; k < N; k++){
        if(totales[k] > max){
            max = totales[k];
            count++;
        }
    }
    return count;
}

void noVendidos(){
    int *puntero1 = puntero;
    int totales[N] = {0};
    for(int i = 0; i < DIAS; i++){
        for(int j = 0; j < N; j++){
            totales[j] += *puntero1;
            puntero1++;
        }
    }
    for(int k = 0; k < N; k++){
        if(totales[k] == 0){
            printf("El producto %d no fue vendido\n", k+1);
        }
    }
}

void superaMitad(){
    int *puntero1 = puntero;
    int *puntero2 = puntero;
    int totales[N] = {0};
    int total = 0, mitad = 0;
    for(int i = 0; i < DIAS; i++){
        for(int j = 0; j < N; j++){
            total += *puntero1;
            puntero1++;
        }
    }
    mitad = total/2;
    for(int i = 0; i < DIAS; i++){
        for(int j = 0; j < N; j++){
            totales[j] += *puntero2;
            puntero2++;
        }
    }
    for(int i = 0; i < N; i++){
        if(totales[i] > mitad){
            printf("El producto %d supero la mitad de ventas, aumentar stock\n", i+1);
        }
    }
}