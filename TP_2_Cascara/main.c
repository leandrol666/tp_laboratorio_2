#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"
#define MAX 20


int main()
{
    EPersona persona[MAX];
    char seguir = 's';
    int opcion = 0;

    inicializar(persona, MAX);

    while(seguir=='s')
    {
        opcion = menu();

        switch(opcion)
        {
            case 1:
                agregar(persona,MAX);
                break;
            case 2:
                borrar(persona,MAX);
                break;
            case 3:
                mostrar(persona,MAX);
                break;
            case 4:
                grafico(persona,MAX);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

