/*Pedir 3 string por consola y escribir los 5 primeros caracteres
 de cada strings en un fichero ejer2.txt, separándolos con saltos de línea.*/
 #include <stdio.h>

int main(int argc, char const *argv[])
{
    //creo variable tipo file y abro el fichero con permisos de escritura
    FILE *archivoEjer2;
    //archivoEjer1 = fopen("ejercicio2.txt","w");
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    if ((archivoEjer2 = fopen("ejer2.txt","w"))== NULL) {
        perror("la ruta del fichero es erronea");
    } 
    //bucle que pedirá las 5 cadenas por consola y las irá añadiendo
    for(int i = 0; i < 5; i++)    {
        //pido los mensajes
        fprintf(stdout, "Escribe el mensaje nº %d, solo los 4 primero caracteres se almacenaran en el fichero: ",i+1);
    
        //para recoger cadenas de texto se usar char *variable
        //char *nombre; no lo uso porque me da problemas al escribir el fichero
        char nombre[1000];
        //stdin para recoger texto por consola, se debe poner el simbolo & para leer    
        fscanf(stdin,"%s",&nombre);
        //para mostrar se debe usar también el & antes de la variable y %s para string y %c carácteres
        //stdout para mostrar por pantalla
        /*como no he usado el char *nombre no se necesita poner & para leer carácter a carácter*/
        //fprintf(stdout,"Hola %s.\nTu inicial es %c\n",&nombre,nombre[0]);
        /*recorro el array tipo char para escribir solo los 4 primero caracteres*/
        for(int i = 0; i < 4; i++)    {
            fputc(nombre[i], archivoEjer2);
        } 
        //para añadir un salto de línea debe ir entre comillas simples
        fputc('\n', archivoEjer2);
    }   
    //cierro el fichero, para cerrar se usa la función y se le pasa el fichero no se 
    //necesita igualar
     //fclose(archivoEjer2);
    if (fclose(archivoEjer2)!=0)  {
    perror("No se ha podido cerrar el fichero.\n");	
  }
    return 0;
}