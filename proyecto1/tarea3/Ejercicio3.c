/*Pedir 2 strings por consola y escribirlos
 enteros (strlen) en un fichero ejer3.txt, separándolos con 2 saltos de línea.*/
 #include <stdio.h>
 #include <string.h>

int main(int argc, char const *argv[])
{
    //creo variable tipo file y abro el fichero con permisos de escritura
    FILE *archivoEjer3;
    //archivoEjer1 = fopen("ejercicio3.txt","w");
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    if ((archivoEjer3 = fopen("ejer3.txt","w"))== NULL) {
        perror("la ruta del fichero es erronea");
    } 
    //bucle que pedirá las 2 cadenas por consola y las irá añadiendo
    for(int i = 0; i < 2; i++)    {
        //pido los mensajes
        fprintf(stdout, "Escribe el mensaje nº %d, se almacenará completo en el fichero: ",i+1);
        //para recoger cadenas de texto se puede usar char *variable
        //char *nombre; no lo uso porque me da problemas al escribir el fichero
        char nombre[1000];        
        //stdin para recoger texto por consola, se debe poner el simbolo & para leer    
        //fscanf(stdin,"%s",&nombre);//ESTA FUNCIÓN DA PROBLEMAS PORQUE AL INTRODUCIR CARACTERES
        //POR PANTALLA CUENTA LOS ESPACIOS COMO QUE EMPIEZA UNA NUEVA CADENA
        //esta función evita el problema de los espacios en una cadena de caracteres
        fgets(nombre,1000,stdin);//1000 es el tope de caracteres que puede leer y stdin el msg por pantalla
        //recojo la longitud del mensaje que usa más abajo en el bucle para escribir todo el 
        //mensaje en el fichero
        int longitud = strlen(nombre);
        printf("longitud del mensaje nº %d = %d\n", i, longitud);
        //para mostrar se debe usar también el & antes de la variable y %s para string y %c carácteres
        //stdout para mostrar por pantalla
        /*como no he usado el char *nombre no se necesita poner & para leer carácter a carácter*/
        
        /*recorro el array tipo char para escribir solo los todos caracteres uso el resultado
        de la longitud del mensaje que obtube con strlen*/
        for(int i = 0; i < longitud; i++)    {
            fputc(nombre[i], archivoEjer3);
            //fwrite(&nombre[i],1,sizeof(nombre), archivoEjer3);
        } 
        //para añadir un salto de línea debe ir entre comillas simples
        fputc('\n', archivoEjer3);
    }   
    //cierro el fichero, para cerrar se usa la función y se le pasa el fichero no se 
    //necesita igualar
     //fclose(archivoEjer3);
    if (fclose(archivoEjer3)!=0)  {
    perror("No se ha podido cerrar el fichero.\n");	
  }
    return 0;
}