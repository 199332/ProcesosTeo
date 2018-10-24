#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *archivo; 
    
    if ((archivo = fopen("texto.txt","r"))== NULL) {
        perror("la ruta del fichero es erronea");
    }
    
    //char letra = argv[1];
    int leo;
    leo = fgetc(archivo);
    
    while(leo!=EOF){
       
           printf("hola %s", leo);

    }
    
    
    



    return 0;
}
