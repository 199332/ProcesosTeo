/*Leer 2 enteros del fichero ejer4.dat sumarlos y 
guardar el resultado en texto plano en ejer5.txt.*/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //creo variable tipo file y abro el fichero con permisos
    FILE *archivoEjer5;
    FILE *archivoNuevo;   
    //con este if abro el documento de texto en la variable y compruebo que no este vacío o
    // que no lo encuentre
   //aunque el fichero sea tipo .dat rb se puede abrir con rt lectura de texto man fopen
    if ((archivoEjer5 = fopen("ejer4.dat","rt"))== NULL) {
        perror("la ruta del fichero es erronea");
    }
     //fichero con permisos de escritura wt la t es porque es de tipo texo
    if ((archivoNuevo = fopen("ejer5.txt","wt"))== NULL) {
        perror("la ruta del fichero es erronea");
    }
    
  int suma = 0;  
  //Esta variable va a ir almacenando los resultados de lectura/escritura. 
  int resultado;/*se puede usar una variable de tipo size_t, estás variables se usan para
  comprobar que si ha leido un datos (devuelve 1) y se no lee nada devuelve0*/
  
  // Se lee número por número.
  int num;
  int contador = 0;
  while (!feof(archivoEjer5))  {
    contador++;
    //si(línea 34) ha leido un datos (devuelve 1) y se no lee nada devuelve0, y en fread almacena
    //el entero que lee lo almacena en la variable num
    resultado = fread(&num, sizeof(int), 1, archivoEjer5);
    //printf(" el valor de resultado es: %d\n",resultado);
    //cuando el valor sea 0(distinto de 1) sale del bucle
	  if (resultado != 1)	{
		  break;
	  }
     printf("El valor %d leido es: %d\n", contador, num);
	   suma = suma + num;     
  } 
    //uso fprintf para escribir el resultado en el nuevo fichero. Se usa con un string
    //para que acepte suma como char
    fprintf(archivoNuevo,"%d", suma);
    
    //fwrite(&conversion, sizeof(conversion),1,archivoNuevo);
  if (ferror(archivoEjer5)!=0)  {
	  printf("Ha ocurrido algún error en la lectura de números.\n");
  }  else  {
	  printf("La suma de los números leídos es: %d\n",suma);   
  }
    //fclose(archivoEjer5);
/*fclose() cierra  el  fichero y devuelve 1 si el cierre es correcto y 0 si es incorrecto. */
    if (fclose(archivoEjer5)!=0)  {
    perror("No se ha podido cerrar el fichero.\n");	
  }
    return 0;
}