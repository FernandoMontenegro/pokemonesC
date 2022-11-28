#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Carga los datos de los pokemones desde el archivo Data_Pokemones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayPokemones LinkedList*
 * \return int
 */
/// @brief Carga los datos de los pokemones desde el archivo Data_Pokemones.csv (modo texto).
///
/// @param path char*
/// @param pArrayPokemones LinkedList*
/// @return 0 si salio bien.
int Montenegro_controller_loadFromText(char* path , LinkedList* pArrayPokemones);
/// @brief modifica los datos de un pokemon
///
/// @param pArrayPokemones, array de pokemones
/// @return retorna 0 si salio bien
int Montenegro_controller_editPokemon(LinkedList* pArrayPokemones);
/// @brief recorre el array de pokemones y con el ll_get va mostrando cada pokemon
///
/// @param pArrayPokemones, array de pokemones
/// @return retorna 0 si salio bien.
int Montenegro_controller_ListPokemones(LinkedList* pArrayPokemones);
/// @brief guarda el archivo de los pokemones filtrados por FIRE
///
/// @param path, le paso el path del archivo
/// @param pArrayPokemones, array de pokemones
/// @return retorna 0 si salio bien.
int Montenegro_controller_saveAsText(char* path , LinkedList* pArrayPokemones);
/// @brief filtra los pokemones por FIRE con ll_filter
///
/// @param path, path del archivo
/// @param pArrayPokemones, array de pokemones
/// @return retorna 0 si salio bien
int Montenegro_controller_generarArchivoTipoFire(char* path , LinkedList* pArrayPokemones);
/// @brief filtra y crea otra lista con los pokemones por XL Y POISON con ll_filter
///
/// @param pArrayPokemones, array de pokemones
/// @return retorna 0 si salio bien.
int Montenegro_controller_filtrarByTipoyTamanio(LinkedList* pArrayPokemones);



#endif
