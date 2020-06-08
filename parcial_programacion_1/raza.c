#include "raza.h"
#include <string.h>

#define CARGADO 1

#define SIAMES 0
#define YAMA 1
#define ANGORA 2
#define PITBULL 3
#define IGUANA 4
#define LABRADOR 5
#define BULLDOG 6

void inicializar_raza_pais(eRaza* lista_raza,int size_raza,int* id_raza)
{
    int i;

    for(i=0;i<size_raza;i++)
    {
        lista_raza[i].id_raza = *id_raza;
        lista_raza[i].estado = CARGADO;
        (*id_raza)++;
    }

}

void harcodear_raza(eRaza* lista_raza,int size_raza,int* id_raza)
{
    int i;
    char raza[7][10] = {"SIAMES","ANGORA","PITBULL","IGUANA","LABRADOR","BULLDOG","YAMA"};
    char pais[7][10] = {"PERSA","HIMALAYA","EEUU","COLOMBIA","INGLATERRA","FRANCIA","ARGENTINA"};

    for(i=0;i<size_raza;i++)
    {
        lista_raza[i].id_raza = *id_raza;
        strcpy(lista_raza[i].nombre_raza,raza[i]);
        strcpy(lista_raza[i].pais, pais[i]);
        lista_raza[i].estado = CARGADO;
        (*id_raza)++;
    }

}
