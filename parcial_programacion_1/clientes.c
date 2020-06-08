#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "clientes.h"
#include "Functions.h"


#define CARGADO 1
#define LIBRE 0

void inicializar_clientes(eclientes* lista_clientes,int size_clientes)
{
    int i;

    for(i=0;i<size_clientes;i++)
    {

       lista_clientes[i].estado = LIBRE;
       //lista_clientes[i].cont_mascotas = 0;
    }
}

void mostrar_cliente(eclientes clientes)
{
    char localidad [3][50] = {"QUILMES","ROSARIO","SANTA ROSA"};

    printf("%4d %15s %15s %15s %15d %10d %20s  \n",clientes.id, clientes.nombre, clientes.apellido, localidad[clientes.id_localidad] /*clientes.localidad*/ ,clientes.telefono, clientes.edad, clientes.sexo);
}

void mostrarTodos_clientes(eclientes* lista_clientes,int size_clientes)
{
    int i;


    printf("%4s %15s %15s %15s %10s %10s %10s\n","ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO");

    for(i=0;i<size_clientes;i++)
    {
        if(lista_clientes[i].estado == CARGADO)
        {

            mostrar_cliente(lista_clientes[i]);
        }
    }
}

int buscar_cliente_by_id(eclientes* lista_clientes,int size_clientes,int id)
{
    int index = -1;
    int i;

    for(i=0;i<size_clientes;i++)
    {
        if(lista_clientes[i].estado == CARGADO && lista_clientes[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

int set_nombre_cliente(eclientes* cliente)
{
    int resultado = 0;

    if ( UTN_getStringName(cliente->nombre,sizeof(cliente->nombre),"ingrese el nombre del cliente: ","error.\n",3) )
    {
        resultado = 1;
    }
    return resultado;
}

int set_apellido_cliente(eclientes* cliente)
{
    int resultado = 0;

    if (UTN_getStringName(cliente->apellido,sizeof(cliente->apellido),"ingrese el apellido del cliente: ","error.\n",3) )
    {
        resultado = 1;
    }
    return resultado;
}

int set_localidad_cliente(eclientes* cliente)
{
    int resultado = 0;

    if (UTN_getNumberInt(&cliente->id_localidad,"ingrese la localidad del cliente \n 0.QUILMES\n 1.ROSARIO\n 2.SANTA ROSA \ningrese: ","\nerror.",0,2,3))
    {
        resultado = 1;
    }

    /*if (UTN_getStringName(cliente->localidad,sizeof(cliente->localidad),"ingrese la localidad del cliente: ","error.\n",3) )
    {
        resultado = 1;
    }*/



    return resultado;
}

int set_telefono_cliente(eclientes* cliente)
{
    int resultado = 0;

    if (UTN_getNumberInt(&cliente->telefono,"ingrese el telefono del cliente: ","error.\n",1,99999999,3) )
    {
        resultado = 1;
    }
    return resultado;
}

int set_edad_cliente(eclientes* cliente)
{
    int resultado = 0;

    if (UTN_getNumberInt(&cliente->edad,"ingrese la edad del cliente: ","error.\n",1,100,3) )
    {
        resultado = 1;
    }
    return resultado;
}

int set_sexo_cliente(eclientes* cliente)
{
    int resultado = 0;
    int sexo;

    if (UTN_getNumberInt(&sexo,"1.MASCULINO\n2.FEMENINO\ningrese el sexo del cliente: ","error.\n",1,2,3) )
    {

        switch(sexo)
        {
            case 1:
                strcpy(cliente->sexo,"MASCULINO");
                resultado = 1;
            break;
            case 2:
                strcpy(cliente->sexo,"FEMENINO");
                resultado = 1;
            break;
        }
    }

    return resultado;
}


int cargar_cliente(eclientes* clienteAux,int* id_duenio)
{
    int resultado = 0;
        if (set_nombre_cliente(clienteAux) )
        {
            resultado = 1;
        }

        if (set_apellido_cliente(clienteAux) )
        {
            resultado = 1;
        }

        if (set_localidad_cliente(clienteAux) )
        {
           resultado = 1;
        }

        if (set_telefono_cliente(clienteAux) )
        {
            resultado = 1;
        }

        if (set_edad_cliente(clienteAux) )
        {
            resultado = 1;
        }

        if (set_sexo_cliente(clienteAux) )
        {
            resultado = 1;
        }

        if ( resultado == 1)
        {
            clienteAux->estado = CARGADO;
            clienteAux->id = (int)*id_duenio;
            (*id_duenio)++;
        }

    return resultado;
}


int alta_cliente(eclientes* lista_clientes,int size_clientes,int* id_duenio)
{
    int i;
   // int sexo = -1;
    int resultado = 0;

    eclientes clienteAux;

    for(i=0;i<size_clientes;i++)
    {
        if(lista_clientes[i].estado == LIBRE)
        {

            if( cargar_cliente(&clienteAux,id_duenio) )
            {
                lista_clientes[i] = clienteAux;
                resultado = 1;
                break;
            }
        }
    }

    return resultado;
}

int modificar_cliente(eclientes* lista_clientes,int size_clientes,int id_duenio)
{
    int resultado = 0;
    int id;
    int index = -1;
    char opcion = 's';

    int modificar;
    char confirmar = 's';

    eclientes clienteAux;

    do
    {
        mostrarTodos_clientes(lista_clientes,size_clientes);

        UTN_getNumberInt(&id,"ingrese el id del cliente: ","error.\n",0,id_duenio-1,1);

        index = buscar_cliente_by_id(lista_clientes,size_clientes,id);

        if (index == -1 )
            {
                printf("error, el id no existe.\n");
            }else
                {
                    clienteAux = lista_clientes[index];
                }

    }while(index == -1);

    do
    {
        UTN_getNumberInt(&modificar,"\n1.Modificar nombre\n2.Modificar apellido\n3.Modificar localidad\n4.Modificar telefono\n5.Modificar edad\n6.Modificar sexo\n7.Salir\n8.Cancelar\nElija que dato modificar :","Error.\n",1,8,3);
        switch( modificar )
        {
            case 1:
                if (set_nombre_cliente(&clienteAux) )
                {
                    resultado = 1;
                }
            break;

            case 2:
                if (set_apellido_cliente(&clienteAux) )
                {
                    resultado = 1;
                }
            break;

            case 3:
                if (set_localidad_cliente(&clienteAux) )
                {
                    resultado = 1;
                }
            break;

            case 4:
                if (set_telefono_cliente(&clienteAux) )
                {
                    resultado = 1;
                }
            break;

            case 5:
                if (set_edad_cliente(&clienteAux) )
                {
                    resultado = 1;
                }
            break;

            case 6:
                if (set_sexo_cliente(&clienteAux) )
                {
                    resultado = 1;
                }
            break;

            case 7:
                opcion = 'n';
            break;
            case 8:
                confirmar = 'n';
            break;

            default:
                printf("\nopcion incorrecta.Reingrese.");
            break;

        }

        //UTN_getOption_char(&opcion,"\ndesea modificar mas datos del cliente? s/n : ","\nerror.",a,b,3);

    }while(opcion=='s');

    //UTN_getOption_char(&confirmar,"\nEsta seguro de confirmar los cambio realizados? s/n :","",'s','n',3);

    if(confirmar == 's')
    {
        //clienteAux.id = lista_clientes[index].id;
        //clienteAux.estado = lista_clientes[index].estado;
        lista_clientes[index] = clienteAux;
    }

    return resultado;
}



float promedio_clientes_masculino(eclientes* lista_clientes,int size_clientes)
{
    int i;
    int cont=0;
    int masculino=0;
    float promedio=0;

    for(i=0 ; i<size_clientes ; i++)
    {
        if(lista_clientes[i].estado == CARGADO)
        {
            cont++;

            if(strcmp(lista_clientes[i].sexo,"MASCULINO")==0)
            {
                masculino++;
            }

        }
    }
    promedio=(float)cont/masculino;
    return promedio;
}

float promedio_clientes_femenino(eclientes* lista_clientes,int size_clientes)
{
    int i;
    int cont=0;
    int femenino=0;
    float promedio=0;

    for(i=0 ; i<size_clientes ; i++)
    {
        if(lista_clientes[i].estado == CARGADO)
        {
            cont++;

            if(strcmp(lista_clientes[i].sexo,"FEMENINO")==0)
            {
                femenino++;
            }

        }
    }
    promedio=(float)cont/femenino;
    return promedio;
}


int mostrar_clientes_por_localidad(eclientes* lista_clientes,int size_clientes,int localidad)
{
    int i;
    int resultado = 0;

    for ( i=0;i<size_clientes;i++)
    {
         if (lista_clientes[i].estado == CARGADO &&  lista_clientes[i].id_localidad == localidad)
         {
             mostrar_cliente(lista_clientes[i]);
         }
    }



    return resultado;
}




