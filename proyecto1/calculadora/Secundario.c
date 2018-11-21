#include <stdio.h>

int main(int argc, char const *argv[])
{
    //pido un nº por teclado
    fprintf(stdout,"inserte un número: ");
    float num2;
    //recojo el número que se ha introducido por teclado en la variable
    fscanf(stdin,"%f",&num2);//PONER & PARA RECOJER LOS DATOS
    printf("numero2 %f",num2);
    return 0;
}