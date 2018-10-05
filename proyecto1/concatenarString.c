#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    /*concatenar dos string */
//no necesito indicarle los caracteres porque se los asigna el 
    char cad1[]="Hola";
    char cad2[]=" ";
    char cad3[]="mundo";
    //char cadRes[200];
    //tamTotal es el total de todas las cadena mas el \0 de final
    int tamTotal = strlen(cad1)+strlen(cad2)+strlen(cad3);
//esto es un apuntador de memoria: es una zona de memoria que esta vacia de momento
    char *cadRes = (char*)malloc((tamTotal+1)*sizeof(char));//sice indica el tamaño del caracter del char y *12 que
    // son los caracteres que le voy a pasar, necesita un cast
    //para usar el apuntador usamos la funcion malloc  para reservar memoria para ello le decimos el tamaño
    //
    
//se concatena con la funcion strcat
    //strcat(cadRes,cad1);cuando no es un char* se usa esto
    cadRes = strcat(cadRes,cad1);
    cadRes = strcat(cadRes,cad2);
    cadRes = strcat(cadRes,cad3);

    fprintf(stdout,"%s\n", cadRes);
    fprintf(stdout,"$d\n",tamTotal);

    return 0;
}
