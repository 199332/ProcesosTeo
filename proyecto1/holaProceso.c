#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    //int error;
   // error = system("ls");
    
    if (system("ls") == -1) {
        fprintf(stderr,"error ejecutando el comando...\n");
        
    }

    fprintf(stdout, "\nAhora con execl:\n\n");
    execl("/bin/ls", "ls", "-l", NULL);
    return 0;

    
}


