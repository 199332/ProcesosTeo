#include <stdio.h>
#include <string.h>

void main(int argc, char const *argv[])
{
    /* pido un nombre por teclado */

    
/*variable para guardar nombre*/
    char cadenaSalida[]="salir";
   fprintf(stdout, "Escribe un nombre para saludar: ");
   char nombre[15];
   fscanf(stdin,"%s",nombre);
   while(strcmp(cadenaSalida, nombre)!=0){
       
       fprintf(stdout,"Hola %s.\ntu inicial es %c\n", nombre,nombre[0]);
       fscanf(stdin,"%s",nombre);
   }
   fprintf(stdout,"Se escribio la palabra clave %s\n", nombre);
   
   
    
}