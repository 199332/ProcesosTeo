#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*1. pedir un string por consola y escribirlos 4 primeros
     caracteres de ese string en un fichero ejer1.txt*/
    FILE* fichero = fopen("./ejer1.txt","w");
    char texto[100];
    //pedir datos por pantalla
    fprintf(stdout, "Escribe un mensaje: ");
    //recibir datos del teclado %s string
    scanf("%s", texto);
    //escribe la variable texto a partir del char 4, el tamaño de lo que le voy a pasar sizeof(char) va a ser un char y fichero
    // que es donde se guarda
    fwrite(texto, 4,sizeof(char), fichero);    
    /*./ indica el directorio actual*/
    //inserta un retorno de carro en el fichero
    putc('\n',fichero );
    
    
    fclose(fichero);
    return 0;
}
