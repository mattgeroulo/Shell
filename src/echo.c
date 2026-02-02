
#include "stdlib.h"
#include "stdio.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "echo.h"

void echo( char* argv[]){
    pid_t pid = fork();
    //both processes run from here, use pid value to determine who is child and who is parent

    if (pid== -1){
        printf("fork process failed");
    }
    else if (pid==0){

        char * args[3];
        args[0]="/bin/echo";
        args[1]=argv[1];
        args[2]=NULL;
        execv(args[0],args);
        exit(1);
    }else{
        wait(NULL);
    }
}