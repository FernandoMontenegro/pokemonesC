#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pokemones.h"
#include "parser.h"
#include "Controller.h"
#include "Inputs.h"

int Montenegro_controller_loadFromText(char* path , LinkedList* pArrayPokemones)
{
	FILE* archivo;
	int retorno;

	retorno = -1;
	archivo = fopen(path, "r");

	if(archivo != NULL)
	{
		if(parser_PokemonesFromText(archivo, pArrayPokemones) == 0)
		{
			retorno = 0;
		}
		fclose(archivo);
	}

    return retorno;
}

int Montenegro_controller_editPokemon(LinkedList* pArrayPokemones)
{
	Pokemones* this;
	int retorno = -1;
	int index;
	int verificacion;

	if(pArrayPokemones != NULL)
	{
		Montenegro_controller_ListPokemones(pArrayPokemones);

		index = Pokemon_validarNumero(pArrayPokemones, "Ingrese un numero de pokemon de la lista para modificar: ");

		this = (Pokemones*) ll_get(pArrayPokemones, index);

		Pokemon_printOne(this);

		utn_getNumero(&verificacion, "¿Está seguro que desea modificar este Pokemon?\n1. Si\n2. No\n", "Opcion invalida...\n", 1, 2, 5);

		if(verificacion == 1)
		{
			if(Pokemon_newEdit(this) == 0)
			{
				retorno = 0;
			}

		}
		else
		{
			retorno = 1;
		}

	}

	return retorno;
}

int Montenegro_controller_ListPokemones(LinkedList* pArrayListPokemones)
{
	Pokemones* this;
	int size;
	int retorno;

	retorno = -1;

	if(pArrayListPokemones != NULL)
	{
		size = ll_len(pArrayListPokemones);

		if(size > 0)
		{
			for(int i=0; i<size; i++)
			{
				this = (Pokemones*) ll_get(pArrayListPokemones, i);
				Pokemon_printOne(this);
			}
			retorno = 0;
		}
	}

	return retorno;
}

int Montenegro_controller_saveAsText(char* path , LinkedList* pArrayPokemones)
{
	FILE* pFile;
	int retorno;

	retorno = -1;

	if(path != NULL && pArrayPokemones != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL && parser_PokemonesSaveText(pFile, pArrayPokemones) == 0)
		{
			retorno = 0;
		}
		fclose(pFile);
	}

	return retorno;
}
int Montenegro_controller_generarArchivoTipoFire(char* path , LinkedList* pArrayPokemones)
{
	int retorno;
	LinkedList* listaFiltrada;

	retorno = -1;

	if(path != NULL && pArrayPokemones != NULL)
	{
		listaFiltrada = ll_filter(pArrayPokemones, Pokemon_filtrarFire);

		if(listaFiltrada != NULL)
		{
			if(Montenegro_controller_saveAsText(path, listaFiltrada) == 0)
			{
				retorno = 0;
			}
		}
	}

    return retorno;
}

int Montenegro_controller_filtrarByTipoyTamanio(LinkedList* pArrayPokemones)
{
	int retorno = -1;
	LinkedList* listaFiltrada;

	if(pArrayPokemones != NULL)
	{
		listaFiltrada = ll_filter(pArrayPokemones, Pokemon_filtrarByTipo_Tamanio);
		if(listaFiltrada != NULL)
		{
			Montenegro_controller_ListPokemones(listaFiltrada);
			retorno = 0;
		}
	}

	return retorno;
}


















