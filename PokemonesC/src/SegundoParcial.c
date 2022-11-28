/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : Montenegro Fernando Thomas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pokemones.h"
#include "parser.h"
#include "Controller.h"
#include "Inputs.h"

int main(void)
{
	setbuf(stdout,NULL);

	int option;
	int contadorCsv;
	int verificacion;
	LinkedList* listaPokemones = ll_newLinkedList();

	contadorCsv = 0;


	do
	{
		utn_getNumero(&option, "MENU DE OPCIONES POKEMON GO\n\n"
							   "1. Cargar archivo pokemones.\n"
							   "2. Modificar valor de ataque.\n"
							   "3. Imprimir Pokemones.\n"
							   "4. Filtrar tipo Fuego.\n"
							   "5. Filtrar Extra Grandes de tipo Veneno.\n"
							   "6. Salir de la aplicacion.\n"
							   "\nSeleccione una opcion: ", "\nEsa no es una opcion valida...\n", 1, 6, 5);

		switch(option)
		{
		case 1:
        	if(contadorCsv == 0)
        	{
        		if(Montenegro_controller_loadFromText("Data_Pokemones.csv", listaPokemones) == 0)
        		{
        			printf("\nSe ha cargado la lista correctamente\n\n");
        			contadorCsv = 1;
        		}
        		else
        		{
        			printf("\nHa ocurrido un error...\n\n");
        		}
        	}
			else
			{
				printf("\nYa se han cargado los datos...\n\n");
			}
			break;

		case 2:
        	if(ll_isEmpty(listaPokemones) == 0)
        	{
        		verificacion = Montenegro_controller_editPokemon(listaPokemones);
        		if(verificacion == 0)
				{
					printf("Pokemon modificado con exito...\n\n");
				}
				else
				{
					if(verificacion == 1)
					{
						printf("Modificacion de Pokemon cancelada...\n\n");
					}
					else
					{
						printf("Hubo un problema y no se puede modificar el Pokemon...\n\n");
					}
				}
        	}
        	else
        	{
        		printf("\nNo hay Pokemones cargados...\n\n");
        	}
			break;

		case 3:
        	if(ll_isEmpty(listaPokemones) == 0)
        	{
        		if(Montenegro_controller_ListPokemones(listaPokemones) == 0)
        		{
        			printf("\nLista de pokemones mostrada con exito...\n\n");
        		}
        	}
        	else
        	{
        		printf("\nNo hay pokemones cargados...\n\n");
        	}
			break;

		case 4:
			if(ll_isEmpty(listaPokemones) == 0)
			{
				if(Montenegro_controller_generarArchivoTipoFire("Data_PokemonesFire.csv", listaPokemones) == 0)
				{
					printf("\nArchivo de filtro tipo Fire generado con exito...\n\n");
				}
				else
				{
					printf("\nHubo un problema al filtrar la lista tipo Fire.\n\n");
				}
			}
			else
			{
				printf("\nNo hay pokemones cargados...\n\n");
			}
			break;
		case 5:
			if(ll_isEmpty(listaPokemones) == 0)
			{
				if(Montenegro_controller_filtrarByTipoyTamanio(listaPokemones) == 0)
				{
					printf("\nListado filtrado por XL y Poison correctamente...\n\n");
				}
				else
				{
					printf("\nHubo un problema al filtrar la lista por tamaño XL y tipo Poison.\n\n");
				}
			}
			else
			{
				printf("\nNo hay pokemones cargados...\n\n");
			}

			break;

		case 6:
			printf("\n\nCerrando aplicacion... exitos entrenador Pokemon.\n");
			break;
		}

	}while(option != 6);

	return EXIT_SUCCESS;
}
