#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
#include <ctype.h>

/*#define  maxNumCaracToRead 200
#define max 10 //nodos diferenetes max que puede llegar a leer*/

//Estructutras finales para el proyecto final

//Estructura para la lectura de archivo
struct arrChar{
char leerCaracter[256];
char auxEntrada[256];
char nodosEntrada[256];
char nodoSalida[256];
char longitud[256];
};

//estructura de la arista del grafo
typedef struct {
    int vertice;
    int peso;
} aristaE;

//Estructura del vertice del grafo
typedef struct {
    aristaE **aristas;
    int longitudAristas;
    int tamanioArista;
    int distancia;
    int nodoPrevio;
    int nodoVisitado;
} verticeE;

//Estructura del grafo
typedef struct {
    verticeE **vertices;
    int longitudVertices;
    int tamanioVertice;
} nodoEstructura;

//Estructura para la crear la topologia
typedef struct {
    int *datosAlmacenados;
    int *auxNodo;
    int *indice;
    int longitudNodo;
    int tamanioNodo;
} pilaNodoE;


//Menu de Ayudaa
void menuHelp();

//imprime los errores
int validationError(int valida);

/*funciones topología*/
//Agrega la arista para la creacion de un grafo.
extern void agregarArista (nodoEstructura *nodo, int nodoOrigen, int nodoDestino, int costoArista);
//Agrega el nodo conectado a la arista
extern void agregaVertice (nodoEstructura *nodo, int i);

/*funciones  ruteo*/

/*pilaNodoE *creaPila(int nodoss);
Entrada: valor entero nodo
Salida: estructura de la pila del nodo
Proceso: crea la pila donde se guardaran los datos ordenados*/

extern pilaNodoE *creaPila (int nodoss);
void guardaPilaNodos (pilaNodoE *auxPilaNodos, int v, int p);

/*Entrada: estructura de la pila de nodos, entero que es el valor del nodo origen, entero valor distancia
Salida: Sin salida
Proceso: guarda los nodos y la distancia que se van formando en las iterraciones*/
extern void guardaPilaNodos (pilaNodoE *auxPilaNodos, int v, int p);

int propPila (pilaNodoE *auxPilaNodoE);

/*Entrada: estructura de la pila
Salida: valor entero
Proceso: Guarda todos los nodos, sacando los de menor costo en cada iteracción*/
extern int propPila (pilaNodoE *auxPilaNodoE);

void dijkstra (nodoEstructura *nodo, int nodoOrigen, int nodoDestino);

/*Entrada: estructura del nodo, nodo origen con valor int, nodo destino con valor int
Salida: Ninguno, solo el archivo de ruteo
Proceso: Esta función nos va a permitir ir sacando las posibles rutas que tiene un nodo origen
    al nodo destino, esto nos permite sacar la tabla de ruteo y guardarlo en el archivo ruteo.txt,
    también guardar todos los nodos para después sacar la ruta más corta*/
extern void dijkstra (nodoEstructura *nodo, int nodoOrigen, int nodoDestino);

/*int sacaMenor(pilaNodoE *h, int longNodo2, int z, int y);
Entrada: estructura del nodo, longitud y dos nodos a comparar con valor entero
Salida: valor del nodo entero menor
Proceso: compara los nodos para sacar el menor y guardarlo en la estructura*/
extern int sacaMenor (pilaNodoE *h, int longNodo2, int z, int y);

  //DIreccionamiento
extern void funcionDireccionamiento (nodoEstructura *nodo, int i);


/*Estructura para leer el archivo de topologia.txt
typedef struct topologiatxt{
  char *origen;
  char *destino;
  char *auxiliar;
  int costo;
  struct topologiatxt *siguiente;
}DATOS;
*/
