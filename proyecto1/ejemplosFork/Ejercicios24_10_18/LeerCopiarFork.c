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
    archivoNuevo = fopen("texto_fork.txt","w"); 
    
  //comienzo los dos procesos
    pid = fork();
    
   if (pid == 0) {//PROCESO HIJO recibe caracter y escribe en el fichero nuevo
    //espera a que se ejecute el proceso padre 
     wait(NULL);
     //muestra el identificador del hijo
     printf("Hola soy el hijo %d\n",getpid());     
    //array que va almacenar el array que le he enviado por la tubería
    char texto2[1000];
    //leo la tubería, padreHijo[0]para leer, sizeof(texto2) indica el tamaño del array
    read(padreHijo[0], texto2, sizeof(texto2));
    //muestra el mensaje recibido
    printf("Hijo: Leído %s del pipe.\n", texto2);
    //escribo el fichero caracter a caracter y cuando leo el caracter añadido al final
    //dejo de escribir
    for(int i = 0; i < sizeof(texto2); i++) {       
        //condición para salir del final del fichero
        if (texto2[i]=='^') {
            break;
        }
        //muestra los caracteres que va leyendo uno a uno
        //printf("%c\n", texto2[i]);
        //escribo el nuevo fichero pero NO añado el caracter que añadi para saber el fin del ficheero  
        fputc(texto2[i], archivoNuevo);      
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
    int contador =0;//para ir moviendome en el array tipo char
      
    char texto[1000];//va a recoger los caracteres del fichero
    //leo el fichero dandole valor a la variable leer y cuando llega al final 
    //EOF  sale del bucle    
    while((leer=fgetc(archivo))!=EOF){
        //muestro por pantalla cada caracter
        printf("%c lee el caracter\n", leer);
        //voy rellenando el array con los caracteres
        texto[contador] = leer;
        //compruebo que se añaden correctamente
        //printf("primer caracter = %c\n",texto[contador]);
        contador++;         
        }
        //le añado este caracter para identificar el final del fichero
        texto[contador]= '^';
        
        printf("acaba el while\n");
        //muestra el tamaño del array
        printf("tamaño array = %d\n",sizeof(texto));
        //imprime el array como un string
        printf("primer caracter = %s\n",texto);
        /*prueba para ver que el array se ha escrito bien
        for(int i = 0; i < sizeof(texto); i++){            
            if (texto[i]=='^') {
              break;
            }                
            printf("%c lee el el array\n", texto[i]);
        }*/       
        //escribo a través de la tubería y lo envío al hijo
        //padreHijo[1] lado de la tubería para escribir
        //&texto es el mensaje que envío y sizeof(texto)el tamaño del mensaje
        write(padreHijo[1],&texto,sizeof(texto));
 }//fin padre
    //cierro los ficheros 
    fclose(archivo);
    fclose(archivoNuevo);

    return 0;
}
