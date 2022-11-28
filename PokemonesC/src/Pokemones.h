#ifndef POKEMONES_H_
#define POKEMONES_H_

typedef struct
{
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;

}Pokemones;

Pokemones* new_Pokemon();
Pokemones* Pokemon_newParametros(char* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr, char* ataqueCargadoStr,char* valorAtaqueStr, char* esVariocolorStr);
void Pokemon_delete(Pokemones* this);

int Pokemon_setNumero(Pokemones* this,int numero);
int Pokemon_getNumero(Pokemones* this,int* numero);

int Pokemon_setNombre(Pokemones* this,char* nombre);
int Pokemon_getNombre(Pokemones* this,char* nombre);

int Pokemon_setTipo(Pokemones* this,char* tipo);
int Pokemon_getTipo(Pokemones* this,char* tipo);

int Pokemon_setTamanio(Pokemones* this,char* tamanio);
int Pokemon_getTamanio(Pokemones* this,char* tamanio);

int Pokemon_setAtaqueCargado(Pokemones* this,char* ataqueCargado);
int Pokemon_getAtaqueCargado(Pokemones* this,char* ataqueCargado);

int Pokemon_setValorAtaque(Pokemones* this,int valorAtaque);
int Pokemon_getValorAtaque(Pokemones* this,int* valorAtaque);

int Pokemon_setEsVariocolor(Pokemones* this,int esVariocolor);
int Pokemon_getEsVariocolor(Pokemones* this,int* esVariocolor);

int Pokemon_validarNumero(LinkedList* listaPokemones, char* editOrRemove);
int Pokemon_findNumero(LinkedList* listaPokemones, int editPokemon);

void Pokemon_printOne(Pokemones* this);
int Pokemon_newEdit(Pokemones* this);

int Pokemon_filtrarFire(void* element);
int Pokemon_filtrarByTipo_Tamanio(void* element);

#endif
