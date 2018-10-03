#include <stdio.h>
int main(int argc, char const *argv[])
{
    int entero = 125;
    FILE* fichero = fopen("./escribirEntrero.txt","wb");
    fwrite(&entero,sizeof(int),1,fichero);
    return 0;
}
