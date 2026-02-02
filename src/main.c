
//#include "readLine.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readLine.h"
#include "ls.h"
#include <ctype.h>

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
    
    char* argv[24]={0};
    //command_fn commands[256]={0};
    
    //char *const args[]={"ls","-l",(char *)NULL};
    size_t buffer_size =128;
    
    char* buffer =  malloc(buffer_size);
    shellInput *input = malloc(sizeof(shellInput)+2*sizeof(char*));
   
    input->args[0]= malloc(128);
    input->args[1]=NULL;
   
    do{
       
       // char input;
        printf(">");
        buffer = readLine(buffer,buffer_size);
        input->cmd = buffer;
        //buffer contains standard io input, parse next
        //lets populate input->args[0], then update ls to actually use them
        parseInput(input->cmd,buffer_size,input->args[0]);
        if(!strcmp(input->cmd,"ls")){
            input->command_function=ls;
            input->command_function(input->args);
            printf("In ls statement\n");
        }else{
            printf("Unsupported || incorrect function call\n");
        }
        
        
         if(!strcmp(buffer,"exit")){
            break;
        }
       
        //printf("argv[0]: %s  argv[1]: %s",argv[0],argv[1]);
    }while(*buffer!='\0');
    free(input->args[0]);
    free(input);
    free(buffer);
}