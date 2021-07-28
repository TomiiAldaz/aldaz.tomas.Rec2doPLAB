#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "bicicleta.h"
#include "Parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListCountry)
{
    //int cant;
    char confirma;
    int todoOk = 0;

    if(path != NULL && pArrayListCountry != NULL)
    {

        FILE* f = fopen(path, "r");

        if(f == NULL)
        {
            printf(" No se pudo abrir el archivo\n");
        }else
        {
            if(ll_len(pArrayListCountry) > 0)
            {
                printf("Cuidado se van a sobre escribir los empleados.\n\n Confirma? ");
                fflush(stdin);
                scanf("%c", &confirma);
            }

            if( ll_len(pArrayListCountry) == 0 || confirma == 's')
            {
                ll_clear(pArrayListCountry);
                if(parser_CountryFromText(f, pArrayListCountry))
                {
                    todoOk = 1;
                }
            }

        }
        fclose(f);


    }

    return todoOk;
}
