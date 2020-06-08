#include <stdio.h>
#include <stdlib.h>


int UTN_getNumberInt(int* number, char* message, char* errorMessage, int min, int max, int retries);
///sample getName
int UTN_getStringName(char* name,int tam, char* message, char* errorMessage, int retries);
///sample getSalary
int UTN_getNumberFloat(float* salary, char* message, char* errorMessage, float min, float max, int retries);

int UTN_getString(char* str,int tam);

int UTN_getOption_char(char* caracter, char* message, char* errorMessage, char a, char b, int retries);


int UTN_getInt(int* number);
int UTN_myGets(char* str, int len);
int UTN_isNumber(char* str);

int UTN_getFloat();
int UTN_isFloat(char* str);

int UTN_isString(char* str,int tam);

