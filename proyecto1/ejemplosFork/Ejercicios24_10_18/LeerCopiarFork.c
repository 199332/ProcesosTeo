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
    //variable para saber en el fork si es el hijo o el padre
    pid_t pid;
    
     //creo una variable de tipo FILE con la que habriré el archivo
    FILE *archivo;
    FILE *archivoNuevo;
    archivo = fopen("texto.txt","r");
    archivoNuevo = fopen("texto_fork.txt","w"); 
    
  //comienzo los dos procesos
    pid = fork();
    
   if (pid == 0) {//PROCESO HIJO recibe caracter y escribe en el fichero nuevo
    printf("Hola soy el hijo %d\n",getpid());
    //espera a que se ejecute el proceso padre 
     wait(NULL);       
    //esta variable va ir almacenando cada caracter que se va a leer
    //printf("la letra clave es: %c\n",letraClave);
    char leer;
    char* texto2;
    read(padreHijo[0], texto2, sizeof(int));
    printf("Hijo: Leído %c del pipe.\n", leer);
    
    for(int i = 0; i < sizeof(texto2); i++)
    {
         printf("%c\n", leer);
            fputc(leer, archivoNuevo);
    }
    /*
    //leo el fichero dandole valor a la variable leer y cuando llega al final 
    //EOF  sale del bucle
    while(leer != '1'){
        //muestro por pantalla cada caracter
        //printf("%c", leer);
        
            printf("%c\n", leer);
            fputc(leer, archivoNuevo);
            //wait(NULL);
            sleep(1);
    }
    //sleep(1);
   */
//fin proceso hijo
 }else if (pid == -1) {
    fprintf(stderr, "se a producido un error");
    exit(-1);
 } else {//PROCESO PADRE lee y envia al hijo el caracter
    printf("Hola soy el padre %d, el hijo que he creado es %d\n",getpid(),pid);
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
    if (archivo == NULL) {
        perror("la ruta del fichero es erronea");
    }
    char leer;
    int contador =0;
    int tamano =0;  
    //leo el fichero dandole valor a la variable leer y cuando llega al final 
    //EOF  sale del bucle
    leer=fgetc(archivo);
    while((leer=fgetc(archivo))!=EOF){
        //muestro por pantalla cada caracter
        printf("%c lee el caracter\n", leer);
        //texto[contador] = leer;
        tamano++;        
         //wait(NULL);
         //sleep(1);
        }
        char texto[tamano+1];
         while((leer=fgetc(archivo))!=EOF){
        //muestro por pantalla cada caracter
        
        texto[contador] = leer;
        printf("primer caracter = %c\n",texto[contador]);
        contador++;        
         //wait(NULL);
         //sleep(1);
        }
        printf("acaba el segundo while\n");
        printf("tamaño array = %d\n",sizeof(texto));
        //printf("primer caracter = %c\n",texto);
        for(int i = 0; i < sizeof(texto); i++){
        
        
             printf("%c lee el el array\n", texto[i]); 
        
                
        }
           
         
        //sizeof igual es char
        write(padreHijo[1],&texto,sizeof(int));
 }//fin padre
       
    fclose(archivo);
    fclose(archivoNuevo);

    return 0;
}
