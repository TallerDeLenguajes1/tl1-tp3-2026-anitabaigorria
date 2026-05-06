// interfaz de usuario para cada preventista de una empresa, donde hace su respectiva carga de clientes de manera manual y productos de forma aleatoria, con el limite de que cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo puede pedir hasta 10 productos.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 50

// 1° declaramos estructuras y elementos a utilizar
char *TiposProductos[]={
    "Galletas",
    "Snack",
    "Cigarrillos",
    "Caramelos",
    "Bebidas"
};

struct { 
    int ProductoID; //Numerado en ciclo iterativo       
    int Cantidad; // entre 1 y 10  
    char *TipoProducto; // Algún valor del arreglo TiposProductos       
    float PrecioUnitario; // entre 10 - 100 
} typedef Producto;  

struct {   
    int ClienteID; // Numerado en el ciclo iterativo              
    char *NombreCliente; // Ingresado por usuario 
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5) 
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”  
} typedef Cliente; 

float calcularCosto(int cantidad, float costoUnitario);
void mostrarClientes(Cliente *cargado, int cant);
void liberarMemoriaClientes(Cliente *arreglo, int cant);

int main(){
    int N;
    char buffer[MAX];
    Cliente *clientes_cargar;

    srand(time(NULL));

    // 2° al iniciar el programa, pregunto la cantidad de clientes a cargar (hasta 5) y pido su reserva dinámicamente
    do
    {
        printf("Ingrese la cantidad de clientes a cargar (hasta 5): ");
        scanf("%d",&N);
        
        if (N<1 || N>5)
        {
            printf("Cantidad fuera del rango establecido. Ingrese nuevamente.\n");
        }
        
    } while (N<1 || N>5);
    
    clientes_cargar = (Cliente *)malloc(N*sizeof(Cliente));
    
    // 3° cargamos los datos
    for (int i = 0; i < N; i++)
    {
        clientes_cargar[i].ClienteID = i;

        // 3°_1 carga dinamica del nombre del cliente ingresado por el usuario, lo hacemos con reserva puntero a char (con arreglo estatico auxiliar (buffer) y strcpy())
        printf("Ingrese el nombre del cliente ID '%d': ",i);
        scanf("%s",buffer);

        // NombreCliente ya esta definido como puntero, guardamos dinamicamente el espacio para la cadena ingresada (cantidad de caracteres ingresados strlen(buffer) + caracter final de cadena * cantidad ocupada por el char en la memoria)
        clientes_cargar[i].NombreCliente = (char *)malloc((strlen(buffer)+1)*sizeof(char));
        // copiamos al arreglo dinamico principal
        strcpy(clientes_cargar[i].NombreCliente,buffer);
    
        // 3°_2 generamos aleatoriamente la cantidad de productos (entre 1 y 5) y hacemos la reserva dinamica para cargar se subarreglo
        clientes_cargar[i].CantidadProductosAPedir = 1 + rand()%5;
    
        clientes_cargar[i].Productos = (Producto *)malloc(clientes_cargar[i].CantidadProductosAPedir*sizeof(Producto));

        // 3°_3 cargamos los datos
        for (int j = 0; j < clientes_cargar[i].CantidadProductosAPedir; j++)
        {
            clientes_cargar[i].Productos[j].ProductoID = j;
            clientes_cargar[i].Productos[j].Cantidad = 1 + rand()%10;
            clientes_cargar[i].Productos[j].PrecioUnitario = 10 + rand()%91;

            // 'clientes_cargar[i]' es el arreglo principal dinamico, 'Productos[j]' es el subarreglo dinamico y 'TipoProducto' es un puntero a una cadena que definimos con un valor aleatorio de otro arreglo de cadenas definida mediante un puntero (apuntamos 'TipoProducto' a un elemento random de 'TiposProductos')
            clientes_cargar[i].Productos[j].TipoProducto = TiposProductos[rand()%5];
        }
        
    }

    // 4° una vez realizada la carga, llamamos a las funciones
    mostrarClientes(clientes_cargar,N);
    
    // 5° liberamos memoria utilizada
    liberarMemoriaClientes(clientes_cargar,N);
    return 0;
}

float calcularCosto(int cantidad, float costoUnitario){
    return (float)cantidad * costoUnitario;
}

void mostrarClientes(Cliente *cargado, int cant){
    float costoTotal = 0;
    for (int i = 0; i < cant; i++)
    {
        printf("\n--------------------------------- DATOS CARGADOS ---------------------------------\n");
        printf("| CLIENTE ID %d: %s - Productos encargados: %d |\n",cargado[i].ClienteID,cargado[i].NombreCliente,cargado[i].CantidadProductosAPedir);
        for (int j = 0; j < cargado[i].CantidadProductosAPedir; j++)
        {
            float costo = calcularCosto(cargado[i].Productos[j].Cantidad,cargado[i].Productos[j].PrecioUnitario);
            printf("           |_ PRODUCTO ID %d: %s = $%.2f c/u -> (x%d) = $%.2f \n",
                cargado[i].Productos[j].ProductoID,
                cargado[i].Productos[j].TipoProducto,
                cargado[i].Productos[j].PrecioUnitario,
                cargado[i].Productos[j].Cantidad,
                costo
            );
            costoTotal += costo;
        }
        printf("                       | MONTO TOTAL A PAGAR = $%.2f |\n",costoTotal);
    }
}

// hago una sola funcion para liberar de adentro hacia afuera la memoria utilizada en el heap durante el tiempo de ejecucion
void liberarMemoriaClientes(Cliente *arreglo, int cant){
    for (int i = 0; i < cant; i++)
    {
        free(arreglo[i].NombreCliente);
        free(arreglo[i].Productos);
    }
    
    free(arreglo);
}
