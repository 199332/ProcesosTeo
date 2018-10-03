/*3.- Pedir 2 strings por consola y escribirlos enteros (strlen)
en un fichero ejer3.txt, separándolos con 3 saltos de línea*/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // abrir archivo
    FILE* fichero = fopen("./ejer3.txt", "w");
    //variable para recibir los mensajes
    char mensaje[100];
    //int tamaño; no es necesario

    fprintf(stdout, "Vas a escribir dos mensajes");
    //escribir datos en el fichero
    for(size_t i = 0; i < 2; i++)
    {
        fprintf(stdout, "Escribe el mensaje: ");
        fscanf("%s", mensaje);
        //tamaño = strlen(mensaje);no es necesario

        fwrite(mensaje,sizeof(char),strlen(mensaje),fichero);
        putc('\n',fichero);
        
    }
    fclose(fichero);
    


    return 0;
}
