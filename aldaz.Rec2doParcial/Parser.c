#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"
#include "LinkedList.h"
#include "bicicleta.h"


int parser_CountryFromText(FILE* pFile , LinkedList* pArrayListCountry)
{
    int todoOk = 0;
    int flag;
    int cant;
    //int tam;
    eBicicleta* auxBici = NULL;

    //tam = ll_len(pArrayListCountry);
    char buffer[4][100];

    if(pFile != NULL && pArrayListCountry != NULL)
    {
        //lectura fantasma
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant == 4)
            {
                //printf("\nCant: %d\n\n", cant);
                auxBici = newBicicletaStr(buffer[0], buffer[1], buffer[2], buffer[3]);


                if(auxBici != NULL)
                {
                    if(ll_add(pArrayListCountry, auxBici) == 0)
                    {
                        auxBici =  NULL;
                        flag = 0;
                        todoOk = 1;
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    flag = 2;
                    break;
                }
            }
            else
            {
                flag = 3;
                break;
            }
        }

        if(flag == 0)
        {
            printf("\n");
        }else if(flag == 1)
        {
            printf("No se pudo conseguir lugar\n");
        }else if(flag == 2)
        {
            printf("No se pudo crear la Bicicleta\n");
        }else if(flag == 3)
        {
            printf("No se pudo leer la Bicicletas\n");
        }


    }

    return todoOk;
}
