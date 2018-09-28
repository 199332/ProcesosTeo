#include <stdio.h>

void main(int argc, char const *argv[])
{
    /* escanea un entero y la devuelva */

    int num;
    //pido al usuario un entero
    fprintf(stdout,"Escribe un entero: ");
    //recibo un entro por teclado %d &indica la direcion de memoria a utilizar para poder leerlo
    fscanf(stdin,"%d",&num );
    //muestro el entero introducido por teclado
    fprintf(stdout, "El entero es %d\n", num);
    fprintf(stdout,"El entero es %d y se encuentra en la dirección de memoria %d\n",num, &num);
    
}