#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


/** \brief
 *
 * \param pElement void*
 * \return int
 *
 */
int asignarTiempos(void* pElement);

/** \brief Filtra las Bicicletas por Tipo
 *
 * \param pElement void*
 * \return int
 *
 */
int filterTipo(void* pElement);

/** \brief Muestra un Menu para seleccionar el tipo de la Bicicleta
 *
 * \return int
 *
 */
int menuTipo();

/** \brief Establece el criterio de ordenamiento de las bicicletas
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int bicicletaCmpTipo(void* a, void* b);
