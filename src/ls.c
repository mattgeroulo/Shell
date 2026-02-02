
#include "syscall.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ls.h"
void ls( char* argv[]){
    (void)argv;
    
    #if DEBUG
        printf("input is ls\n");
    #endif
    //fork to a child process, set child process fd to this process fd, execute ls
    pid_t pid = fork();
    //both processes run from here, use pid value to determine who is child and who is parent

    if (pid== -1){
        #if DEBUG
            printf("Failed to fork from parent\n");
        #endif
    }
    else if (pid==0){
        //CHILD PROCESS
        #if DEBUG
            printf("Child process is: %u , Parent process is %u \n",getpid(),getppid());
        #endif
        char * args[2];
        args[0]="/bin/ls";
        args[1]=NULL;
        execv(args[0],args);
        #if DEBUG
            printf("Error on child process exec call\n");
        #endif
        exit(1);
    }else{
        wait(NULL);
        #if DEBUG
            
            printf("Parent: child process finished,we back to shell\n");
        #endif
    }
   


    
}
        