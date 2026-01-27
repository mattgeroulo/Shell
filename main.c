
//#include "readLine.h"
#include <stdlib.h>
#include <stdio.h>


int readLine(){
    
    int num_bytes_read=0;
    char* buffer =  malloc(sizeof(char)*128);
    while(1){
        char c= getchar();
        if(c=='\n'){
            break;
        }
        num_bytes_read+=sizeof(c);
    }
    free(buffer);
    printf("Number of bytes read: %d\n",num_bytes_read);
    if(num_bytes_read==0){
        return 1;
    }else{
        return 0;
    }
    
}



int main(int argc,char *argv[]){
    int status=1;
    
    do{
        printf(">");
        status = readLine();
    }while(!status);
}