#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void tratarAlarm(int);

int main(int argc, char const *argv[])
{
    signal(SIGALRM,tratarAlarm);/*es una funcion que es necesaria para llamar a la señal, que necesita
    que se le indique el tipo de alarma y el metodo para que devuelva el número de alarma*/

    int i = 0;
    while (i<100){
        printf("%d\n",++i);
        sleep(1);//tiempo que espera para mostrar cada número
    }

    return 0;
}
//a este metodo no se le pasa el entero porque signal internamente lo hace
void tratarAlarm(int numSenyal){
    printf("Alarma")
}