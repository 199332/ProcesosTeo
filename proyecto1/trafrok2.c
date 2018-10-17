#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
 
 int main(int argc, char const *argv[])
 {
     //esta varaible es como un int

 pid_t pid; 

 int a = 100;
 fprintf(stdout,"soy el proceso principal mi pid es: %d\n", getpid());
 //se realiza el programa dos veces porque a partir del fork se duplica
 /*por eso cuando pasa con el hijo le da valor a la variable a y cuando se ejecuta
 con el padre se repite el proceso*/
 pid = fork();
 
 if (pid == 0) {
    printf("Hola soy el hijo\n\tmi pid es: %d\n\t mi padre es: %d\n",getpid(),getppid());
    printf("Imprime a %d\n",--a);
    sleep(1);
    pid_t pidNieto;
    if (pidNieto =fork() ==-1) {
       exit(-1);       
    }
    
    if (pidNieto == 0) {//soy el nieto
        printf("Hola soy el nieto\n\tmi pid es: %d\n\t mi padre es: %d\n",getpid(),getppid());
    }
    else
    {//vuelve a ser el hijo
        wait(NULL);
    }
    
    
    printf("Soy un proceso mi pid es: %d\n",getpid());
    

 }else 
 if (pid == -1) {
    fprintf(stderr, "se a producido un error");
    exit(-1);
 } 
 else
 {
    printf("Hola soy el padre %d, el hijo que he creado es %d\n",getpid(),pid);
    printf("Imprime a %d\n",--a);
    wait(NULL);
    fprintf(stderr, "El hijo a acabado\n");
    
 }
 printf("Imprime a %d\n",++a);
 //sleep(1);esta función es para que espere y veamos el proceso 
 return 0;    
 }
 
