#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * @lajavrac93 Ruben Carvajal Mesas
 * 
 * Desarrolla un programa en C en el que se haya definido una variable
 * entera a la que se dará el valor 10. Se creará un proceso hijo, el
 * proceso padre aumentará la variable en 4 unidades y el hijo le restará
 * 6. Se debe mostrar el valor de la variable en el proceso padre antes
 * de crear el proceso hijo, mostrar la variable una vez modificada en el
 * proceso padre y también hay que mostrar la variable en el proceso hijo
 * una vez modificada. Los valores de las variables que deben aparecer son:
 * 10, 4 y 14.
*/

int main()
{
    //Nombramos los procesos
    pid_t pid;
    //Creamos y establecemos la variable
    int variable = 10;
    //Mostramos la variable antes de crear al hijo
    printf("Variable antes de crear al hijo= %d\n", variable);
    //creamos al hijo
    pid = fork();
    switch (pid)
    {
    case -1:
        /*
        * En caso de error en la creación del hijo, mandaremos un
        * mensaje al usuario y terminaremos el programa.
        **/
        printf("El hijo no pudo ser creado\n");
        exit(-1);
        break;
    case 0:
        /**
         * El hijo modifica la variable y la muestra junto a un mensaje.
         **/
        variable -= 6;
        printf("Soy el hijo y la variable ahora es %d\n", variable);
        break;
    default:
        //el padre espera a que al hijo
        pid = wait(NULL);
        /**
         * El padre modifica la variable y la muestra junto a un mensaje 
         **/
        variable += 4;
        printf("Soy el padre y la variable ahora es %d\n", variable);
        break;
    }
    //fin del programa
    exit(0);
}