
#include <stdio.h>
#include <stdlib.h>

#include "Functions.h"

#include "clientes_con_mascotas.h"
#include "localidad.h"

#define T_CLIENTES 10
#define T_MASCOTAS 20
#define T_RAZA 7
#define T_LOCALIDAD 3

int main()
{

    char PERRO[50] ="PERRO";
    //char GATO[50] = "GATO";
    //char RARO[50] = "RARO";

    int localidad;

    int id_duenio = 100;
    int id_duenio_inicial = 100;
    int id_mascota = 10;
    int id_raza = 0;
    int id_localidad = 0;

    eLocalidad lista_localidad[T_LOCALIDAD];
    harcodear_localidad(lista_localidad,T_LOCALIDAD,&id_localidad);

    eRaza listaRaza[T_RAZA];
    harcodear_raza(listaRaza,T_RAZA,&id_raza);


    ecliente_mascota clientemascota;
    inicializar_cliente_mascota(&clientemascota);


    eclientes lista_clientes[T_CLIENTES];
    inicializar_clientes(lista_clientes,T_CLIENTES);

    harcodear_clientes(lista_clientes,5,&id_duenio);

    emascotas lista_mascotas[T_MASCOTAS];
    inicializar_mascotas(lista_mascotas,T_MASCOTAS);

    harcodear_mascotas(lista_mascotas,11,lista_clientes,T_CLIENTES,&id_mascota,&clientemascota);

    int opcion = -1;

    do
    {
        printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
                "1.Listar clientes\n",
                "2.Listar mascotas\n",
                "3.Listar clientes con sus mascotas\n",
                "4.Alta de mascota\n",
                "5.Baja de mascota\n",
                "6.Modificar mascota\n",
                "7.Alta cliente.\n",
                "8.Baja cliente.\n",
                "9.Ordenar mascotas por tipo.\n",
                "10.Modificar dueño\n",
                "11.Listar los dueños con mas de una mascota\n",
                "12.Listar las mascotas de mas de 3 años\n",
                "13.Listar las mascotas por un tipo en particular(perro,gato,raro)\n",
                "14.Ordenar a los dueños por cantidades de mascotas y mostrarlos\n",
                "15.Ordenar a los dueños por cantidades de mascotas y por orden alfabetico de los nombrees\n",
                "16.Mostrar el promedio de edad entre las mascotas\n",
                "17.Mostrar el promedio de edad entre las mascotas por tipo\n",
                "18.Mostrar el promedio de mujeres entre los clientes\n",
                "19.Clientes con mas de 2 o mas mascotas del mismo tipo\n",
                "20.Mostrar clientes de una localidad ingresada\n",
                "21.Ordenar por localidad y nombre del cliente\n",
                "22.salir\n",
                "Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {

            case 1:
                system("cls");
                printf("LISTA DE CLIENTES:\n");
                mostrarTodos_clientes(lista_clientes,T_CLIENTES);
            break;
            case 2:
                system("cls");
                printf("LISTA DE MASCOTAS:\n");
                mostrarTodos_mascotas(lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES);
            break;
            case 3:
                system("cls");
                printf("LISTA DE CLIENTES Y SUS MASCOTAS:\n");
                mostrarTodos_clientes_mascotas(lista_clientes,T_CLIENTES,lista_mascotas,T_MASCOTAS);
            break;

            case 4:
                system("cls");
                printf("ALTA MASCOTAS:\n");

                switch(alta_mascota(&clientemascota,lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES,listaRaza,T_RAZA,id_duenio_inicial,id_duenio,&id_mascota) )
                {
                    case 0:
                       printf("no hay espacio disponible.\n");
                    break;

                    case 1:
                        printf("carga correcta.\n");
                    break;

                    case -1:
                        printf("falla al cargar algunos de los datos.\n");
                    break;
                }
            break;

            case 5:
                system("cls");
                printf("BAJA MASCOTAS:\n");
                baja_mascota(lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES,id_mascota);

            break;

            case 6:
                system("cls");
                printf("MODIFICAR MASCOTAS:\n");
                modificar_mascota(lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES, id_mascota,id_duenio);


            break;

            case 7:
                system("cls");
                printf("ALTA CLIENTE:\n");
                alta_cliente(lista_clientes,T_CLIENTES,&id_duenio);
            break;

            case 8:
                system("cls");system("cls");
                printf("BAJA CLIENTE:\n");
                baja_cliente(lista_clientes,T_CLIENTES,lista_mascotas,T_MASCOTAS,id_duenio);

            break;

            case 9:
                system("cls");
                printf("ORDENAR MASCOTAS POR TIPO:\n");
                ordenar_mascotas_por_tipo(lista_mascotas,T_MASCOTAS);
                mostrarTodos_mascotas(lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES);
            break;

            case 10:
                system("cls");
                printf("MODIFICAR DUEÑO:\n");
                modificar_cliente(lista_clientes,T_CLIENTES,id_duenio);

            break;

            case 11:
                system("cls");
                printf("MOSTRAR DUEÑOS CON MAS DE UNA MASCOTA:\n");
                mostrar_clientes_mas_de_una_mascota(lista_clientes,T_CLIENTES,lista_mascotas,T_MASCOTAS);
            break;

            case 12:
                system("cls");
                printf("MOSTRAR MASCOTAS CON MAS DE 3 AÑOS:\n");
                mostrar_mascotas_mas_3_anios(lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES);
            break;
            case 13:
                system("cls");
                printf("MOSTRAR MASCOTAS POR TIPO:\n");
                mostrar_por_tipo(lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES);
            break;
            case 14:
                system("cls");
                printf("MOSTRAR CLIENTES ORDENADOS POR CANTIDAD DE MASCOTAS:\n");
                ordenar_clientes_por_cantidad_mascota(lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES);
                mostrarTodos_clientes_mascotas(lista_clientes,T_CLIENTES,lista_mascotas,T_MASCOTAS);
            break;

            case 15:
                system("cls");
                printf("MOSTRAR CLIENTES ORDENADOS POR CANTIDAD DE MASCOTAS Y NOMBRE:\n");
                ordenar_clientes_por_cantidad_mascota_nombre(lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES);
                mostrarTodos_clientes_mascotas(lista_clientes,T_CLIENTES,lista_mascotas,T_MASCOTAS);
            break;

            case 16:
                system("cls");
                printf("PROMEDIO DE EDAD ENTRE LAS MASCOTAS:\n");
                printf("promedio %.2f\n",promedio_edad_mascotas(&clientemascota,lista_mascotas,T_MASCOTAS));
            break;

            case 17:
                system("cls");
                printf("PROMEDIO DE EDAD ENTRE LAS MASCOTAS POR TIPO:\n");
                printf("promedio edad perro :%.2f\n",promedio_edad_mascotas_por_tipo(&clientemascota,lista_mascotas,T_MASCOTAS,1));
                printf("promedio edad gato :%.2f\n",promedio_edad_mascotas_por_tipo(&clientemascota,lista_mascotas,T_MASCOTAS,2));
                printf("promedio edad raro :%.2f\n",promedio_edad_mascotas_por_tipo(&clientemascota,lista_mascotas,T_MASCOTAS,3));
            break;

            case 18:
                system("cls");
                printf("PROMEDIO DE CLIENTES MUJERES:\n");
                //printf("promedio clientes masculinos :%.2f\n",promedio_clientes_masculino(lista_clientes,T_CLIENTES) );
                printf("promedio clientes femeninos :%.2f\n",promedio_clientes_femenino(lista_clientes,T_CLIENTES) );
            break;
            case 19:
                system("cls");
                printf("CLIENTES CON  2 O MAS MASCOTAS DEL MISMO TIPO:\n");

                mostrar_clientes_de_dos_o_mas_mascota(lista_clientes,T_CLIENTES,lista_mascotas,T_MASCOTAS,PERRO);
                /*printf("clientes con mascotas macho:\n");
                clientes_mascotas_macho(lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES);
                printf("clientes con mascotas hembra:\n");
                clientes_mascotas_hembra(lista_mascotas,T_MASCOTAS,lista_clientes,T_CLIENTES);
                */
            break;
            case 20:
                system("cls");
                printf("CLIENTES DE UNA LOCALIDAD\n");

                if (UTN_getNumberInt(&localidad,"0. QUILMES\n1.ROSARIO\n2.SANTA ROSA\n Ingrese una opcion :","\nerror..",0,2,3))
                {
                    mostrar_clientes_por_localidad(lista_clientes,T_CLIENTES,localidad);
                }else
                    {
                        printf("Error, no es posible mostrar el cliente con la localidad.\n");
                    }


            break;
            case 21:

            break;

        }

    system("pause");
    system("cls");

    }while(opcion != 22);


    return 0;
}
