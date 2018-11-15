#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{  
    //variable para crear la tubería el 0 lee y el 1 escribe 
    int padreHijo[2];
    //creo tuberia para mandar los datos
    pipe(padreHijo);
    //variable para saber en el fork cual es el id del hijo y del padre
    pid_t pid;
    
     //creo una variable de tipo FILE con la que habriré los archivos
    FILE *archivo;
    FILE *archivoNuevo;
    //abro los archivos y les doy permisos
    //archivo = fopen("texto.txt","r");
    archivo = fopen(argv[1],"r");
    archivoNuevo = fopen("texto_fork2.txt","w"); 
    
  //comienzo los dos procesos
    pid = fork();
    
   if (pid == 0) {//PROCESO HIJO recibe caracter y escribe en el fichero nuevo
    //espera a que se ejecute el proceso padre 
     wait(NULL);
     
     //muestra el identificador del hijo
     printf("Hola soy el hijo %d\n",getpid());     
    //array que va almacenar el array que le he enviado por la tubería
    char texto2;
    //leo la tubería, padreHijo[0]para leer, sizeof(texto2) indica el tamaño del array
    read(padreHijo[0], &texto2, sizeof(int));
    //compruebo dentro de un bucle cuando manda el final del fichero y voy leyendo y escribiendo
    //caracter a caracter
    while(texto2!=EOF){   
    //muestra el mensaje recibido
    printf("Hijo: Leído %c del pipe.\n", texto2);
    //escribo el caracter en el fichero
    fputc(texto2, archivoNuevo);
    //leo la tubería
    read(padreHijo[0], &texto2, sizeof(int));
    //lo para un segundo para que vaya al proceso padre
    sleep(1);
    }
//fin proceso hijo
 }else if (pid == -1) {//si no se consigue crear el fork se muestra el siguiente error y se finaliza todo
    fprintf(stderr, "se a producido un error");
    exit(-1);
 } else {//PROCESO PADRE lee y envia al hijo los caracteres del fichero
    //muestra el identificador del padre
    printf("Hola soy el padre %d, el hijo que he creado es %d\n",getpid(),pid);
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    if (archivo == NULL) {
        perror("la ruta del fichero es erronea");
    }
    char leer;//variable para leer caracter a caracter
    //leo el fichero hasta el final caracter a caracter
    while((leer=fgetc(archivo))!=EOF){
        //muestro por pantalla cada caracter
        printf("%c lee el caracter\n", leer);
        
        //escribo a través de la tubería y lo envío al hijo
        //padreHijo[1] lado de la tubería para escribir
        //&texto es el mensaje que envío y sizeof(texto)el tamaño del mensaje
        write(padreHijo[1],&leer,sizeof(leer));
        //lo para para que vaya al hijo y lea y escriba el fichero
        sleep(1);         
        }
        //leo el final EOF y se lo mando para que el hijo sepa que es el final
        //le añado este caracter para identificar el final del fichero
        write(padreHijo[1],&leer,sizeof(leer));
        //vuelvo a pararlo para que vaya al hijo
        sleep(1);       
        printf("acaba el while del padre\n");      
 }//fin padre
    //cierro los ficheros 
    fclose(archivo);
    fclose(archivoNuevo);

    return 0;
}
