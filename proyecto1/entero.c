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
    /*hago que imprima la dirección de la salida de memoria del entero/num
    entre comilla escribo lo que quiero que muestre y luego le paso las variable que son los
    valores que necesitan %d %ld*/
    fprintf(stdout,"El entero es %d y se encuentra en la dirección de memoria %ld\n",num, &num);
    
}