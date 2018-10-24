#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    //es un array con dos valores que equivaldrán a 0lectura 1escritura
    int pPadreHijo[2];
    int pHijoPadre[2];
    //crea la tuberia
    pipe(pPadreHijo);
    pipe(pHijoPadre);

    pid_t pid;
    pid = fork();
    //no hay problema porque las variables se llamen iguales porque uno es el padre1 y otra el hijo
    if (pid == 0) {//código hijo. espera que el padre le envíe 
        //cierro la escritura del pipe por el que recibo 
        close(pPadreHijo[1]);
        //cierro la lectura del pipe por el que envío
        close(pHijoPadre[0]);
        int recibido;
        read(pPadreHijo[0], &recibido, sizeof(int));
        printf("Hijo: Leído %d del pipe.\n", recibido);
        int mensaje = 3432;
        write(pHijoPadre[1],&mensaje,sizeof(int));
    }else{
        //cierro la escritura del pipe por el que recibo 
        close(pPadreHijo[0]);
        //cierro la lectura del pipe por el que envío
        close(pHijoPadre[1]);
        int mensaje = 123456;
        write(pPadreHijo[1],&mensaje, sizeof(int));
        int recibido;
        read(pHijoPadre[0], &recibido, sizeof(int));
        printf("Padre: Leído %d del pipe.\n", recibido);
        wait(NULL);
    }
    
    //esto lo ejecutan los dos
    return 0;
}

 