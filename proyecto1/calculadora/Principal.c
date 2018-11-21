#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100
int main(int argc, char const *argv[])
{
    //pido un nº por teclado
    fprintf(stdout,"inserte un número: ");
    double num1;
    char txtnum1[TAM_MAX];
    fgets(txtnum1, TAM_MAX,stdin);
    num1 = atof(txtnum1);
    //atof(num1, txtnum1);
    //recojo el número que se ha introducido por teclado en la variable
    //fscanf(stdin,"%f",&num1);//PONER & PARA RECOJER LOS DATOS
    //Pido la operación que se desea hacer
    
    //fprintf(stdout, "elija la operación que desea hacer(+,-,*,/)escribiendo el caracter correspondiente:");
    //char operacion;
    /*la funcion fscanf DA PROBLEMAS AL RECOGER LOS DATOS EN LA SEGUNDA VEZ USAR 
    usar la funcion de abajo o duplicar para que una recoja el enter y otra el simbolo*/
    //fscanf(stdin,"%[^\n]%*c", &operacion);
    //o esta
    //char txtnum2[TAM_MAX];
    //gets(txtnum1,TAM_MAX);
    //fscanf(stdin,"%c",&operacion);
    //fscanf(stdin,"%c",&operacion);
    printf("\nnumero1 txt %s  numero double %lf y la operacion que va a realizar es:  \n",txtnum1, atof(txtnum1));
    return 0;
}
