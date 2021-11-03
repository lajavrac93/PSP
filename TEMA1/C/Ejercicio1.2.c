#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * @lajavrac93 Ruben Carvajal Mesas
 * 
 * Desarrolla un programa en C que construya una tubería en la que 
 * el proceso padre envíe información al proceso hijo.
*/

int main()
{
    int fd[2];
    char buffer[10];
    pid_t pid;

    pipe(fd); //1

    pid = fork(); //2

    switch (pid)
    {
    case -1: //ERROR
        printf("NO SE HA PODIDO CREAR HIJO...");
        exit(-1);
        break;
    case 0: //HIJO
        
        printf("El proceso hijo lee ...\n");
        read(fd[0], buffer, 10);
        printf("%s",buffer);
        // printf("El proceso hijo escribe ...\n");
        // write(fd[1], "Saqué un 0\n", 11);
        break;
    default: //PADRE

        printf("El proceso padre escribe ...\n");
        write(fd[1], "Hola Hijo\n", 10);
        wait(NULL);
        // printf("El proceso padre lee ...\n");
        // read(fd[0], "Castigado\n", 10);
        
        break;
    }
}
