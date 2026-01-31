
//#include "readLine.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <syscall.h>
#include "readLine.h"




#define DEBUG 1



int main(int argc,char *argv[]){
    (void)argc;
    (void)argv;
    
    //char *const args[]={"ls","-l",(char *)NULL};
    size_t buffer_size =128;
    char* buffer =  malloc(buffer_size);
    do{
        printf(">");
        buffer = readLine(buffer,buffer_size);
        size_t buffer_len= strlen(buffer);
        for(size_t i=0;i<buffer_len;i++){
            buffer[i]=tolower((unsigned char)buffer[i]);
        }

        if(!strcmp(buffer,"ls")){
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
                pid_t child_pid = wait(NULL);
                #if DEBUG
                    printf("child process reaped, id was : %u\n",child_pid);
                    printf("Parent: child process finished,we back to shell\n");
                #endif
            }
            //pid_t child_pid = getpid();
            //pid_t parent_pid = getppid();
            //printf("child pid: %u\n", child_pid);
            //printf("Parent pid: %u\n", parent_pid);
          
            
        }
        else if(!strcmp(buffer,"exit")){
            break;
        }
       
        //printf("argv[0]: %s  argv[1]: %s",argv[0],argv[1]);
    }while(*buffer!='\0');
    free(buffer);
}