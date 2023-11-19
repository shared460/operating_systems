/**
 1.about finding the directoies in any directory, basicall ls command
*/


//input and output operations
#include<stdio.h>
//directory manupulation
#include<dirent.h>
//memory allocation
#include<stdlib.h>
int main(){

    char dirname[10];
    DIR* p;                     // pointer p type of DIR, specific directories
    struct dirent *d;           // pointer d type of struct dirent, contains many directory
    
    printf("Enter directory name\n");   
    scanf("%s",dirname);
    
    p = opendir(dirname);       //opening director of give it to p and read it, if directory can;t opened set it to NULL
    if(p==NULL){
        perror("cannot find directory!");
    }

    while(d=readdir(p))         //enter the loop and read all the directory until it ends with NULL of p directory
    printf("%s\n",d->d_name);
    return 0;
}