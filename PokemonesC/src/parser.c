#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pokemones.h"
#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PokemonesFromText(FILE* pFile , LinkedList* pArrayPokemones)
{
	Pokemones* this;
	int leido;
	char numeroAux[50];
	char nombreAux[50];
	char tipoAux[50];
	char tamanioAux[50];
	char ataqueCargadoAux[50];
	char valorAtaqueAux[50];
	char esVariocolorAux[50];
	int retorno;

	retorno = -1;

	if(pFile != NULL && pArrayPokemones != NULL)
	{
		while(!feof(pFile))
		{
			leido = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
					numeroAux,
					nombreAux,
					tipoAux,
					tamanioAux,
					ataqueCargadoAux,
					valorAtaqueAux,
					esVariocolorAux);

			if(leido == 7)
			{
				this = Pokemon_newParametros(numeroAux, nombreAux, tipoAux, tamanioAux, ataqueCargadoAux, valorAtaqueAux, esVariocolorAux);
				if (this != NULL)
				{
					ll_add(pArrayPokemones, this);
					retorno = 0;
				}
				else
				{
					printf("\nHa ocurrido un error...\n\n");
					Pokemon_delete(this);
				}
			}
		}
	}
	else
	{
		printf("\nEl archivo no existe.\n\n");
	}


    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo .csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PokemonesSaveText(FILE* pFile , LinkedList* pArrayPokemones)
{
	Pokemones* this;
	int len;
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;
	int retorno;

	retorno = -1;

	len = ll_len(pArrayPokemones);

	if(len > 0 && pFile != NULL && pArrayPokemones != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			this = (Pokemones*) ll_get(pArrayPokemones, i);

			if(this != NULL)
			{
				Pokemon_getNumero(this, &numero);
				Pokemon_getNombre(this, nombre);
				Pokemon_getTipo(this, tipo);
				Pokemon_getTamanio(this, tamanio);
				Pokemon_getAtaqueCargado(this, ataqueCargado);
				Pokemon_getValorAtaque(this, &valorAtaque);
				Pokemon_getEsVariocolor(this, &esVariocolor);


				fprintf(pFile, "%d,%s,%s,%s,%s,%d,%d\n", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVariocolor);

				retorno = 0;
			}
		}
	}

	return retorno;

}

