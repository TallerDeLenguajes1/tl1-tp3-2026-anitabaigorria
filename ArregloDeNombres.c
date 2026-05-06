#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void MostrarPersonas(char *V[]);
// void MostrarPersonas1(char **V[],int N);
void BuscarNombre_id(char *V[], int id);
void BuscarNombre_palabra(char *V[], char palabra[]);

// VERSION PUNTERO SIMPLE (tamaño estático de vector principal (5) y tamaño de cada elemento (nombre) asignado dinámicamente)
int main(){
    char *V[5], buffer[MAX];
    int id;
    
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf("INICIANDO PROGRAMA...\n");
    printf("| CARGA DE NOMBRES |\n");
    
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre %d: ",i+1);
        fflush(stdin);
        fgets(buffer, sizeof(buffer), stdin);
        printf("\n");
        
        V[i] = (char *)malloc((strlen(buffer)+1)*sizeof(char)); 
        strcpy(V[i],buffer);
    }
    
    printf("| NOMBRES CARGADOS |\n");
    MostrarPersonas(V);
    
    int eleccion;
    do
    {
        printf("| COMO DESEA BUSCAR? 1=ID 0=PALABRA CLAVE |\n");
        scanf("%d",&eleccion);
        
        if (eleccion != 0 && eleccion != 1)
        {
            printf("Ingrese 0 o 1.\n");
        }
        
    } while (eleccion != 0 && eleccion != 1);
    
    if (eleccion == 1)
    {
        printf("Ingrese ID del nombre a buscar: ");
        scanf(" %d",&id);
        printf("\n");
        BuscarNombre_id(V,id);
    } else
    {
        printf("Ingrese palabra clave a buscar: ");
        fflush(stdin);
       fgets(buffer, sizeof(buffer), stdin);
        printf("\n");
        BuscarNombre_palabra(V,buffer);
    }
    
    //  LIBERO NOMBRES ALMACENADOS DINÁMICAMENTE
    for (int i = 0; i < 5; i++) {
    free(V[i]);
}
}

// PUNTO 4) - VERSION CON PUNTERO DOBLE (tamaño de vector principal y de cada elemento (nombre) asignado dinámicamente)
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
//             printf("Ingrese el nombre: \n");
//             fflush(stdin);
//             gets(buffer);

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
        printf("[%d] ", i);
        puts(V[i]);
    }    
    printf("\n");
}

// void MostrarPersonas1(char **V[],int N){
//     for (int i = 0; i < N; i++)
//     {
//         puts(V[i]);
//     }  
// }


void BuscarNombre_id(char *V[], int id){
    int bandera = 0;

    for (int i = 0; i < 5; i++)
    {
        if (i == id)
        {
            printf("PERSONA %d: ",id);
            puts(V[id]);

            bandera = 1;
        }
    }

    if (bandera == 0)
    {
        printf("No se encontro el valor buscado\n");
    }
}

void BuscarNombre_palabra(char *V[], char palabra[]){
    int bandera = 0;
    for (int i = 0; i < 5; i++)
    {
        if (strstr(V[i],palabra) != NULL)
        {
            printf("PALABRA '%s' ENCONTRADA DENTRO DE '%s'!\n",palabra,V[i]);

            bandera = 1;
            break;
        }
    }

    if (bandera == 0)
    {
        printf("-1\n");
    }
}