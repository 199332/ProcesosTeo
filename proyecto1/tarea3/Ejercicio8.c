/*Diccionariov2: Realizar el ejercicio7 en un bucle que no saldrá hasta que escribamos 
la cadena ".-" como palabra.*/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //creo variable tipo file y abro el fichero con permisos de escritura
    FILE *archivoEjer8;
    //archivoEjer1 = fopen("ejercicio5.txt","w");
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    //"a+" abre o crea un fichero de texto para añadirle datos. 
    if ((archivoEjer8 = fopen("ejer7.txt","a+"))== NULL) {
        perror("la ruta del fichero es erronea");
    }     
    char palabra[100];
    char word[100];
    char *salir = ".-";
    printf(salir);
    while(salir!='a'){
       
       if (palabra[0]=='.'&& palabra[1]=='-') {
           salir = 'a';
           break;
       }
       else  {
           
        //pido palabra en español
        fprintf(stdout, "Escribe una palabra en español: ");
        
        //stdin para recoger texto por consola, se debe poner el simbolo & para leer    
        fscanf(stdin,"%s",&palabra);//ESTA FUNCIÓN DA PROBLEMAS PORQUE AL INTRODUCIR CARACTERES
        //pido palabra en español
        int longitud = strlen(palabra);
        for(int i = 0; i < longitud; i++)    {
            fputc(palabra[i], archivoEjer8);
            //fwrite(&nombre[i],1,sizeof(nombre), archivoEjer3);
        } 
        if (palabra[0]=='.'&& palabra[1]=='-') {
           salir = 'a';
           break;
       }
        //para añadir un salto de línea debe ir entre comillas simples
        fputc('=', archivoEjer8);
        fprintf(stdout, "Escribe la misma palabra en inglés: ");
        
        //stdin para recoger texto por consola, se debe poner el simbolo & para leer    
        fscanf(stdin,"%s",&word);//ESTA FUNCIÓN DA PROBLEMAS PORQUE AL INTRODUCIR CARACTERES 
         int longitud2 = strlen(word);
        for(int i = 0; i < longitud2; i++)    {
            fputc(word[i], archivoEjer8);
            //fwrite(&nombre[i],1,sizeof(nombre), archivoEjer3);
        } 
        //para añadir un salto de línea debe ir entre comillas simples
        fputc('\n', archivoEjer8); 
       }
       
       
    
        
    }
    //cierro el fichero, para cerrar se usa la función y se le pasa el fichero no se 
    //necesita igualar
     //fclose(archivoEjer);
    if (fclose(archivoEjer8)!=0)  {
    perror("No se ha podido cerrar el fichero.\n");	
  }
    return 0;
}