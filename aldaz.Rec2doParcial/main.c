#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bicicleta.h"
#include "LinkedList.h"
#include "Controller.h"
#include "informes.h"

int menu();

int main()
{
    srand(time(NULL));

    char salir = 'n';
    int flag = 0;
    int flagE = 0;

    LinkedList* listaBicicletas = ll_newLinkedList();
    LinkedList* listaPorTipo;

    do{
        switch(menu())
        {
            case 1:
                if(controller_loadFromText("bicicletas.csv", listaBicicletas))
                {
                    printf("\nBicicletas cargados correctamente\n\n");
                }
                else
                {
                    printf("\nHubo un problema al cargar las Bicicletas\n\n");
                }
                flag = 1;
                break;
            case 2:
                if(flag)
                {
                    if(mostrarBicicletas(listaBicicletas))
                    {
                        printf("\nListado exitoso.\n");
                        flagE = 1;
                    }else
                    {
                        printf("Hubo un problema al realizar el listado.\n\n");
                    }
                }else
                {
                    printf("\nAntes de dar de listar las bicicletas, primero debes cargar los datos del archivo.\n\n");
                }
                break;
            case 3:
                if(flagE)
                {
                    LinkedList* listaBicicletasConTiempos = ll_map(listaBicicletas, asignarTiempos);

                    printf("\n  Listado de Bicicletas con Tiempos\n\n");
                    mostrarBicicletas(listaBicicletasConTiempos);
                }
                else
                {
                    printf("\nAntes de asignar los tiempos, primero debes dar de alta un empleado\n\n");
                }
                break;
            case 4:
                if(flagE)
                {
                    system("cls");

                    listaPorTipo = ll_filter(listaBicicletas, filterTipo);
                    if(mostrarBicicletas(listaPorTipo))
                    {
                        printf("\n\n Listado exitoso\n");
                    }else
                    {
                        printf("\n\n Hubo un problema al realizar el listado\n\n");
                    }
                }
                else
                {
                    printf("\nAntes de dar listar un empleado, primero debes dar de alta un empleado\n\n");
                }
                break;
            case 5:
                if(flagE)
                {
                    system("cls");
                    ll_sort(listaBicicletas, bicicletaCmpTipo, 1);
                    if(mostrarBicicletas(listaBicicletas))
                    {
                        printf("\n\n Listado exitoso\n");
                    }else
                    {
                        printf("\n\n Hubo un problema al realizar el listado\n\n");
                    }
                }
                else
                {
                    printf("\nAntes de dar listar un empleado, primero debes dar de alta un empleado\n\n");
                }
                break;
            case 6:
                if(flagE)
                {
                    system("cls");

                    if(1)
                    {
                        printf("\n\n Ordenado exitoso\n");
                    }else
                    {
                        printf("\n\n Hubo un problema al realizar el ordenado\n\n");
                    }
                }
                else
                {
                    printf("\nAntes de ordenar una lista de empleados, primero debes dar de alta un empleado\n\n");
                }
                break;
            case 7:
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
    }while(salir == 'n');

    return 0;
}

int menu(){

    int opcion;

    system("cls");
    printf("      Menu de Opciones\n\n");
    printf("   1. Cargar los datos del archivo\n");
    printf("   2. Imprimir lista.\n");
    printf("   3. Asignar tiempos.\n");
    printf("   4. Filtrado por tipo.\n");
    printf("   5. Mostrar posiciones.\n");
    printf("   6. Guardar posiciones.\n");
    printf("   7. Salir\n");
    printf("   Introduzca opcion (1-7): ");
    fflush(stdin);

    scanf("%d", &opcion);


    return opcion;
}
