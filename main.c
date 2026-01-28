
//#include "readLine.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
    
    printf("Number of bytes read: %d\n",num_bytes_read);
    //char str[num_bytes_read]=buffer;
    int input=0;
    //printf("Buffer: %s\n",buffer);
    //str[-1]='\n';
    return buffer;
    
}



int main(int argc,char *argv[]){
    int status=1;
    char * input;
    char* buffer =  malloc(sizeof(char)*128);
    do{
        printf(">");
        input = readLine(buffer);
        for(int i=0;i<strlen(input);i++){
            input[i]=tolower(input[i]);
        }

        printf("input: %s\n",input);
        //printf("argv[0]: %s  argv[1]: %s",argv[0],argv[1]);
    }while(*input!='\0');
    free(input);
}