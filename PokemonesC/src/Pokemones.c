#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pokemones.h"
#include "parser.h"
#include "Controller.h"
#include "Inputs.h"
#include <string.h>
#include <ctype.h>

Pokemones* new_Pokemon()
{
	Pokemones* this;

	this = (Pokemones*) malloc(sizeof(Pokemones));

	return this;
}

Pokemones* Pokemon_newParametros(char* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr, char* ataqueCargadoStr,char* valorAtaqueStr, char* esVariocolorStr)
{
	Pokemones* this;
	int numero;
	int valorAtaque;
	int esVariocolor;

	this = new_Pokemon();

	numero = atoi(numeroStr);
	valorAtaque = atoi(valorAtaqueStr);
	esVariocolor = atoi(esVariocolorStr);

	if(this != NULL)
	{
		if(Pokemon_setNumero(this, numero) == -1 ||
		   Pokemon_setNombre(this, nombreStr) == -1 ||
		   Pokemon_setTipo(this, tipoStr) == -1 ||
		   Pokemon_setTamanio(this, tamanioStr) == -1 ||
		   Pokemon_setAtaqueCargado(this, ataqueCargadoStr) == -1 ||
		   Pokemon_setValorAtaque(this, valorAtaque) == -1 ||
		   Pokemon_setEsVariocolor(this, esVariocolor) == -1)
		{
			Pokemon_delete(this);
			this = NULL;
		}
	}

	return this;
}

void Pokemon_delete(Pokemones* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Pokemon_setNumero(Pokemones* this,int numero)
{
	int retorno;

	retorno = -1;

	if (this != NULL && numero > 0)
	{
		this->numero = numero;
		retorno = 0;
	}

	return retorno;
}
int Pokemon_getNumero(Pokemones* this,int* numero)
{
	int retorno;

	retorno = -1;

	if (this != NULL && numero != NULL)
	{
		*numero = this->numero;
		retorno = 0;
	}

	return retorno;
}

int Pokemon_setNombre(Pokemones* this,char* nombre)
{
	int retorno;

	retorno = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
int Pokemon_getNombre(Pokemones* this,char* nombre)
{
	int retorno;

	retorno = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int Pokemon_setTipo(Pokemones* this,char* tipo)
{
	int retorno;

	retorno = -1;

	if (this != NULL && tipo != NULL)
	{
		strcpy(this->tipo, tipo);
		retorno = 0;
	}

	return retorno;
}
int Pokemon_getTipo(Pokemones* this,char* tipo)
{
	int retorno;

	retorno = -1;

	if (this != NULL && tipo != NULL)
	{
		strcpy(tipo, this->tipo);
		retorno = 0;
	}

	return retorno;
}

int Pokemon_setTamanio(Pokemones* this,char* tamanio)
{
	int retorno;

	retorno = -1;

	if (this != NULL && tamanio != NULL)
	{
		strcpy(this->tamanio, tamanio);
		retorno = 0;
	}

	return retorno;
}
int Pokemon_getTamanio(Pokemones* this,char* tamanio)
{
	int retorno;

	retorno = -1;

	if (this != NULL && tamanio != NULL)
	{
		strcpy(tamanio, this->tamanio);
		retorno = 0;
	}

	return retorno;
}

int Pokemon_setAtaqueCargado(Pokemones* this,char* ataqueCargado)
{
	int retorno;

	retorno = -1;

	if (this != NULL && ataqueCargado != NULL)
	{
		strcpy(this->ataqueCargado, ataqueCargado);
		retorno = 0;
	}

	return retorno;
}

int Pokemon_getAtaqueCargado(Pokemones* this,char* ataqueCargado)
{
	int retorno;

	retorno = -1;

	if (this != NULL && ataqueCargado != NULL)
	{
		strcpy(ataqueCargado, this->ataqueCargado);
		retorno = 0;
	}

	return retorno;
}

int Pokemon_setValorAtaque(Pokemones* this,int valorAtaque)
{
	int retorno;

	retorno = -1;

	if (this != NULL && valorAtaque > 0)
	{
		this->valorAtaque = valorAtaque;
		retorno = 0;
	}

	return retorno;
}

int Pokemon_getValorAtaque(Pokemones* this,int* valorAtaque)
{
	int retorno;

	retorno = -1;

	if (this != NULL && valorAtaque != NULL)
	{
		*valorAtaque = this->valorAtaque;
		retorno = 0;
	}

	return retorno;
}

int Pokemon_setEsVariocolor(Pokemones* this,int esVariocolor)
{
	int retorno;

	retorno = -1;

	if (this != NULL)
	{
		this->esVariocolor = esVariocolor;
		retorno = 0;
	}

	return retorno;
}

int Pokemon_getEsVariocolor(Pokemones* this,int* esVariocolor)
{
	int retorno;

	retorno = -1;

	if (this != NULL && esVariocolor != NULL)
	{
		*esVariocolor = this->esVariocolor;
		retorno = 0;
	}

	return retorno;
}

void Pokemon_printOne(Pokemones* this)
{
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;

	Pokemon_getNumero(this, &numero);
	Pokemon_getNombre(this, nombre);
	Pokemon_getTipo(this, tipo);
	Pokemon_getTamanio(this, tamanio);
	Pokemon_getAtaqueCargado(this, ataqueCargado);
	Pokemon_getValorAtaque(this, &valorAtaque);
	Pokemon_getEsVariocolor(this, &esVariocolor);

	printf("|%-10d | %-16s | %-18s | %-15s | %-15s | %-15d | %-10d |\n", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVariocolor);

}
int Pokemon_validarNumero(LinkedList* listaPokemones, char* editOrRemove)
{
	int idEdit;
	int index;

	if(listaPokemones != NULL && editOrRemove != NULL)
	{
		PedirEntero(&idEdit, editOrRemove);
		index = Pokemon_findNumero(listaPokemones, idEdit);

		while(index == -1)
		{
			printf("Ese Pokemon no existe.\n");
			PedirEntero(&idEdit, editOrRemove);
			index = Pokemon_findNumero(listaPokemones, idEdit);
		}
	}

	return index;
}

int Pokemon_findNumero(LinkedList* listaPokemones, int editPokemon)
{
	Pokemones* this;
	int index = -1;
	int len;
	int numeroAux;

	if(listaPokemones != NULL)
	{
		len = ll_len(listaPokemones);

		if(len > 0)
		{
			for(int i=0; i<len; i++)
			{
				this = (Pokemones*) ll_get(listaPokemones, i);
				Pokemon_getNumero(this, &numeroAux);
				if(numeroAux == editPokemon)
				{
					index = i;
					break;
				}
			}
		}
	}

	return index;
}
int Pokemon_newEdit(Pokemones* this)
{
	int retorno = -1;
	int valorAtaque;

	printf("\n||| MODIFICACION DE POKEMON |||\n");

	utn_getNumero(&valorAtaque, "\nIngrese el nuevo Valor de Ataque del Pokemon: ", "\nError. no es un Valor de Ataque valido [MAX 10.000]...\n", 0, 10000, 5);

	if(Pokemon_setValorAtaque(this, valorAtaque) == 0)
	{
		printf("\nValor de ataque agregado correctamente...\n\n");
		retorno = 0;
	}

	return retorno;
}

int Pokemon_filtrarFire(void* element)
{
	Pokemones* this = element;
    int retorno = -1;
    char tipoAux[50];

    if(this != NULL)
    {
		Pokemon_getTipo(this, tipoAux);
		if(strcmp(tipoAux,"Fire") == 0)
		{
			retorno = 1;
		}
    }
    return retorno;
}

int Pokemon_filtrarByTipo_Tamanio(void* element)
{
	Pokemones* this = element;
    int retorno = -1;
    char tipoAux[50];
    char tamanioAux[50];

    if(this != NULL)
    {
		Pokemon_getTamanio(this, tamanioAux);
		if(strcmp(tamanioAux,"XL") == 0)
		{
			Pokemon_getTipo(this, tipoAux);
			if(strcmp(tipoAux,"Poison") == 0)
			{
				retorno = 1;
			}
		}
    }

    return retorno;
}

