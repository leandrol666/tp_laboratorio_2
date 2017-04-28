#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int menu()
{
    int opcion=0;

    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");
    scanf("%d",&opcion);

    return opcion;
}

void inicializar(EPersona lista[], int max)
{
    int contador;

    for(contador=0;contador<max;contador++)
        {
            lista[contador].estado=0;
        }

    return;
}

int obtenerEspacioLibre(EPersona lista[], int max)
{
    int contador;

    for(contador=0;contador<max;contador++)
        {
            if(lista[contador].estado==0)
                {
                    return contador;
                }
        }
    return -1;
}

int buscarPorDni(EPersona lista[], int dni, int max)
{
    int contador;

    for(contador=0;contador<max;contador++)
    {
        if(lista[contador].dni==dni && lista[contador].estado == 1)
        {
            return contador;
        }
    }
    return -1;
}


void agregar(EPersona lista[], int max)
{
    int contador, auxDni;

    int aux;
    aux = obtenerEspacioLibre(lista, max);

    if(aux == -1)
        {
            printf("No hay espacio disponible! \n");
            return;
        }
    else
        {
            printf("Ingrese nombre: ");
            //Se utiliza para evitar que el scanf envie un \n al buffer
            while(getchar() != '\n');
            fgets(lista[aux].nombre,50,stdin);
            //se utiliza para agregarle un \0 al final del string y eliminar el \n
            size_t ln = strlen(lista[aux].nombre) - 1;
            if (*lista[aux].nombre && lista[aux].nombre[ln] == '\n')
            {
                lista[aux].nombre[ln] = '\0';
            }
            printf("Ingrese edad: ");
            scanf("%d",&lista[aux].edad);
            printf("Ingrese dni: ");
            scanf("%d",&auxDni);

            for(contador=0;contador<max;contador++)
                {
                    if (auxDni==lista[contador].dni  && lista[contador].estado == 1)
                        {
                            printf("El DNI ya fue ingresado \n");
                            return;
                        }
                }
            lista[aux].dni = auxDni;
            lista[aux].estado=1;

            printf("Datos ingresados con exito! \n");
        }
    return;
}

void mostrar(EPersona lista[], int max)
{
    int contador,contador2;
    EPersona aux;

    for(contador=0;contador<max-1;contador++)
        {
            for(contador2=contador+1;contador2<max;contador2++)
                {
                    if(strcmp(lista[contador].nombre,lista[contador2].nombre)>0)
                        {
                            aux=lista[contador];
                            lista[contador]=lista[contador2];
                            lista[contador2]=aux;
                        }
                }
        }
    printf("Nombre\t\tEdad\t\tDNI\t\t\n\n");
    for(contador=0;contador<max;contador++)
        {
            if(lista[contador].estado==1)
                {
                    printf("%s\t\t%d\t\t%d\t\t\n",lista[contador].nombre,lista[contador].edad,lista[contador].dni);
                }
        }
    return;
}

void borrar(EPersona lista[], int max)
{
    int dni, aux;
    char respuesta;

    printf("Ingrese DNI a eliminar: \n");
    scanf("%d",&dni);
    aux = buscarPorDni(lista, dni, max);
    if(aux==-1)
    {
        printf("El DNI ingresado no se encuentra en la base. \n");
        return;
    }
    else
    {
        printf("%s\t%d\t%d\n", lista[aux].nombre, lista[aux].edad, lista[aux].dni);
        printf("Esta seguro de eliminar el usuario? s/n: \n");
        while(getchar() != '\n');
        respuesta = getchar();
        if(respuesta=='s')
        {
            if(lista[aux].estado==1)
            {
                lista[aux].estado=0;
                printf("El usuario fue eliminado. \n");
                return;
            }
        }
        else
        {
            printf("Accion cancelada!\n");
        }
    }
    return;
}

void grafico(EPersona lista[],int max)
{
    int contador;

    int menor18=0, entre19y35=0, mayor35=0, flag=0, mayor;

    for(contador=0;contador<max;contador++)
    {
        if(lista[contador].estado==1)
        {
            if (lista[contador].edad<=18)
            {
                menor18++;
            }
            else
            {
                if(lista[contador].edad>=19 && lista[contador].edad<=35)
                {
                    entre19y35++;
                }
                else
                {
                    mayor35++;
                }
            }
        }
    }

    if(menor18 >= entre19y35 && menor18 >= mayor35)
    {
        mayor = menor18;
    }
    else
    {
        if(entre19y35 >= menor18 && entre19y35 >= mayor35)
        {
            mayor = entre19y35;
        }
        else
        {
            mayor = mayor35;
        }
    }

    for(contador=mayor; contador>0; contador--)
        {
            printf("%02d|",contador);

            if(contador<= menor18)
                {
                    printf("*");
                }
            if(contador<= entre19y35)
                {
                    flag=1;
                    printf("\t*");
                }
            if(contador<= mayor35)
                {
                    if(flag==0)
                        {
                            printf("\t\t*");
                        }
                    if(flag==1)
                        {
                            printf("\t*");
                        }
                }
            printf("\n");
        }

    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35 \n");

    return;;
}
