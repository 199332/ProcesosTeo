/*Crea el programa indexarDiccionario que cree un fichero diccionario.txt 
que será igual al fichero ejer7.txt pero añadiendo números correlativos empezando 
por 0001-, 0002-, 0003-,... al inicio de cada 
línea del fichero (rebusca en el man de printf cómo hacerlo).*/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //creo variable tipo file y abro el fichero con permisos
    FILE *archivoEjer7;
    
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    //"a+" abre o crea un fichero de texto para añadirle datos. 
    if ((archivoEjer7 = fopen("diccionario.txt","a+"))== NULL) {
        perror("la ruta del fichero es erronea");
    }   
    char prueba ='\0001';
    printf("%x prueba\n"); 
    char lee;
    int contador = 1;
    while((lee = fgetc(archivoEjer7))!=EOF){
        
        if (lee =='\n') {
            contador++;
        }
        
    }
    
   /*if (contador == 0001) {
        fputc(contador, archivoEjer7);
        fputc('-', archivoEjer7);
        fputc(' ', archivoEjer7);
    }*/
    fprintf(archivoEjer7,"000%x- ", contador);
    
     
        //pido palabra en español
        fprintf(stdout, "Escribe una palabra en español: ");
        char palabra[100];
        //stdin para recoger texto por consola, se debe poner el simbolo & para leer    
        fscanf(stdin,"%s",&palabra);//ESTA FUNCIÓN DA PROBLEMAS PORQUE AL INTRODUCIR CARACTERES
        //pido palabra en español
        /*int longitud = strlen(palabra);
        for(int i = 0; i < longitud; i++)    {
            fputc(palabra[i], archivoEjer7);
            //fwrite(&nombre[i],1,sizeof(nombre), archivoEjer3);
        } */
        fprintf(archivoEjer7,"%s ", &palabra);
        //para añadir un salto de línea debe ir entre comillas simples
        fputc('=', archivoEjer7);
        fprintf(stdout, "Escribe la misma palabra en inglés: ");
        char word[100];
        //stdin para recoger texto por consola, se debe poner el simbolo & para leer    
        fscanf(stdin,"%s",&word);//ESTA FUNCIÓN DA PROBLEMAS PORQUE AL INTRODUCIR CARACTERES 
        /* int longitud2 = strlen(word);
        for(int i = 0; i < longitud2; i++)    {
            fputc(word[i], archivoEjer7);
            //fwrite(&nombre[i],1,sizeof(nombre), archivoEjer3);
        } */
        fprintf(archivoEjer7," %s ", &word);
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