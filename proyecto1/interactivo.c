#include <stdio.h>

void main(int argc, char const *argv[])
{
    /* pido un nombre por teclado */

    fprintf(stdout, "Escribe un nombre para saludar: ");
/*variable para guardar nombre*/
    char nombre[15];
   
    //recojo el nombre y lo guardo en nombre
    fscanf(stdin,"%s",nombre );
    //muestro el valor de nombre
    fprintf(stdout, "Hola %s\n", nombre);
    //para imprimir un caracter
    fprintf(stdout,"Hola %s.\n Tu inicial es %c\n",nombre, nombre[0]);
    
    
}