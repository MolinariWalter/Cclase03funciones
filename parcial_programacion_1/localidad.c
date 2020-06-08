#include <string.h>


#define CARGADO 1

void inicializar_localidad(eLocalidad* lista_localidad,int size_localidad,int* id_localidad)
{
    int i;

    for(i=0;i<lista_localidad;i++)
    {
        lista_localidad[i].id_localidad = *id_localidad;
        lista_localidad[i].estado = CARGADO;
        (*id_raza)++;
    }

}
void harcodear_localidad(eLocalidad* lista_localidad,int size_localidad,int* id_localidad)
{
    int i;
    char provinciaAux[3][50] = {"Bs As","Rosario","La Pampa"};
    char descripcionAux[3][50] = {"","",""};

    for(i=0;i<size_localidad;i++)
    {
        strcpy(lista_localidad[i].provincia,provinciaAux[i]);

        lista_localidad[i].codigo_postal = ;

        strcpy(lista_localidad[i].descripcion );

        lista_localidad[i].id_localidad = id_localidad;
        (*id_raza)++;
    }
}
