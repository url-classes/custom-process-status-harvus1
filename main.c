#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
    
    printf("Bienvenidos al Programa\n");
    printf("Process Type                  PID              PPID              Time\n");
    printf("--------------------------------------------------------------------------------");
    printf("\n");
    
    int fork_result;
    fork_result = fork();
    fork_result = fork();
    fork_result = fork();

    if (fork_result >= 1)
    {
    time_t tiempo;
    struct tm *timeformat;
    time(&tiempo);
    timeformat = localtime(&tiempo);
        printf("System Process             %d               %d                 %s", getpid(), getppid(), asctime (timeformat));
        
    }
    else if (fork_result == 0)
    {
    time_t tiempo;
    struct tm *timeformat;
    time(&tiempo);
    timeformat = localtime(&tiempo);
       
        printf("System Process             %d               %d                 %s", getpid(), getppid(), asctime (timeformat));
    }
    else
    {
        printf("Error al crear el proceso\n");
    }
    return 0;
}