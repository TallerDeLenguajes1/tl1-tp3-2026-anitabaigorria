#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

void MostrarPersonas(char *V[]);
// void MostrarPersonas1(char **V[],int N);

// VERSION PUNTERO SIMPLE (tamaño estático de vector principal (5) y tamaño de cada elemento (nombre) asignado dinámicamente)
int main(){
    char *V[5], buffer[MAX];
    
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre: \n");
        fflush(stdin);
        gets(buffer);

        V[i] = (char *)malloc((strlen(buffer)+1)*sizeof(char)); 
        strcpy(V[i],buffer);
    }

    MostrarPersonas(V);
    
    //  LIBERO NOMBRES ALMACENADOS DINÁMICAMENTE
    for (int i = 0; i < 5; i++) {
    free(V[i]);
    }
}

// VERSION CON PUNTERO DOBLE (tamaño de vector principal y de cada elemento (nombre) asignado dinámicamente)
// int main(){
//     char **V,buffer[MAX];
//     int N;
    
//     // pedir cantidad de nombres a cargar
//     printf("Cantidad de nombres a cargar: \n");
//     scanf("%d",&N);

//     // asigno dinamicamente ese espacio para la cantidad de nombres (arreglo dinámico DE PUNTEROS)
//     V = (char **)malloc(N*sizeof(char *)); // genero N espacios en la primera direccion a la que está apuntando

//     for (int i = 0; i < N; i++)
//     {
//         printf("Ingrese el nombre: \n");
//         fflush(stdin);
//         gets(buffer);

//         V[i] = (char *)malloc((strlen(buffer)+1)*sizeof(char)); 
//         strcpy(V[i],buffer);
//     }

//     for (int j = 0; j < N; j++)
//     {
//         MostrarPersonas1(V[j],N);
//     }
    
    
//     //  LIBERO NOMBRES ALMACENADOS DINÁMICAMENTE
//     for (int i = 0; i < 5; i++) {
//     free(V[i]);
//     }

//     // LIBERO ARREGLO PRINCIPAL
//     free(V);
// }


void MostrarPersonas(char *V[]){
    for (int i = 0; i < 5; i++)
    {
        puts(V[i]);
    }    
}

// void MostrarPersonas1(char **V[],int N){
//     for (int i = 0; i < N; i++)
//     {
//         puts(V[i]);
//     }  
// }

