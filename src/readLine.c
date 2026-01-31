
#include <stdio.h>
#include <stddef.h>
#include "readLine.h"

#define DEBUG 0

char* readLine(char* buffer,size_t size){
    
    
    
    size_t i=0;
    int c;
    while((c= getchar())!='\n' && c !=EOF){
        
        if (i<size-1){
            buffer[i++]=(char)c;
        }
    }
    buffer[i]='\0';
    return buffer;
    
}