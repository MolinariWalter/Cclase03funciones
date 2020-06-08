
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "clientes.h"
#include "mascotas.h"
#include "raza.h"

#define CARGADO 1

typedef struct
{
    int edad_total;
    int cont_macho;
    int cont_hembra;
    float cont_peso;
    int cont_perro;
    int cont_gato;
    int cont_raro;

}ecliente_mascota;

void inicializar_cliente_mascota(ecliente_mascota* clientemascota);

void harcodear_mascotas(emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes,int size_clientes,int* id_mascota,ecliente_mascota* clientemascota);

void mostrar_cliente_con_mascota(eclientes clientes,emascotas mascota);

void harcodear_clientes(eclientes* lista_clientes,int size_clientes,int* id_duenio);

void mostrarTodos_clientes_mascotas(eclientes* lista_clientes,int size_clientes,emascotas* lista_mascotas,int size_mascotas);

void mostrar_mascotas_con_cliente(emascotas mascotas,eclientes clientes);

void mostrarTodos_mascotas(emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes, int size_clientes);

int alta_mascota(ecliente_mascota* clientemascota,emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes, int size_clientes,eRaza* lista_raza,int size_raza,int id_duenio_inicial, int id_duenio,int* id_mascota);

int cargar_mascota(emascotas* mascotaAux,eRaza* lista_raza,int size_raza,int* id_mascota);

int baja_mascota(emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes,int size_clientes,int id_mascota);

int modificar_mascota(emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes,int size_clientes,int id_mascota,int id_duenio);

int baja_cliente(eclientes* lista_clientes,int size_clientes,emascotas* lista_mascotas,int size_mascotas,int id_duenio);

int ordenar_mascotas_por_tipo(emascotas* lista_mascotas,int size_mascotas);

void mostrar_mascotas_mas_3_anios(emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes,int size_clientes);

void mostrar_por_tipo(emascotas* lista_mascotas,int size_mascotas,eclientes*  lista_clientes,int size_clientes);

int ordenar_clientes_por_cantidad_mascota(emascotas* lista_mascotas,int size_mascotas,eclientes*  lista_clientes,int size_clientes);

int ordenar_clientes_por_cantidad_mascota_nombre(emascotas* lista_mascotas,int size_mascotas,eclientes*  lista_clientes,int size_clientes);

float promedio_edad_mascotas(ecliente_mascota* clientemascota,emascotas* lista_mascotas,int size_mascotas);

float promedio_edad_mascotas_por_tipo(ecliente_mascota* clientemascota,emascotas* lista_mascotas,int size_mascotas,int tipo);

void clientes_mascotas_macho(emascotas* lista_mascotas,int size_mascotas,eclientes*  lista_clientes,int size_clientes);

void clientes_mascotas_hembra(emascotas* lista_mascotas,int size_mascotas,eclientes*  lista_clientes,int size_clientes);


void mostrar_clientes_mas_de_una_mascota(eclientes* lista_clientes,int size_clientes,emascotas* lista_mascotas,int size_mascotas);

void mostrar_clientes_de_dos_o_mas_mascota(eclientes* lista_clientes,int size_clientes,emascotas* lista_mascotas,int size_mascotas,char* tipo);

int contador_mascotas_por_cliente_del_mismo_tipo(eclientes* cliente,emascotas* lista_mascotas,int size_mascotas);


int contador_mascotas_por_cliente(eclientes* cliente,emascotas* lista_mascotas,int size_mascotas);


int set_raza_mascota(emascotas* mascota,eRaza* lista_raza,int size_raza);

int set_duenio_mascota(emascotas* mascota,eclientes* lista_clientes,int size_clientes,int id_inicial_duenio,int id_duenio);

int define_to_string(int definido,char* ret);
