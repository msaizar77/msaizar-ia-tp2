#include <stdio.h>

/*

Carrera: Licenciatura en Informática
Alumno: SAIZAR, Mauricio
Legajo: VINF09738


Inteligencia Artificial
=======================

Trabajo Práctico Nº 2
---------------------

*/



/* defino las posiciones CORRECTAS del bloque */
struct puntoTD {
    int x,y,z;
    } posicionesBlock[4], posicionActual;

void inicializoPuntosBlock(){
    /* Si fueran mas puntos podria inicializarlos con valores aleatorios normalizados en un rango p.ej. 1..10 */
    posicionesBlock[0].x=0;    posicionesBlock[0].y=3;    posicionesBlock[0].z=2;
    posicionesBlock[1].x=2;    posicionesBlock[1].y=4;    posicionesBlock[1].z=1;
    posicionesBlock[2].x=4;    posicionesBlock[2].y=1;    posicionesBlock[2].z=3;
    posicionesBlock[3].x=1;    posicionesBlock[3].y=5;    posicionesBlock[3].z=6;
}

int distanciaEPuntos(struct puntoTD p1, struct puntoTD p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
}

void realizarBusquedaExaustiva(struct puntoTD destino){
    printf("Comienzo en la posicion (%d,%d,%d)\n",posicionActual.x,posicionActual.y,posicionActual.z);

    int iteraciones = 0;
    for(int x=0; x<10 ; x++){
        for(int y=0; y<10 ; y++){
            for(int z=0; z<10 ; z++){
                iteraciones++;
                if (destino.x==x && destino.y==y && destino.z==z){
                    posicionActual.x=x;     posicionActual.y=y;     posicionActual.z=z;
                    printf("Cantidad de iteraciones: %d\n",iteraciones);
                    return;
                }
            }
        }
    }
}

void realizarBusquedaHeuristica(struct puntoTD destino){
    printf("Comienzo en la posicion (%d,%d,%d)\n\n",posicionActual.x,posicionActual.y,posicionActual.z);

    int iteraciones = 0;

    int distancias[100];
    struct puntoTD colaPuntos[100];
    struct puntoTD puntosYaVisitados[100];

    int cantPuntosEncolados=0;
    int cantPuntosVisitados=0;

    cantPuntosEncolados++;
    colaPuntos[0]=posicionActual;
    distancias[0]=distanciaEPuntos(posicionActual,destino);

    while (cantPuntosEncolados>0){
        // Obtener la proxima posicion cuya distancia sea minima desde "colaPuntos[]"
        // Controlo que no este dentro de las posiciones ya visitadas
        // La asigno como posicion actual
        // Ahora si, agrego la posicion a la lista de posiciones ya visitadas

        // Busco todos los puntos que limitan con el punto actual (a distancia 1, considerando x,y, ó z) dentro de los limites
        // Los encolo, para que sean considerados en las siguientes iteraciones del bucle
    }

    posicionActual.x=destino.x;     posicionActual.y=destino.y;     posicionActual.z=destino.z;
}

int main(int argc, char const *argv[])
{
    inicializoPuntosBlock();

    /* Recorro todas las posiciones del recorrido del Block sobre la cinta */
    /* Realizo una Búsqueda Exahustiva para encontrar los movimientos 
        DESDE posicionActual HASTA posicionesBlock[i] */ 
    printf("*** *************************** ***\n");
    printf("*** Realizar Busqueda Exaustiva ***\n");
    printf("*** *************************** ***\n");
    posicionActual.x = 0;   posicionActual.y=0;     posicionActual.z=0;

    for (int i=0;i<4;i++){
        realizarBusquedaExaustiva(posicionesBlock[i]);
        printf("Finalizo  en la posicion (%d,%d,%d)\n\n",posicionActual.x,posicionActual.y,posicionActual.z);
    }

    /* ******************************************************************* */
    /* Recorro todas las posiciones del recorrido del Block sobre la cinta */
    /* Realizo una Búsqueda Heuristica  para encontrar los movimientos 
        DESDE posicionActual HASTA posicionesBlock[i] */ 
    printf("*** **************************** ***\n");
    printf("*** Realizar Busqueda Heuristica ***\n");
    printf("*** **************************** ***\n");
    posicionActual.x = 0;   posicionActual.y=0;     posicionActual.z=0;

    for (int i=0;i<4;i++){
        realizarBusquedaHeuristica(posicionesBlock[i]);
        printf("Finalizo  en la posicion (%d,%d,%d)\n\n",posicionActual.x,posicionActual.y,posicionActual.z);
    }

    return 0;
}
