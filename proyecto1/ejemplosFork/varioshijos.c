#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
 
 int main(int argc, char const *argv[])
 {
   
   if (argc != 2) {//son argumentos que se le va a pasar en la linea de abajo
       printf("Uso del programa:\n\t %s num_hijos", argv[0]);
       exit(-1);
   }
   int num_hijos = atoi(argv[1]);//atoi pasa de string a entero
   int pid_hijo;
   
   for(int i = 0; i < num_hijos; i++)   {
       pid_hijo = fork();
       
       if (pid_hijo == 0) {
           printf("HIJO %3d: hola\n",i);//%3d cubre huecos si el número tiene menos de 3 cifras
           return 0;
       }       
   }
   
   for(int i = 0; i < num_hijos; i++)   {
       wait(NULL);//hay un wait de todos los hijos
       printf("PADRE %3d: Un hijo ha acabado\n",i);
   }
   
   
   
 
 return 0;    
 }
 
