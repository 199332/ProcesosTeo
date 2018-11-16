#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include "libPractica.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <time.h>


bool finalPrograma = false;
pid_t pid;

#define RUTA_PIPE "/tmp/tub.pipe"
#define RUTA_LOG "./log.txt"
#define TAM_MAX 100

void tratarCtrlC(int);
void tratar2oCtrlC(int);

int main(int argc, char const *argv[])
{
  int pipe = abrirPipe(RUTA_PIPE);
  //leo el pid
  read(pipe,&pid,sizeof(pid_t));
  printf("El PID del emisor es: %d\n", pid);
  char* buffer;
  signal(SIGINT,tratarCtrlC);
  //reserva de memoria es igual char* buffer[100];
  buffer = (char*) malloc(TAM_MAX);
  //abro el fichero con a para añadir cosas en txt
  FILE* registro = fopen(RUTA_LOG,"a"); 
  // variable para controlar el error del lectura
  int bytesLeidos;
  while(!finalPrograma){
    bytesLeidos = read(pipe,buffer,TAM_MAX);
    //por si hay un problema de lectura
    if( bytesLeidos == -1){
      perror("Error en el read");
      exit(-2);
    }
    //
    if( bytesLeidos != 0){
      char fechaHora[24];
      //funcion para mostrar la hora en libPractica.c
      rellenarFechaYHora(fechaHora);
      //registro es elfichero, cadena char, y buffer el tamaño
      fprintf(registro,"%s %s\n",fechaHora,buffer);
      fprintf(stderr,"%s %s\n",fechaHora,buffer);
    }
  }
  fclose(registro);
  close(pipe);
  free(buffer);//libero la memoria HAY QUE HACERLO SIEMPRE QUE SE USE
  return 0;
}

void tratarCtrlC(int senyal){
  //kill va a llamar a una señal
  kill(pid,SIGUSR1);
  printf("Vuelva a pulsar Ctrl-C para salir");
  //para que salga despues de la señal se usa fflush
  fflush(stdout);

  signal(SIGINT,tratar2oCtrlC);
}

void tratar2oCtrlC(int senyal){
  printf("Saliendo...\n");
  fflush(stdout);
  finalPrograma = true;
}
