/*Pedir una serie de strings por parámetro (al menos 1) y guardarlos separados por salto
 de línea en un fichero de texto plano. Debéis usar la función malloc (o calloc) para 
 reservar el espacio de memoria que necesario para albergar todos los strings de los
  parámetros concatenados con \n.*/
   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>

int main(int argc, char const *argv[])
{
    //creo variable tipo file y abro el fichero con permisos de escritura
    FILE *archivoEjer10;    
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    if ((archivoEjer10 = fopen("ejer10.txt","w"))== NULL) {
        perror("la ruta del fichero es erronea");
    } 
    //variables que recibirán y almacenarán los datos pasado por argumento
    char *cadena1 = argv[1];
    char *cadena2 = argv[2];
    
    //variable para reservar memoria
    char *reserva;
    /*variable para almacenar el número de caracteres con los que vamos a calcular el tamaño
    de la memoria que se va a reservar con malloc */
    int contadorCaracteres = strlen(cadena1) + strlen(cadena2)+1;
    //printf("suma de cadenas %d\n",contadorCaracteres);
    //printf("%s\n",cadena1);
    /*para reservar la memoria creamos una variable tipo string a la que le indicamos el 
    tipo de dato que se va a guardar en este caso char(un casting) la función malloc que 
    multiplica el nº de caracteres por el tamaño de un char es este caso porque es lo que se
    va a guardar*/
    reserva=(char*)malloc(contadorCaracteres*sizeof(char));
    //concateno las cadenas con el salto de línea en la memoria almacenada
    reserva=strcat(reserva,cadena1);
    //debe ir entre "" no ''(con '' lo recibe como entero) 
    reserva=strcat(reserva,"\n");
    reserva=strcat(reserva,cadena2);
    printf("%s\n",reserva);
    //escribo en el fichero las dos cadenas recibidas como argumento separadas por \n
    fprintf(archivoEjer10,"%s\n%s",cadena1,cadena2);
    //cierro el fichero, para cerrar se usa la función y se le pasa el fichero no se 
    //necesita igualar
     //fclose(archivoEjer2);
    if (fclose(archivoEjer10)!=0)  {
    perror("No se ha podido cerrar el fichero.\n");	
  }
    return 0;
}