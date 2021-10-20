#include <studio.h>
#include <stdlib.h>

//codigo principal

void main(){
    printf("Llamando a varios comandos desde la system()\n");
    printf("Contenido del directorio actual\n");
    system("ls -l");
    printf("Enviando el contenido del directorio actual a un fichero de texto\n");
    system("ls -l > salida.txt");
    printf("Se ha creado el fichero salida.txt con gedit\n");
    system("Se abre el fichero salida.txt con gedit\n");
    system("gedit salida.txt");
    printf("\nProbando un comando erróneo: %d",system("cop"));
    printf("\nPrograma finalizado\n");
}
