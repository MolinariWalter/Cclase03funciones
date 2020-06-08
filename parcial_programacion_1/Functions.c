#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"

int UTN_getNumberInt(int* number, char* message, char* errorMessage, int min, int max, int retries)
{
    int bufferInt;
    int result = 0;
    while(retries > 0)
    {
        retries--;
        printf("%s",message);
        fflush(stdin);
        if(UTN_getInt(&bufferInt)==1 )
        {
            if(bufferInt >= min && bufferInt <= max)
            {
                *number = bufferInt;
                result = 1;
                break;
            }
        }
        printf("%s",errorMessage);
    }

    return result;
}

int UTN_getInt(int* number)
{
    int result = 0;
    char str[20];
    if(number != NULL)
    {
        if( UTN_myGets(str,sizeof(str))== 1 )
        {
            if(UTN_isNumber(str)==1)
            {
               *number = atoi(str);
                result = 1;
            }

        }
    }
    return result;
}


int UTN_myGets(char* str, int len)
{
    int result = 0;

    if( str != NULL && len >0 )
    {

        fgets(str,len,stdin);

        fflush(stdin);///reemplazar por funcion
        if(str[strlen(str)-1] == '\n')
        {
            str[strlen(str)-1] = '\0';
            result = 1;
        }

    }
    return result;
}

int UTN_isNumber(char* str)
{
    int i=0;
    int result = 1;
    if(str != NULL && strlen(str) > 0)
    {
        if(str[0]=='-')
        {
            i++;
        }
        while(str[i] != '\0')
        {
            if(str[i] < '0' || str[i] > '9')
            {
                result = 0;
                break;
            }
            i++;
        }
    }
    return result;
}

int UTN_getStringName(char* name,int tam, char* message, char* errorMessage, int retries)
{
    char nameAux[20];
    int result = 0;
    while(retries > 0)
    {
        retries--;
        printf("%s",message);
        fflush(stdin);

        if(UTN_getString(nameAux,tam)==1)
        {
            strcpy(name, nameAux);
            result = 1;
            break;
        }
        printf("%s",errorMessage);
    }

    return result;
}


int UTN_getOption_char(char* caracter, char* message, char* errorMessage, char a, char b, int retries)
{
    char bufferchar;

    int result = 0;
    while(retries > 0)
    {
        retries--;
        printf("%s",message);
        fflush(stdin);
        if(UTN_myGets(&bufferchar,sizeof(bufferchar)) == 1 )//UTN_getInt(&bufferInt)==1 )
        {
            if(bufferchar == a || bufferchar == b)
            {
                *caracter = (char)bufferchar;
                //strcpy(caracter,bufferchar);
                result = 1;
                break;
            }
        }
        printf("%s",errorMessage);
    }

    return result;
}


int UTN_getString(char* str, int tam)
{
    int result = 0;
    if(str != NULL )
    {
        if( UTN_myGets( str,tam) ==1 )
        {
            if(UTN_isString(str,tam)==1 )
            {
                result = 1;
            }
        }
    }
   return result;
}

int UTN_isString(char* str, int tam)
{
    int i=0;
    int result = 1;
    if(str != NULL && tam > 0)
    {
        while(str[i] != '\0')
        {
            if( (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] !=' ' )
            {
                result = 0;
                break;
            }
            i++;
        }
    }
    return result;
}


int UTN_getNumberFloat(float* fNumber, char* message, char* errorMessage, float min, float max, int retries)
{
    int result = 0;
    //char fbuffer[20];
    float fAux;
    while(retries > 0)
    {
        retries--;
        printf("%s",message);
        //if(UTN_getFloat(&fbuffer) )
        if(UTN_getFloat(&fAux) )
            {

                if(fAux >= min && fAux <= max)
                {
                     *fNumber = fAux;
                      result = 1;
                      break;
                }
            }
            printf("%s",errorMessage);
    }
    return result;
}
int UTN_getFloat(float* number)
{
    int result = 0;
    char str[20];

    if(str != NULL)
    {
        if( UTN_myGets (str,sizeof(str) ) )// && UTN_isFloat(str))
        {
            if( UTN_isFloat(str) )
                {
                    *number=atof(str);
                    result = 1;
                }
        }
    }

    return result;
}
int UTN_isFloat(char* str)
{

    int i=0;
    int contPuntos=0;
    int contMenos=0;
    int contNonumerico=0;
    int posicionPunto=-1;

    int contNumero=0;
    int esFloat=1;


    if( str != NULL && strlen(str) > 0)
    {
         if(str[0]=='-')
            {
                i++;
                contMenos++;
            }

        while(str[i]!='\0')
        {
            if(str[i]<'0' || str[i]>'9')///si no es numerico cuento y busco un punto (.)
                {
                    contNonumerico++;
                    if(str[i]=='.')
                        {
                            contPuntos++;
                            posicionPunto=i;
                        }
                }else /// entonces es numerico y cuento
                    {
                        contNumero++;
                    }

                i++;
            }///fin while
    }


    if(contPuntos!=1)/// si tiene ninguno o mas de un punto --> no es float
    {
        esFloat=0;
    }else
        {
            if(contPuntos<contNonumerico || (contMenos==1 && posicionPunto==1) || (posicionPunto==0) || (contNumero<2))/// si la cantidad de noNumericos es distinto de cantidadPuntos --> no es float
            {
                esFloat=0;
            }

        }

    return esFloat;
}


