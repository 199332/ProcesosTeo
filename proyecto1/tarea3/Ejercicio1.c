#include <stdio.h>

int main(int argc, char const *argv[])
{
    //creo variable tipo file y abro el fichero con permisos de escritura
    FILE *archivoEjer1;
    //archivoEjer1 = fopen("ejercicio1.txt","w");
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    if ((archivoEjer1 = fopen("ejercicio1.txt","w"))== NULL) {
        perror("la ruta del fichero es erronea");
    }    
    fprintf(stdout, "Escribe un mensaje, solo los 4 primero caracteres se almacenaran en el fichero: ");
    //para recoger cadenas de texto se usar char *variable
    //char *nombre; no lo uso porque me da problemas al escribir el fichero
    char nombre[1000];
    //stdin para recoger texto por consola, se debe poner el simbolo & para leer    
    fscanf(stdin,"%s",&nombre);
    //para mostrar se debe usar también el & antes de la variable y %s para string y %c carácteres
    //stdout para mostrar por pantalla
    /*como no he usado el char *nombre no se necesita poner & para leer carácter a carácter*/
    //fprintf(stdout,"Hola %s.\nTu inicial es %c\n",&nombre,nombre[0]);
    /*recorro el array tipo char para escribir solo los 4 primero caracteres*/
    for(int i = 0; i < 4; i++)
    {
        fputc(nombre[i], archivoEjer1);
    }    
    //cierro el fichero, para cerrar se usa la función y se le pasa el fichero no se 
    //necesita igualar
     //fclose(archivoEjer1);
    if (fclose(archivoEjer1)!=0)  {
    perror("No se ha podido cerrar el fichero.\n");	
  }
    return 0;
}