#include <stdio.h>

void main(int argc, char const *argv[])
{
    /* escanea un entero y la devuelva */

    int num;
    //pido al usuario un entero
    fprintf(stdout,"Escribe un entero: ");
    fscanf(stdin,"%d\n",&num );
    fprintf(stdout, "El entero es %d\n", num);
    
}
