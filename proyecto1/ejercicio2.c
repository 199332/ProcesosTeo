#include <stdio.h>

/*2.- pedir 3 string por consola y escribir los 5 primeros 
caracteres de esos string en un fichero ejer2.txt, separandolos con saltos de linea*/
int main(int argc, char const *argv[])
{
    FILE* fichero = fopen("./ejer2.txt","w");//se puede usar "a"
char mensaje[100];

//pedir datos por pantalla
 fprintf(stdout, "Vas a escribir 3 mensajes");
for(size_t i = 0; i < 3; i++)
{
   fprintf(stdout, "\nEscribe el mensaje: ");
   scanf("%s", mensaje);
   fwrite(mensaje, 5, sizeof(char),fichero);
   putc('\n', fichero); 
}
fclose(fichero);

    return 0;
}



