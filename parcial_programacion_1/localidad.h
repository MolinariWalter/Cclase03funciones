#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct
{
    char provincia[50];
    int codigo_postal;
    char descripcion[50];
    int id_localidad;
    int estado;

}eLocalidad;

void inicializar_localidad(eLocalidad* lista_localidad,int size_localidad,int* id_localidad);
void harcodear_localidad(eLocalidad* lista_localidad,int size_localidad,int* id_localidad);

#endif // LOCALIDAD_H_INCLUDED
