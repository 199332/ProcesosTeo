#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *archivo; 
    
    if ((archivo = fopen("texto.txt","r"))== NULL) {
        perror("la ruta del fichero es erronea");
    }
    
    //char letra = argv[1];
    //char[80] leo;
    //leo = fgetc(archivo);
    char leer;
    while((leer=fgetc(archivo))!=EOF){
       
           printf("%c", leer);

    }
    printf("\n");
    
    



    return 0;
}
