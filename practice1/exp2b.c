#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid = fork();

    if(pid < 0)
    {
        fprintf(stderr, "\nFork failed, exiting...");
        exit(-1);
    }
    else if(pid == 0) {
        printf("\nI am the child, return from fork = %d", pid);
    }
    else{
        printf("\nI am the parent, return from fork child pid= %d", pid);
        printf("\nParent id= %d", getpid());
        printf("\nParent's parent process id= %d", getppid());
        exit(0);
    }

    return 0;
}