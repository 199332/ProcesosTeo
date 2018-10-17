#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    /* code */
    printf("Hola\n");
    fork();
    printf("Hola2\n");

    sleep(1);
    return 0;
}

