/*Transformar el texto ejer5.txt a entero y escribirlo en un fichero binario ejer6.dat*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //creo variable tipo file y abro el fichero con permisos 
    FILE *archivoEjer6;
    FILE *archivoNuevo;   
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
   //aunque el fichero sea tipo .dat rb se puede abrir con rt lectura de texto man fopen
    if ((archivoEjer6 = fopen("ejer5.txt","rt"))== NULL) {
        perror("la ruta del fichero es erronea");
    }
     //fichero con permisos de escritura wt la t es porque es de tipo texo
    if ((archivoNuevo = fopen("ejer6.dat","wb"))== NULL) {
        perror("la ruta del fichero es erronea");
    }
    //variable para leer el fichero y un apuntador para la funcion strtol
    char numeroLetras[10], *final;    
    int num;    
    fscanf(archivoEjer6, "%s" , numeroLetras);
 	printf("Lectura del fichero .txt es %s\n",numeroLetras);    
    /*la función strtol convierte de string a long(o char a int, tb funciona) se le pasa
    el string, un apuntado tipo char y 0 que es la base a la que queremos convertir*/
    num = strtol( numeroLetras, &final, 0 );
    /*muestro el número leido del archivo de texto como entero*/
    printf("el entero es %d\n",num);
    //escribo el nº como entero en un fichero .dat en bits
    fwrite(&num,sizeof(num),1,archivoNuevo);
/*fclose() cierra  el  fichero y devuelve 1 si el cierre es correcto y 0 si es incorrecto. */
    if (fclose(archivoEjer6)!=0)  {
    perror("No se ha podido cerrar el fichero.\n");	
  }
    return 0;
}