
//#include "readLine.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readLine.h"
#include "ls.h"
#include <ctype.h>



#define DEBUG 1
typedef void (*command_fn)(void);
typedef struct{
    char* cmd ;
    char* args[];
}shellInput;

int main(){
    
    char* argv[24]={0};
    //command_fn commands[256]={0};
    
    //char *const args[]={"ls","-l",(char *)NULL};
    size_t buffer_size =128;
    
    char* buffer =  malloc(buffer_size);
    shellInput *input = malloc(sizeof(shellInput));
    input->args[0]= "hello";
    input->cmd = "ls";
    printf("%s",input->cmd);
    printf("size of shellInput: %ld\n",sizeof(shellInput));
    do{
       
       // char input;
        printf(">");
        buffer = readLine(buffer,buffer_size);
        //buffer contains standard io input, parse next
        
        if(!strcmp(buffer,"ls")){
            ls(argv);
            printf("In ls statement\n");
        }else{
            ls(argv);
            printf("In the else statement\n");
        }
        
        
         if(!strcmp(buffer,"exit")){
            break;
        }
       
        //printf("argv[0]: %s  argv[1]: %s",argv[0],argv[1]);
    }while(*buffer!='\0');
    free(buffer);
}