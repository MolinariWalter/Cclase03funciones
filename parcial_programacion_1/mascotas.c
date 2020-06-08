#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "mascotas.h"
#include "Functions.h"

#define CARGADO 1
#define LIBRE 0

void inicializar_mascotas(emascotas* lista_mascotas,int size_mascotas)
{
    int i;

    for(i=0;i<size_mascotas;i++)
    {
       lista_mascotas[i].estado = LIBRE;

    }
}
void mostrar_mascota(emascotas mascota)
{
    printf("%4d %15s %15s %15d %10d %10.2f %20s\n",mascota.id,mascota.nombre, mascota.tipo, mascota.id_raza ,mascota.edad, mascota.peso, mascota.sexo);
}

int buscar_mascota_by_id(emascotas* lista_mascotas,int size_mascotas,int id)
{
    int index = -1;
    int i;

    for(i=0;i<size_mascotas;i++)
    {
        if(lista_mascotas[i].estado == CARGADO && lista_mascotas[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}


int set_nombre_mascota(emascotas* mascota)
{
    int resultado = 0;

    if ( UTN_getStringName(mascota->nombre,sizeof(mascota->nombre),"ingrese el nombre de la mascota :","error.\n",3) )
    {
        resultado = 1;
    }

    return resultado;
}

int set_tipo_mascota(emascotas* mascota)
{
    int resultado = 0;

    //char [3][10] = {"PERRO","GATO","RARO"};
    int tipo;

    if ( UTN_getNumberInt(&tipo,"1.PERRO\n2.GATO\n3.RARO\ningrese la opcion del tipo de mascota :","error.\n",1,3,3))
    {
      switch(tipo)
      {
        case 1:
            strcpy(mascota->tipo,"PERRO");
            resultado = 1;
        break;
        case 2:
            strcpy(mascota->tipo,"GATO");
            resultado = 1;
        break;
        case 3:
            strcpy(mascota->tipo,"RARO");
            resultado = 1;
        break;
      }

    }

    return resultado;
}


int set_edad_mascota(emascotas* mascota)
{
    int resultado = 0;

    if ( UTN_getNumberInt(&mascota->edad,"ingrese la edad de la mascota :","error.\n",1,100,3))
    {
        resultado = 1;
    }

    return resultado;
}

int set_peso_mascota(emascotas* mascota)
{
    int resultado = 0;

    if ( UTN_getNumberFloat(&mascota->peso,"ingrese el peso de la mascota :","error.\n",0.0,200.0,3))
    {
        resultado = 1;
    }

    return resultado;
}

int set_sexo_mascota(emascotas* mascota)
{
    int resultado = 0;
    int sexo;

    if ( UTN_getNumberInt(&sexo,"1.MACHO\n2.HEMBRA\ningrese la opcion del sexo de la mascota :","error.\n",1,2,3))
    {
        switch(sexo)
        {
            case 1:
                strcpy(mascota->sexo,"MACHO");
                resultado = 1;
            break;
            case 2:
                strcpy(mascota->sexo,"HEMBRA");
                resultado = 1;
            break;
        }
    }

    return resultado;
}





