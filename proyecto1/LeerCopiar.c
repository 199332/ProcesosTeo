#include <stdio.h>

int main(int argc, char const *argv[])
{   //creo una variable de tipo FILE con la que habriré el archivo
    FILE *archivo;
    FILE *archivoNuevo;
    //char* nos vale para string
    //char* ruta = argv[1];
    archivoNuevo = fopen("texto_A.txt","w"); 
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    if ((archivo = fopen(argv[1],"r"))== NULL) {
        perror("la ruta del fichero es erronea");
    }    
//PARA PARA ARGUMENTOS DESPUES DE ./PROGRAMA ES ARGV[0], LO SIGUIENTE QUE ESCRIBA ES ARGV[1]
//Y PARA RECOGER UN CHAR ARGV[Nº DEL ARGUMENTO][NºDEL CHAR QUE QUIERO COGER]
    char letraClave = argv[2][0]; 
    
    //printf(ruta);
    //char letraClave = 'a';
    //esta variable va ir almacenando cada caracter que se va a leer
    printf("\nla letra clave es: %c\n",letraClave);
    char leer;
    //leo el fichero dandole valor a la variable leer y cuando llega al final 
    //EOF  sale del bucle
    while((leer=fgetc(archivo))!=EOF){
        //muestro por pantalla cada caracter
        //printf("%c", leer);
        //comparo con el caracter que no quiero copiar y copio
        if (leer != letraClave) {
            printf("%c", leer);
            //escribo el caracter en el nuevo fichero
            fputc(leer, archivoNuevo);
        }       
    }
    printf("\n");
    //cierro los ficheros
    fclose(archivo);
    fclose(archivoNuevo);

    return 0;
}
