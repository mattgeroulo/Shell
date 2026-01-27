
//#include "readLine.h"
#include <stdlib.h>
#include <stdio.h>


void readLine(){
    
    int num_bytes_read=0;
    char* buffer =  malloc(sizeof(char)*128);
    while(1){
        char c= getchar();
        if(c=='\n'){
            break;
        }
        num_bytes_read+=sizeof(&c);
    }
    free(buffer);
    printf("%d %s",num_bytes_read);
}



int main(int argc,char *argv[]){
    int status=1;
    readLine();
    do{
        printf(">");
    }while(status);
}