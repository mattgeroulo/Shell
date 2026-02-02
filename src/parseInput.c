
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void parseInput(char* buffer, size_t size, char* returnValue){
    (void)size;
    size_t buffer_len = strlen(buffer);
    int argCount=0;
    size_t j=0;
    for (size_t i=0; i<buffer_len;i++){
        if(buffer[i]==' '){
            argCount++;
            returnValue[j++]='&';
        }else{
            //char is a part of the input
            returnValue[j++]=buffer[i];
        }
        
    }
    returnValue[j] = '\0';
    printf("here is our returning args from parse:%s\n",returnValue);
    
}