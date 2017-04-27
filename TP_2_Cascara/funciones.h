#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    int edad;
    int dni;
    int estado;

}EPersona;

/**
 * Muestra el menu principal
 * @return la opcion escojida
 */
int menu();

/**
 * inicia el estado de la persona
 * @param lista array de las personas a inicializar
 * @param se le indica el maximo del array
 */
void inicializar(EPersona lista[], int);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int);

/**
 * Agrega un usuario a la lista de personas
 * @param lista array de las personas 
 * @param se le indica el maximo del array
 */
void agregar(EPersona lista[], int);

/**
 * muestra una lista de personas ordenadas por nombre
 * @param lista es el array de personas
 * @param se le indica el maximo del array
 */
void mostrar(EPersona lista[], int);

/**
 * elimina un usuario de la lista de personas
 * @param lista array de las personas 
 * @param se le indica el maximo del array
 */
void borrar(EPersona lista[], int);

/**
 * muestra un grafico dividiendo a las personas en un rango de edades                                                                                  *
 *
 * @param lista array a utilizar en el grafico
 * @param se le indica el maximo del array
 */
void grafico(EPersona lista[],int);

#endif // FUNCIONES_H_INCLUDED
