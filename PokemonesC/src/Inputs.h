#ifndef FUNCIONUTN_H_
#define FUNCIONUTN_H_

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getAlphaNumeric(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int getString(char* cadena, int longitud);
int PedirEntero(int* pResultado, char* mensaje);

#endif /* FUNCIONUTN_H_ */

