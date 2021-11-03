#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * @lajavrac93 Ruben Carvajal Mesas
 * 
 * Ejemplo con el cual vemos la creación y manejo de hilos de proceso 
*/

//ABUELO-HIJO-NIETO

int main()
{
  /**
   * Creamos la nomenclatura de los distintos hilos
  */
  pid_t pid, hijo_pid, pid2, hijo_pid2;
  /**
   * Creamos un nuevo proceso y lo establecemos como pid lo que causa 
   * que el proceso actual cambie de hilo 
  */
  pid = fork(); //Soy el  Abuelo, se crea el Hijo

  if (pid == -1) //Ha ocurrido un error
  {
    printf("No se ha podido crear el proceso hijo...");
    /**
    * Cerramos el programa con errores
   */
    exit(-1);
  }

  if (pid == 0) //Nos encontramos en Proceso hijo  {
  {
    /**
    * Creamos un nuevo proceso y lo establecemos como pid2 lo que causa 
    * que el proceso actual cambie de hilo 
    */
    pid2 = fork(); //Soy el Hijo, se crea al Nieto
    switch (pid2)
    {
    case -1: // error
      printf("No se ha podido crear el proceso hijo en el HIJO...");
      /**
    * Cerramos el programa con errores
   */
      exit(-1);
      break;
    case 0: // proceso hijo
      printf("\t\tSoy el proceso NIETO %d; Mi padre es = %d \n", getpid(), getppid());
      break;
    default: // proceso padre
      hijo_pid2 = wait(NULL);
      /**
         * Muestra informacion por pantalla
        */
      printf("\tSoy el proceso HIJO %d, Mi padre es: %d.\n",
             getpid(), getppid());
      printf("\tMi hijo: %d terminó.\n", hijo_pid2);
    }
  }
  else //Nos encontramos en Proceso padre
  {
    hijo_pid = wait(NULL); //espera la finalización del proceso hijo
    /**
         * Muestra informacion por pantalla
        */
    printf("Soy el proceso ABUELO: %d, Mi HIJO: %d terminó.\n", getpid(), pid);
  }
  /**
    * Cerramos el programa sin errores
   */
  exit(0);
}