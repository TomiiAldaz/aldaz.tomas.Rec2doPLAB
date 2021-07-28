#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include "bicicleta.h"





eBicicleta* newBicicleta()
{
    eBicicleta* nuevaBicicleta = (eBicicleta*) malloc(sizeof(eBicicleta));

    if(nuevaBicicleta != NULL)
    {
        nuevaBicicleta->id_bike = 0;
        strcpy(nuevaBicicleta->nombre, "");
        strcpy(nuevaBicicleta->tipo, "");
        nuevaBicicleta->tiempo = 0;


    }

    return nuevaBicicleta;
}

eBicicleta* newBicicletaStr(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr)
{
    eBicicleta* nuevaBicicleta = newBicicleta();

    if(nuevaBicicleta != NULL)
    {
        if(!( bicicletaSetId(nuevaBicicleta, atoi(idStr))
              && bicicletaSetNombre(nuevaBicicleta, nombreStr)
              && bicicletaSetTipo(nuevaBicicleta, tipoStr)
              && bicicletaSetTiempo(nuevaBicicleta, atoi(tiempoStr)) ))
        {
                free(nuevaBicicleta);
                nuevaBicicleta = NULL;


        }

    }

    return nuevaBicicleta;
}

void mostrarBicicleta(eBicicleta* b)
{
    if(b != NULL)
    {
        printf("%d    %-10s    %-10s     %d\n",b->id_bike, b->nombre, b->tipo, b->tiempo);
    }
}

int mostrarBicicletas(LinkedList* pLista)
{
    int todoOk = 0;
    int tam;
    eBicicleta* pElement = NULL;

    if(pLista != NULL)
    {
        tam = ll_len(pLista);
        printf(" ID     Nombre     Tipo   Tiempo\n\n");
        for(int i=0; i < tam; i++)
        {
            pElement = (eBicicleta*) ll_get(pLista, i);
            if(pElement != NULL)
            {
                mostrarBicicleta(pElement);
            }
        }
        todoOk = 1;
        printf("\n\n");
    }

    return todoOk;
}
int bicicletaSetId(eBicicleta* b, int id)
{
    int todoOk = 0;
    if(b != NULL && id > 0)
    {
        b->id_bike = id;
        todoOk = 1;

    }

    return todoOk;
}
int bicicletaSetNombre(eBicicleta* b, char* nombre)
{
    int todoOk = 0;
    if(b != NULL && nombre != NULL && strlen(nombre) < 128 && strlen(nombre) > 2)
    {
        strcpy(b->nombre, nombre);
        todoOk = 1;

    }

    return todoOk;
}
int bicicletaSetTipo(eBicicleta* b, char* tipo)
{
    int todoOk = 0;
    if(b != NULL && tipo != NULL && strlen(tipo) < 20 && strlen(tipo) > 2)
    {
        strcpy(b->tipo, tipo);
        todoOk = 1;

    }

    return todoOk;
}
int bicicletaSetTiempo(eBicicleta* b, int tiempo)
{
    int todoOk = 0;
    if(b != NULL && tiempo >= 0)
    {
        b->tiempo = tiempo;
        todoOk = 1;

    }

    return todoOk;
}

