/*Diccionario: Pedir de la entrada estandar una palabra en inglés, 
y después su traducción en español. Añadir al fichero ejer7.txt con 
el formato "word = palabra" seguido de un salto de línea.
 El fichero ejer7.txt deberá crecer en palabras en cada ejecución.*/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //creo variable tipo file y abro el fichero con permisos 
    FILE *archivoEjer7;
    
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    //"a+" abre o crea un fichero de texto para añadirle datos. 
    if ((archivoEjer7 = fopen("ejer7.txt","a+"))== NULL) {
        perror("la ruta del fichero es erronea");
    }     
        //pido palabra en español
        fprintf(stdout, "Escribe una palabra en español: ");
        char palabra[100];
        //stdin para recoger texto por consola, se debe poner el simbolo & para leer    
        fscanf(stdin,"%s",&palabra);//ESTA FUNCIÓN DA PROBLEMAS PORQUE AL INTRODUCIR CARACTERES
        //pido palabra en español
        int longitud = strlen(palabra);
        for(int i = 0; i < longitud; i++)    {
            fputc(palabra[i], archivoEjer7);
            //fwrite(&nombre[i],1,sizeof(nombre), archivoEjer3);
        } 
        //para añadir un salto de línea debe ir entre comillas simples
        fputc('=', archivoEjer7);
        fprintf(stdout, "Escribe la misma palabra en inglés: ");
        char word[100];
        //stdin para recoger texto por consola, se debe poner el simbolo & para leer    
        fscanf(stdin,"%s",&word);//ESTA FUNCIÓN DA PROBLEMAS PORQUE AL INTRODUCIR CARACTERES 
         int longitud2 = strlen(word);
        for(int i = 0; i < longitud2; i++)    {
            fputc(word[i], archivoEjer7);
            //fwrite(&nombre[i],1,sizeof(nombre), archivoEjer3);
        } 
        //para añadir un salto de línea debe ir entre comillas simples
        fputc('\n', archivoEjer7);     

    //cierro el fichero, para cerrar se usa la función y se le pasa el fichero no se 
    //necesita igualar
     //fclose(archivoEjer);
    if (fclose(archivoEjer7)!=0)  {
    perror("No se ha podido cerrar el fichero.\n");	
  }
    return 0;
}