#include <stdio.h>
#include <unistd.h>
#include <signal.h>
//definimos una señal
void tratarSenyal(int);

int main(int argc, char const *argv[])
{
    //
    signal(SIGUSR1,tratarSenyal);//mata el proceso
    signal(SIGUSR2,tratarSenyal);//estas líneas se usan para llamar a la alarma
    signal(SIGINT,tratarSenyal);//sigint es ctrl+c el número de señal sigint es 2
    int i = 0;
    while (i<100){
        printf("%d\n",++i);
        sleep(1);//tiempo que espera para mostrar cada número
    }
    return 0;
}
//a este metodo no se le pasa el entero porque signal internamente lo hace
void tratarSenyal(int numSenyal){
    printf("He recibido una señal con número %d\n",numSenyal);
    fflush(stdout);//es para que imprima justo en el momento porque printf no se ejecuta en un momento determinado
    sleep(1);
}