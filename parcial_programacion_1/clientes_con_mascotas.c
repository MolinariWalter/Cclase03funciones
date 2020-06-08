#include "clientes_con_mascotas.h"
#include "Functions.h"
#define LIBRE 0
#define OCUPADO 1

#define SIAMES 0
#define YAMA 1
#define ANGORA 2
#define PITBULL 3
#define IGUANA 4
#define LABRADOR 5
#define BULLDOG 6



void inicializar_cliente_mascota(ecliente_mascota* clientemascota)
{
    clientemascota->edad_total=0;
    clientemascota->cont_macho=0;
    clientemascota->cont_hembra=0;
    clientemascota->cont_peso=0.0;
    clientemascota->cont_perro=0;
    clientemascota->cont_gato=0;
    clientemascota->cont_raro=0;
}



void harcodear_mascotas(emascotas* lista_mascotas,int size_mascotas,eclientes* listaclientes,int size_clientes,int* id_mascota,ecliente_mascota* clientemascota)
{
    int i;

    char nombre[11][20] = { "tomas","zaira","boby","laila","fantasma","mancha","colita","fido","tete","negri","firulay"};
    char tipo[11][20] = {"gato","perro","perro","raro","gato","perro","raro","perro","gato","gato","perro"};
    //char raza[11][20] = {"siames","siames","pitbull","yama","angora","pitbull","iguana","labrador","angora","siames","bulldog"};
    int id_raza [11]= {SIAMES,BULLDOG,PITBULL,YAMA,ANGORA,PITBULL,IGUANA,LABRADOR,ANGORA,SIAMES,BULLDOG};
    int edad [11] = {4,2,5,10,6,2,2,6,3,7,2};
    float peso[11]= {5.3,4.0,8.1,8.9,4.2,10.1,1.4,3.8,4.6,6.4,11.2};


    char sexo[11][20] = {"MACHO","HEMBRA","MACHO","HEMBRA","MACHO","MACHO","HEMBRA","MACHO","MACHO","HEMBRA","MACHO"};
    int id_duenio[11]= {100,100,101,101,101,102,102,103,104,104,104};

    clientemascota->edad_total=49;
    clientemascota->cont_macho=7;
    clientemascota->cont_hembra=4;
    clientemascota->cont_peso=68;
    clientemascota->cont_perro=5;//lista_clientes
    clientemascota->cont_gato=5;
    clientemascota->cont_raro=1;

    for(i=0;i<size_mascotas;i++)
    {

        lista_mascotas[i].id = (int)*id_mascota;

        strcpy(lista_mascotas[i].nombre, nombre[i]);
        strcpy(lista_mascotas[i].tipo, tipo[i]);
        lista_mascotas[i].id_raza = id_raza[i];
        lista_mascotas[i].edad = edad[i];
        lista_mascotas[i].peso = peso[i];
        strcpy(lista_mascotas[i].sexo, sexo[i]);
        lista_mascotas[i].id_duenio = id_duenio[i];

        lista_mascotas[i].estado = CARGADO;

        (*id_mascota)++;
    }
}

void harcodear_clientes(eclientes* lista_clientes,int size_clientes,int* id_duenio)
{
    int i;


    char nombre[5][20] = { "marta","juan","pedro","lola","pablo"};
    char apellido[5][20] = {"benitez","leirado","troglio","martinez","fernandez"};
    char localidad[5][20] = {"avellaneda","san telmo","quilmes","la plata","san jose"};
    int telefono[5] = {4250126,42308970,43346691,41219000,44509901};
    int edad [5] = {42,50,62,26,30};
    char sexo[5][20] = {"FEMENINO","MASCULINO","MASCULINO","FEMENINO","MASCULINO"};


    for(i=0;i<size_clientes;i++)
    {
        lista_clientes[i].id = (int)*id_duenio;

        strcpy(lista_clientes[i].nombre, nombre[i]);
        strcpy(lista_clientes[i].apellido, apellido[i]);
        strcpy(lista_clientes[i].localidad, localidad[i]);
        lista_clientes[i].telefono=telefono[i];
        lista_clientes[i].edad = edad[i];
        strcpy(lista_clientes[i].sexo, sexo[i]);

        lista_clientes[i].estado = CARGADO;
        (*id_duenio)++;
    }
}

void mostrar_cliente_con_mascota(eclientes clientes,emascotas mascota)
{
    printf("%4d %15s %15s %15s %10d %10d %20s %10s %10s\n",clientes.id,clientes.nombre, clientes.apellido, clientes.localidad ,clientes.telefono, clientes.edad, clientes.sexo, mascota.nombre, mascota.sexo);
}


void mostrarTodos_clientes_mascotas(eclientes* lista_clientes,int size_clientes,emascotas* lista_mascotas,int size_mascotas)
{
    int i;
    int j;
    char raza[7][10] = {"SIAMES","YAMA","ANGORA","PITBULL","IGUANA","LABRADOR","BULLDOG"};
    printf("%30s %15s %15s %15s \n","NOMBRE DEL CLIENTE","MASCOTA","TIPO","RAZA");
    for(i=0;i<size_clientes;i++)
    {
        for(j=0;j<size_mascotas;j++)
        {
            if(lista_clientes[i].estado == CARGADO && lista_mascotas[j].estado == CARGADO)
            {
                if(lista_clientes[i].id == lista_mascotas[j].id_duenio)
                {
                    printf("%15s %15s %15s %15s %15s\n",lista_clientes[i].nombre,lista_clientes[i].apellido,lista_mascotas[j].nombre,lista_mascotas[j].tipo, raza[lista_mascotas[j].id_raza] );
                }
            }
        }
    }
}

void mostrar_mascotas_con_cliente(emascotas mascotas,eclientes clientes)
{

    char raza[7][10] = {"SIAMES","YAMA","ANGORA","PITBULL","IGUANA","LABRADOR","BULLDOG"};

    printf("%4d %15s %15s %15s %10d %10.2f %20s %10s \n",mascotas.id,mascotas.nombre, mascotas.tipo, raza[mascotas.id_raza] ,mascotas.edad, mascotas.peso, mascotas.sexo,clientes.nombre);
}

void mostrarTodos_mascotas(emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes, int size_clientes)
{
    int i;
    int j;

    printf("%4s %15s %15s %15s %10s %10s %20s %10s\n","ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO","DUEÑO");

    for(i=0;i<size_mascotas;i++)
    {
        for(j=0;j<size_clientes;j++)
        {
            if(lista_mascotas[i].estado == CARGADO && lista_mascotas[i].id_duenio == lista_clientes[j].id)
             {

                  mostrar_mascotas_con_cliente(lista_mascotas[i],lista_clientes[j]);
             }
        }

    }
}


int cargar_mascota(emascotas* mascotaAux,eRaza* lista_raza,int size_raza,int* id_mascota)
{
    int resultado = 0;

    if ( set_nombre_mascota(mascotaAux) )
    {
        resultado = 1;
    }

    if ( set_tipo_mascota(mascotaAux) )
    {
        resultado = 1;
    }

    if ( set_raza_mascota(mascotaAux,lista_raza,size_raza) )
    {
        resultado = 1;
    }

    if ( set_edad_mascota(mascotaAux) )
    {
        resultado = 1;
    }

    if ( set_peso_mascota(mascotaAux) )
    {
        resultado = 1;
    }

    if ( set_sexo_mascota(mascotaAux) )
    {
        resultado = 1;
    }

    if (resultado == 1)
    {
        mascotaAux->id = (int)*id_mascota;
        mascotaAux->estado = CARGADO;
        (*id_mascota)++;
    }

    return resultado;
}



int alta_mascota(ecliente_mascota* clientemascota,emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes, int size_clientes ,eRaza* lista_raza,int size_raza, int id_duenio_inicial,int id_duenio,int* id_mascota)
{
    int i;
    int duenio = -1;
    int resultado = 0;

    emascotas mascotaAux;

    for(i=0;i<size_mascotas;i++)
    {
        if(lista_mascotas[i].estado == LIBRE)
        {

            do
            {
                if ( set_duenio_mascota(&mascotaAux,lista_clientes,size_clientes,id_duenio_inicial,id_duenio) )
                {
                    if ( cargar_mascota(&mascotaAux,lista_raza,size_raza,id_mascota) )
                    {
                        lista_mascotas[i] = mascotaAux;

                        resultado = 1;
                        duenio = 1;
                    }
                }

            }while(duenio == 0);

            clientemascota->edad_total+=mascotaAux.edad;
            clientemascota->cont_peso+=mascotaAux.peso;

            resultado = 1;
            break;
        }
    }

    return resultado;
}


/// al dar de baja restar el conteo en clientemascota -->edad,macho,hembra,etc.
int baja_mascota(emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes,int size_clientes,int id_mascota)
{
    int resultado = 0;
    int index;
    int id;
    int i;

    do
    {
        mostrarTodos_mascotas(lista_mascotas,size_mascotas,lista_clientes,size_clientes);

        UTN_getNumberInt(&id,"ingrese el id de la mascota: ","error.\n",0,id_mascota,1);

        index = buscar_mascota_by_id(lista_mascotas,size_mascotas,id);

        if (index == -1 )
            {
                printf("error, el id no existe.\n");
            }

    }while(index == -1);


    for(i=0;i<size_clientes;i++)
    {
        if(lista_mascotas[index].id_duenio==lista_clientes[i].id)
        {
            //lista_clientes[i].cont_mascotas--;
            break;
        }
    }

    lista_mascotas[index].estado = LIBRE;

    resultado = 1;

   return resultado;
}


int modificar_mascota(emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes,int size_clientes,int id_mascota,int id_duenio)
{
    int resultado = 0;
    int index;
    int id;
    int tipo = -1;
    int sexo = -1;
    int raza = -1;

    emascotas mascotaAux;

    do
    {
        mostrarTodos_mascotas(lista_mascotas,size_mascotas,lista_clientes,size_clientes);

        UTN_getNumberInt(&id,"ingrese el id de la mascota: ","error.\n",0,id_mascota,1);

        index = buscar_mascota_by_id(lista_mascotas,size_mascotas,id);

        if (index == -1 )
            {
                printf("error, el id no existe.\n");
            }

    }while(index == -1);


    mostrarTodos_clientes(lista_clientes,size_clientes);
    if (UTN_getNumberInt(&mascotaAux.id_duenio,"ingrese el id del dueño de la mascota: ","error.\n",0,id_duenio-1,3) )
    {
        resultado = -1;
    }

     if (UTN_getStringName(mascotaAux.nombre,sizeof(mascotaAux.nombre),"ingrese el nombre de la mascota: ","error.\n",3) ==0 )
            {
                resultado = -1;

            }


            if (UTN_getNumberInt(&tipo,"1.perro\n2.gato\n3.raro \ningrese el tipo de la mascota: ","error.\n",1,3,3) )
            {
                do
                {
                     switch(tipo)
                    {
                        case 1:
                            strcpy(mascotaAux.tipo,"perro");
                        break;
                        case 2:
                            strcpy(mascotaAux.tipo,"gato");
                        break;
                        case 3:
                            strcpy(mascotaAux.tipo,"raro");
                        break;
                    }

                }while(tipo == -1);



            }else
                {
                    resultado = -1;

                }

             if (UTN_getNumberInt(&raza,"1.siames\n2.yama\n3.angora\n4.pitbull\n5.iguana\n6.labrador\n7.bulldog \ningrese el tipo de la mascota: ","error.\n",1,7,3) )
            {
                do
                {
                     switch(raza)
                    {
                        case 1:

                            mascotaAux.id_raza=SIAMES;

                        break;
                        case 2:

                            mascotaAux.id_raza=YAMA;

                        break;
                        case 3:

                            mascotaAux.id_raza=ANGORA;
                        break;

                        case 4:

                            mascotaAux.id_raza=PITBULL;
                        break;

                        case 5:

                            mascotaAux.id_raza=IGUANA;
                        break;

                        case 6:

                            mascotaAux.id_raza=LABRADOR;
                        break;

                        case 7:

                            mascotaAux.id_raza=BULLDOG;
                        break;

                    }

                }while(tipo == -1);
            }


            if (UTN_getNumberInt(&mascotaAux.edad,"ingrese la edad de la mascota: ","error.\n",1,100,3) == 0 )
            {
                resultado = -1;

            }

            if (UTN_getNumberFloat(&mascotaAux.peso,"ingrese el peso de la mascota: ","error.\n",1,100,3) == 0 )
            {
                resultado = -1;

            }

             if (UTN_getNumberInt(&sexo,"1.MACHO\n2.HEMBRA\ningrese el sexo de la mascota: ","error.\n",1,2,3) )
            {
                do
                {
                     switch(sexo)
                    {
                        case 1:
                            strcpy(mascotaAux.sexo,"MACHO");
                        break;
                        case 2:
                            strcpy(mascotaAux.sexo,"HEMBRA");
                        break;

                    }

                }while(tipo == -1);



            }else
                {
                    resultado = -1;

                }




    mascotaAux.id = id;
    //mascotaAux.id_duenio = lista_mascotas[index].id_duenio;
    mascotaAux.estado = CARGADO;

    lista_mascotas[index] = mascotaAux;


    return resultado;
}


/// al modificar cliente restar el conteo en clientemascota -->edad,macho,hembra,etc.
int baja_cliente(eclientes* lista_clientes,int size_clientes,emascotas* lista_mascotas,int size_mascotas,int id_duenio)
{

    int resultado = 0;
    int index;
    int id;
    int i;

    do
    {
        mostrarTodos_clientes(lista_clientes,size_clientes);

        UTN_getNumberInt(&id,"ingrese el id del cliente: ","error.\n",0,id_duenio,1);

        index = buscar_cliente_by_id(lista_clientes,size_clientes,id);

        if (index == -1 )
            {
                printf("error, el id no existe.\n");
            }

    }while(index == -1);

    for(i=0;i<size_mascotas;i++)
    {
        if(lista_mascotas[i].id_duenio == id)
        {
            lista_mascotas[i].estado = LIBRE;
        }
    }

    lista_clientes[index].estado = LIBRE;

    resultado = 1;

   return resultado;
}

int ordenar_mascotas_por_tipo(emascotas* lista_mascotas,int size_mascotas)
{
    int i;
    int j;
    int resultado = 0;

    emascotas mascotaAux;

    for(i=0 ; i<size_mascotas-1 ; i++)
    {
        for(j=i+1 ; j<size_mascotas ; j++)
        {
            if(lista_mascotas[i].estado == CARGADO && lista_mascotas[j].estado == CARGADO && strcmp(lista_mascotas[i].tipo,lista_mascotas[j].tipo) > 0 )// >  )
            {
                mascotaAux = lista_mascotas[i];
                lista_mascotas[i] = lista_mascotas[j];
                lista_mascotas[j] = mascotaAux;
                resultado = 1;
            }
        }
    }

    return resultado;
}

void mostrar_mascotas_mas_3_anios(emascotas* lista_mascotas,int size_mascotas,eclientes* lista_clientes,int size_clientes)
{
    int i;
    int j;

    printf("%4s %15s %15s %15s %10s %10s %20s %10s\n","ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO","DUEÑO");

    for(i=0;i<size_mascotas;i++)
    {
        for(j=0;j<size_clientes;j++)
        {
            if(lista_mascotas[i].estado == CARGADO && lista_mascotas[i].edad > 3)
            {
                if(lista_mascotas[i].id_duenio==lista_clientes[j].id)
                {
                    mostrar_mascotas_con_cliente(lista_mascotas[i],lista_clientes[j]);
                }
            }
        }
    }
}

void mostrar_por_tipo(emascotas* lista_mascotas,int size_mascotas,eclientes*  lista_clientes,int size_clientes)
{
    int i;
    int tipo = -1;

    do
    {
        UTN_getNumberInt(&tipo,"mostrar mascotas por:\n1.perro\n2.gato\n3.raro\ningrese opcion: ","error.",1,3,3);
        switch(tipo)
        {
            case 1:
                for(i=0;i<size_mascotas;i++)
                {
                    if( strcmp(lista_mascotas[i].tipo,"perro") == 0)
                    {
                        mostrar_mascota(lista_mascotas[i]);
                    }
                }
            break;
            case 2:
               for(i=0;i<size_mascotas;i++)
                {
                    if( strcmp(lista_mascotas[i].tipo,"gato") == 0)
                    {
                        mostrar_mascota(lista_mascotas[i]);
                    }
                }
            break;
            case 3:
                for(i=0;i<size_mascotas;i++)
                {
                    if( strcmp(lista_mascotas[i].tipo,"raro") == 0)
                    {
                        mostrar_mascota(lista_mascotas[i]);
                    }
                }
            break;
        }

    }while(tipo == -1);

}

int ordenar_clientes_por_cantidad_mascota(emascotas* lista_mascotas,int size_mascotas,eclientes*  lista_clientes,int size_clientes)
{
    int i;
    int j;
    int resultado = 0;

    eclientes clienteAux;

    for(i=0 ; i<size_clientes-1 ; i++)
    {
        for(j=i+1 ; j<size_clientes ; j++)
        {
            if( contador_mascotas_por_cliente( &lista_clientes[i],lista_mascotas,size_mascotas ) > contador_mascotas_por_cliente( &lista_clientes[j],lista_mascotas,size_mascotas ) )
            {
                clienteAux = lista_clientes[i];
                lista_clientes[i] = lista_clientes[j];
                lista_clientes[j] = clienteAux;
                resultado = 1;
            }
        }
    }

   return resultado;
}

int ordenar_clientes_por_cantidad_mascota_nombre(emascotas* lista_mascotas,int size_mascotas,eclientes*  lista_clientes,int size_clientes)
{
    int i;
    int j;
    int resultado = 0;

    eclientes clienteAux;

    for(i=0 ; i<size_clientes-1 ; i++)
    {
        for(j=i+1 ; j<size_clientes ; j++)
        {
            if(    contador_mascotas_por_cliente(&lista_clientes[i],lista_mascotas,size_mascotas) > contador_mascotas_por_cliente(&lista_clientes[j],lista_mascotas,size_mascotas)  ||
                   (contador_mascotas_por_cliente( &lista_clientes[i],lista_mascotas,size_mascotas) == contador_mascotas_por_cliente(&lista_clientes[j],lista_mascotas,size_mascotas) && strcmp(lista_clientes[i].nombre,lista_clientes[j].nombre) > 0 ) )

            //if( (lista_clientes[i].cont_mascotas > lista_clientes[j].cont_mascotas) ||  (lista_clientes[i].cont_mascotas == lista_clientes[j].cont_mascotas && strcmp(lista_clientes[i].nombre,lista_clientes[j].nombre) > 0) )
            {
                clienteAux = lista_clientes[i];
                lista_clientes[i] = lista_clientes[j];
                lista_clientes[j] = clienteAux;
                resultado = 1;
            }
        }
    }

   return resultado;
}

float promedio_edad_mascotas(ecliente_mascota* clientemascota,emascotas* lista_mascotas,int size_mascotas)
{
    int i;
    int cont = 0;
    float promedio = 0.0;
    for(i=0 ; i<size_mascotas ; i++)
    {
        if(lista_mascotas[i].estado == CARGADO)
        {
            cont++;
        }
    }

    promedio = (float)clientemascota[0].edad_total/cont;

    return promedio;
}

float promedio_edad_mascotas_por_tipo(ecliente_mascota* clientemascota,emascotas* lista_mascotas,int size_mascotas,int tipo)
{
    int i;
    int cont = 0;
    float promedio = 0.0;
    int edad=0;

    switch(tipo)
    {
        case 1:
            for(i=0 ; i<size_mascotas ; i++)
            {
                if(lista_mascotas[i].estado == CARGADO && strcmp(lista_mascotas[i].tipo,"perro")==0 )
                {
                    edad+=lista_mascotas[i].edad;
                    cont++;
                }
            }

            promedio = (float)edad/cont;
        break;
        case 2:
            for(i=0 ; i<size_mascotas ; i++)
            {
                if(lista_mascotas[i].estado == CARGADO && strcmp(lista_mascotas[i].tipo,"gato")==0 )
                {
                    edad+=lista_mascotas[i].edad;
                    cont++;
                }
            }

            promedio = (float)edad/cont;

        break;
        case 3:
            for(i=0 ; i<size_mascotas ; i++)
            {
                if(lista_mascotas[i].estado == CARGADO && strcmp(lista_mascotas[i].tipo,"raro")==0 )
                {
                    edad+=lista_mascotas[i].edad;
                    cont++;
                }
            }

            promedio = (float)edad/cont;

        break;
    }



    return promedio;
}

void clientes_mascotas_macho(emascotas* lista_mascotas,int size_mascotas,eclientes*  lista_clientes,int size_clientes)
{
    int i;
    int j;
    for(i=0;i<size_clientes;i++)
    {
        for(j=0;j<size_mascotas;j++)
        {
            if( lista_clientes[i].id == lista_mascotas[j].id_duenio )
            {
                if(strcmp(lista_mascotas[j].sexo,"MACHO")==0)
                {
                    mostrar_cliente_con_mascota(lista_clientes[i],lista_mascotas[j]);

                }

            }
        }
    }
}

void clientes_mascotas_hembra(emascotas* lista_mascotas,int size_mascotas,eclientes*  lista_clientes,int size_clientes)
{
    int i;
    int j;
    for(i=0;i<size_clientes;i++)
    {
        for(j=0;j<size_mascotas;j++)
        {
            if( lista_clientes[i].id == lista_mascotas[j].id_duenio )
            {
                if(strcmp(lista_mascotas[j].sexo,"HEMBRA")==0)
                {
                    mostrar_cliente_con_mascota(lista_clientes[i],lista_mascotas[j]);

                }

            }
        }
    }
}

int set_duenio_mascota(emascotas* mascota,eclientes* lista_clientes,int size_clientes,int id_inicial_duenio,int id_duenio)
{
    int resultado = 0;
    int id;
    int i;

    for(i=0;i<size_clientes;i++)
    {
        if(lista_clientes[i].estado == OCUPADO)
        {
            printf("%10s %10s %4d\n",lista_clientes[i].nombre,lista_clientes[i].apellido,lista_clientes[i].id);
        }
    }

    if ( UTN_getNumberInt(&id,"ingrese el id del dueño de la mascota :","error.\n",id_inicial_duenio,id_duenio-1,3))
    {
        for(i=0;i<size_clientes;i++)
        {
            if ( lista_clientes[i].id == id)
            {
                mascota->id_duenio = id;
                resultado = 1;
                break;
            }
        }

    }

    return resultado;
}

int set_raza_mascota(emascotas* mascota,eRaza* lista_raza,int size_raza)
{
    int resultado = 0;
    int i;
    int j = 0;
    int raza;

    for(i=0;i<size_raza;i++)
    {
        if( lista_raza[i].estado == CARGADO)
        {
            printf("%d. %s\n",lista_raza[i].id_raza,lista_raza[i].nombre_raza);
            j = lista_raza[i].id_raza;
        }

    }

    if ( UTN_getNumberInt(&raza,"ingrese la opcion de la raza de la mascota :","error.\n",0,j,3))
    {
        mascota->id_raza = raza;
        resultado = 1;
    }


    return resultado;
}

void mostrar_clientes_mas_de_una_mascota(eclientes* lista_clientes,int size_clientes,emascotas* lista_mascotas,int size_mascotas)
{
    int i;

    int contador;

    printf("%4s %15s %15s %15s %10s %10s %10s\n","ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO");

    for ( i=0 ; i<size_clientes ; i++)
    {
        contador = contador_mascotas_por_cliente(&lista_clientes[i],lista_mascotas,size_mascotas);
        if ( contador > 1)
        {
            mostrar_cliente( lista_clientes[i]);
            contador = 0;
        }

    }

}

int contador_mascotas_por_cliente(eclientes* cliente,emascotas* lista_mascotas,int size_mascotas)
{
    int resultado = 0;

    int j;

    for ( j=0 ; j<size_mascotas ; j++)
    {
        if ( cliente->id == lista_mascotas[j].id_duenio)
        {
            resultado++;
        }
    }
    return resultado;
}

/**
#define SIAMES 0
#define YAMA 1
#define ANGORA 2
#define PITBULL 3
#define IGUANA 4
#define LABRADOR 5
#define BULLDOG 6
*/
int define_to_string(int definido,char* str)
{
    int ret = 0;

    switch(definido)
    {
        case SIAMES:
            strcpy(str,"SIAMES");
            ret = 1;
        break;
        case YAMA:
            strcpy(str,"YAMA");
            ret = 1;
        break;
        case ANGORA:
            strcpy(str,"ANGORA");
            ret = 1;
        break;
        case PITBULL:
            strcpy(str,"PITBULL");
            ret = 1;
        break;
        case IGUANA:
            strcpy(str,"IGUANA");
            ret = 1;
        break;
        case LABRADOR:
            strcpy(str,"LABRADOR");
            ret = 1;
        break;
        case BULLDOG:
            strcpy(str,"BULLDOG");
            ret = 1;
        break;
    }


    return ret;
}
