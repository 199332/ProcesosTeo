/*Escribir 2 enteros cualesquiera en un fichero ejer4.dat*/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //creo variable tipo file y abro el fichero con permisos de escritura
    FILE *archivoEjer4;
    //archivoEjer1 = fopen("ejercicio5.txt","w");
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    //fichero con permisos de escritura wb la b es porque es de tipo binanio
    if ((archivoEjer4 = fopen("ejer4.dat","wb"))== NULL) {
        perror("la ruta del fichero es erronea");
    } 
    //bucle que pedirá los 2 enteros por consola y los irá añadiendo
    for(int i = 0; i < 2; i++)    {
        //pido los mensajes
        fprintf(stdout, "Escribe el mensaje nº %d, se almacenará completo en el fichero: ",i+1);
        
        int numero;        
        //stdin para recoger texto por consola, se debe poner el simbolo & para leer    
        fscanf(stdin,"%d",&numero);//ESTA FUNCIÓN DA PROBLEMAS PORQUE AL INTRODUCIR CARACTERES
        char salto = '\n';
        /*numero es la dirección de la variable que queremos escribir en el fichero indicado por
        la variable archivoEjer4. En tamaño debemos indicar el tamaño en bytes de la variable
        que vamos a escribir en el fichero. Para obtener el tamaño de una variable int podemos
        usar el operador sizeof y para obtener el tamaño de una cadena (char) la función strlen. 
        Después indicamos cuántos elementos del tipo tamaño vamos a escribir.¡Cuidado!, 
        veces no es el número de veces que queremos que se escriba repetidamente el 
        dato indicado en archivoEjer4*/
        fwrite(&numero,sizeof(numero),1,archivoEjer4);
        //fwrite(&salto,sizeof(salto),1, archivoEjer4);
    }   
    //cierro el fichero, para cerrar se usa la función y se le pasa el fichero no se 
    //necesita igualar
     //fclose(archivoEjer);
    if (fclose(archivoEjer4)!=0)  {
    perror("No se ha podido cerrar el fichero.\n");	
  }
    return 0;
}