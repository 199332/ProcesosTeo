#include <stdio.h>

int main(int argc, char const *argv[])
{   //creo una variable de tipo FILE con la que habriré el archivo
    FILE *archivo;    
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    if ((archivo = fopen("texto.txt","r"))== NULL) {
        perror("la ruta del fichero es erronea");
    }    

    //char letraClave = argv[2];
    char letraClave = 'a';
    //esta variable va ir almacenando cada caracter que se va a leer
    printf("la letra clave es: %c\n",letraClave);
    char leer;
    //leo el fichero dandole valor a la variable leer y cuando llega al final 
    //EOF  sale del bucle
    while((leer=fgetc(archivo))!=EOF){
        //muestro por pantalla cada caracter
        printf("%c", leer);   
        
    }
    printf("\n");
    //cierro el fichero
    fclose(archivo);
    



    return 0;
}