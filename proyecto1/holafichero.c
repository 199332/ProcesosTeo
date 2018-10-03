#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE* fichero = fopen("./hola.txt","w");
    char texto[]= "Hola mundo";
    fwrite(texto, 5,sizeof(char), fichero);
    //escribe la variable texto 5 caracteres 
    /*./ indica el directorio actual*/
    putc('\n',fichero );
    //esta dos lineas habren el fichero y cambian la primero linea 
    //letra por una J
    fseek(fichero , 0, SEEK_SET);
    putc('J', fichero);
    fclose(fichero);
    return 0;
}
