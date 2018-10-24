#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    FILE* fichero

    fichero = fopen("./hola.txt","r");
    
    if (fichero == NULL) {
        //la función perror no muestra el mensaje que le pasamos
        //y el mensaje del error
        perror("Error abriendo el fichero");
        /*para imprimir un error se usa stderr porque si no puede dar problemas de ejecución
        la línea de abajo nos muestra el número de error (errno) y después en string strerror(errno)
        el mensaje es el mismo que la línea de arriba*/
        fprintf(stderr,"Código de error %d. Texto: %s\n", errno, strerror(errno));
        //__FILE__ es una macro en c, nos dice el fichero que ha fallado
        fprintf(stderr,__FILE__,": Código de error %d. Texto: %s\n", errno, strerror(errno));
        
        fprintf(stderr,"%s: línea %d: Código de error %d. Texto: %s\n"
                    ,__FILE__,__LINE__, errno, strerror(errno));
    }
    
    return 0;
}
