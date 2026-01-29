
//#include "readLine.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <syscall.h>

#define DEBUG 0

char* readLine(char* buffer){
    
    int num_bytes_read=0;
    
    int i=0;
    char c;
    while(1){
        c= getchar();
        if (c=='\n' || c==EOF){
            buffer[i]='\0';
            break;
        }
        num_bytes_read+=sizeof(c);
       // printf("%d",c);
        buffer[i]=(char)c;
        i++;
    }
    #if DEBUG
        printf("Number of bytes read: %d\n",num_bytes_read);
    #endif
    //char str[num_bytes_read]=buffer;
    int input=0;
    //printf("Buffer: %s\n",buffer);
    //str[-1]='\n';
    return buffer;
    
}

int main(int argc,char *argv[]){
    int status=1;
    char * input;
    char *const args[]={"ls","-l",(char *)NULL};
    char* buffer =  malloc(sizeof(char)*128);
    do{
        printf(">");
        input = readLine(buffer);
        for(int i=0;i<strlen(input);i++){
            input[i]=tolower(input[i]);
        }

        if(!strcmp(input,"ls")){
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
        else if(!strcmp(input,"exit")){
            break;
        }
        #if DEBUG
            printf("input: %s\n",input);
        #endif
        //printf("argv[0]: %s  argv[1]: %s",argv[0],argv[1]);
    }while(*input!='\0');
    free(input);
}