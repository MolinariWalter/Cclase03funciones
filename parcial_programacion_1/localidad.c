
#include "localidad.h"

#include <string.h>


#define CARGADO 1

void inicializar_localidad(eLocalidad* lista_localidad,int size_localidad,int* id_localidad)
{
    int i;

    for(i=0;i<size_localidad;i++)
    {
        lista_localidad[i].id_localidad = *id_localidad;
        lista_localidad[i].estado = CARGADO;
        (*id_localidad)++;
    }

}
void harcodear_localidad(eLocalidad* lista_localidad,int size_localidad,int* id_localidad)
{
    int i;
    char provinciaAux[3][50] = {"Bs As","Rosario","La Pampa"};
    int codigoAux[3] = {1876,1642,1321};
    char descripcionAux[3][50] = {"quilmes","rosario","santa rosa"};


    for(i=0;i<size_localidad;i++)
    {
        strcpy(lista_localidad[i].provincia,provinciaAux[i]);

        lista_localidad[i].codigo_postal = codigoAux[i];

        strcpy(lista_localidad[i].descripcion,descripcionAux[i]);

        lista_localidad[i].estado = CARGADO;

        lista_localidad[i].id_localidad = *id_localidad;


        (*id_localidad)++;
    }
}
