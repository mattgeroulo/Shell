
//#include "readLine.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readLine.h"
#include "ls.h"
#include <ctype.h>
#include "echo.h"
#include "parseInput.h"

#define DEBUG 1
typedef void (*command_fn)(char** args);

//args if variable length, length is defined in malloc call
//args has to go at the end of the struct since its variable size, if it was fixed size it could go anywhere
typedef struct{
    char* cmd;
    command_fn command_function;
    char* args[];
}shellInput;

int main(){
    
    //char* argv[24]={0};
    //command_fn commands[256]={0};
    
    //char *const args[]={"ls","-l",(char *)NULL};
    size_t buffer_size =128;
    
    char* buffer =  malloc(buffer_size);
    shellInput *input = malloc(sizeof(shellInput)+256*sizeof(char*));
   
    input->args[0]= malloc(128);
    input->args[1]=NULL;
   
    do{

        printf(">");
        buffer = readLine(buffer,buffer_size);
        input->cmd = buffer;
        parseInput(input->cmd,buffer_size,input->args);
        if(!strcmp(input->cmd,"ls")){
            input->command_function=ls;
            input->command_function(input->args);
           // printf("In ls statement\n");
        }
        else if(!strcmp(input->cmd,"echo")){        
            input->command_function=echo;
            input->command_function(input->args);
           // printf("In ls statement\n");
        }
        else if(!strcmp(buffer,"exit")){
            break;
        }
        else{
            printf("Unsupported || incorrect function call: %s\n",input->cmd);
        }
    }while(*buffer!='\0');
   
    free(input);
    free(buffer);
}