#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * 
 * @lajavrac93 Rubén Carvajal Mesas
 *  
 * Se crea un proceso padre que tenga dos procesos hijos;
 * Los procesos deben modificar la misma variable de tipo entero;
 * 
 * */
int main(void)
{
    pid_t pid_hijo1, pid_hijo2, pid;
    int variableEntera = 0;
    pid = fork();

    if (pid == -1)
    { //se ha producido algún error
        /**
        * Codigo exclusivo del padre
        * */
        printf("Se ha producido un error y no se ha podido crear el proceso hijo1\n");
        exit(pid);
    }
    if (pid == 0)
    { //no hay error, y como el valor es 0 estamos en el proceso hijo
        /**
        *  Codigo exclusivo del hijo1
        * */
        printf("Estamos en el proceso hijo1\n");
        printf("El PID del proceso padre es %d\n",
               getppid());
        printf("Mi PID es el %d\n", getpid());
        variableEntera = 1;
        printf("A=> %d \n", variableEntera);
    }
    else
    { //estamos en proceso padre, el valor de pid>0
        //bloquea al procesa padre y espera al proceso hijo
        /**
        * Codigo exclusivo del padre
        * */
        printf("----------------------------------------------------------\n");
        printf("Estamos en el proceso padre, mi PID es %d\n el PID de mi padre es %d\n", getpid(), getppid());
        printf("Mi proceso hijo1 %d ha terminado\n", pid);
    }
    if (pid != 0)
    {

        pid = fork(); //hijo2

        if (pid == -1)
        { //se ha producido algún error
            printf("Se ha producido un error y no se ha podido crear el proceso hijo1\n");

            exit(pid);
        }
        if (pid == 0)
        { //no hay error, y como el valor es 0 estamos en el proceso hijo
            printf("Estamos en el proceso hijo2\n");
            printf("El PID del proceso padre es %d\n",
                   getppid());
            printf("Mi PID es el %d\n", getpid());
            variableEntera = 2;
            printf("A=> %d \n", variableEntera);
        }
        else
        { //estamos en proceso padre, el valor de pid>0
            //bloquea al procesa padre y espera al proceso hijo
            wait(NULL);
            printf("----------------------------------------------------------\n");
            printf("Estamos en el proceso padre, mi PID es %d\n el PID de mi padre es %d\n", getpid(), getppid());
            printf("Mi proceso hijo2 %d ha terminado\n", pid);
        }
    }
    printf("A Final=> %d \n", variableEntera);
    exit(0);
}
