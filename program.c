#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[], char *envp[])
{
    int pid ; // identificador de processo

    pid = fork () ; // replicação do processo

    if ( pid < 0 ) // fork funcionou?
    {
        perror ("Erro no fork: ") ; // não, encerra este processo
        exit (-1) ;
    }
    else // sim, fork funcionou
    if ( pid > 0 ) // sou o processo pai?
    {
        wait (0) ; // sim, vou esperar meu filho
    }
    else // não, sou o processo filho
    {
        // carrega outro código binário para executar
        execve ("/bin/date", argv, envp) ;
        perror ("Erro no execve: ") ; // execve não funcionou, então esta linha será executada
        // Se execve falhar, o filho continuará e imprimirá "Tchau !" abaixo.
    }
    printf ("Tchau !\n") ;
    exit(0) ; // encerra este processo
}