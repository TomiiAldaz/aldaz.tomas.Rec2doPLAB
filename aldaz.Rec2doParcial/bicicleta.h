#include "LinkedList.h"

#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

typedef struct{
    int id_bike;
    char nombre[20];
    char tipo[20];
    int tiempo;
}eBicicleta;


#endif // PAISES_H_INCLUDED


/** \brief Crea una nueva Bicicleta con todos sus campos vacios o en 0
 *
 * \return eBicicleta*
 *
 */
eBicicleta* newBicicleta();
eBicicleta* newBicicletaStr(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr);

/** \brief Muestra una Bicicleta
 *
 * \param b eBicicleta*
 * \return void
 *
 */
void mostrarBicicleta(eBicicleta* b);

/** \brief Muestra un lista enlazada de Bicicletas
 *
 * \param pLista LinkedList*
 * \return int
 *
 */
int mostrarBicicletas(LinkedList* pLista);

/** \brief Establece el id de una bicicleta en una estructura Bicicleta
 *
 * \param b eBicicleta*
 * \param id int
 * \return int
 *
 */
int bicicletaSetId(eBicicleta* b,int id);

/** \brief Establece el nombre del conductor de una bicicleta en una estructura Bicicleta
 *
 * \param b eBicicleta*
 * \param nombre char*
 * \return int
 *
 */
int bicicletaSetNombre(eBicicleta* b, char* nombre);

/** \brief Establece el tipo de bicicleta en una estructura Bicicleta
 *
 * \param b eBicicleta*
 * \param tipo char*
 * \return int
 *
 */
int bicicletaSetTipo(eBicicleta* b, char* tipo);

/** \brief Establece el tiempo de una bicicleta en una estructura Bicicleta
 *
 * \param b eBicicleta*
 * \param tiempo int
 * \return int
 *
 */
int bicicletaSetTiempo(eBicicleta* b, int tiempo);

/** \brief Asigna aleatoriamente valores
 *
 * \param pElement void*
 * \return int
 *
 */
int asignarTiempos(void* pElement);
