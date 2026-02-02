
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void parseInput(char* buffer, size_t size, char* returnValue[]){
    (void)size;
    (void)returnValue;
    size_t buffer_len = strlen(buffer);
  
    //size_t j=0;
    size_t i;
    for ( i=0;i<buffer_len;i++){
        if(buffer[i]==' '){
            //buffer looks like it removed inputs after spaces but it still exists in memory. ex: input="hello there" and print(buffer) outputs:"hello"
            //but print buffer+6 prints "there"
            buffer[i]='\0';    
    }}
    size_t j=0;
    for(size_t i=0;i<buffer_len;i++){
        if(buffer[i]!='\0'&&(i == 0 || buffer[i - 1] == '\0')){
            returnValue[j++]= &buffer[i];
        }
    }
    returnValue[j]=NULL;
    printf("here is our returning args from parse:%s%s \n",returnValue[0],returnValue[1]);
    
}