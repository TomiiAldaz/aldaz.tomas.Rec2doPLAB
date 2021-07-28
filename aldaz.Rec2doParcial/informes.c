#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "informes.h"
#include "bicicleta.h"

int asignarTiempos(void* pElement)
{
    int retorno = 0;
    eBicicleta* b;
    int maxTime;
    int minTime;


    if(pElement != NULL )
    {
        maxTime = 120;
        minTime = 50;



        b = (eBicicleta*) pElement;

        if(b != NULL)
        {
            b->tiempo = rand() % (maxTime - minTime +1) + minTime;

            retorno = 1;
        }
    }

    return retorno;
}


int filterTipo(void* pElement)
{
    int retorno = 0;
    eBicicleta* bici;
    char salir = 'n';

    if(pElement != NULL )
    {
        bici = (eBicicleta*) pElement;

        printf("Ingrese el tipo de la bicicleta que desea filtrar\n\n");

        do
        {
            switch(menuTipo())
            {
            case 1:
                if(!strcmpi(bici->tipo, "BMX"))
                {
                    retorno = 1;
                }
                break;
            case 2:
                if(!strcmpi(bici->tipo, "PLAYERA"))
                {
                    retorno = 1;
                }
                break;
            case 3:
                if(!strcmpi(bici->tipo, "MTB"))
                {
                    retorno = 1;
                }
                break;
            case 4:
                if(!strcmpi(bici->tipo, "PASEO"))
                {
                    retorno = 1;
                }
                break;
            case 5:
                printf("\n   Confirma salida?: ");
                fflush(stdin);
                salir = getchar();
                break;
            default:
                printf("\n   Opcion Invalida!\n");
                fflush(stdin);
                printf("\n");
            }
            printf("\n");
            system("pause");
        }
        while(salir == 's');



    }

    return retorno;
}

int menuTipo(){

    int opcion;

    system("cls");
    printf("      Menu de Tipos\n\n");
    printf("   1. BMX\n");
    printf("   2. PLAYERA.\n");
    printf("   3. MTB.\n");
    printf("   4. PASEO.\n");
    printf("   5. Salir\n");
    printf("   Introduzca opcion (1-5): ");
    fflush(stdin);

    scanf("%d", &opcion);


    return opcion;
}


int bicicletaCmpTipo(void* a, void* b)
{
    int retorno = 0;

    eBicicleta* bici1;
    eBicicleta* bici2;

    if(a != NULL && b != NULL)
    {
        bici1 = (eBicicleta*) a;
        bici2 = (eBicicleta*) b;

        if(!(strcmp(bici1->tipo, bici2->tipo)))
        {
            if(bici1->tiempo > bici2->tiempo)
            {
                retorno = 1;
            }
            else  if(bici1->tiempo < bici2->tiempo)
            {
                retorno = -1;
            }
        }else
        {
            retorno = strcmp(bici1->tipo, bici2->tipo);
        }

    }

    return retorno;
}

