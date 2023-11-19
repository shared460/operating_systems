/**
 basically about cp command
*/

//this is input and output operations
#include<stdio.h>
//POSIX perating system API
#include<unistd.h>
//file control operations
#include<fcntl.h>
//general utilites like exit() functions
#include<stdlib.h>

//takes CLI arguments, argv is array containg all arguments
int main(int argc, char *argv[]){
    
    int f1,f2;
    char buff[50];   //stores data
    long int n;     //no of bytes read or written

    //file1 open and read mode active
    //file2 create and write mode active
    if(((f1 = open(argv[1], O_RDONLY)) == -1 || (f2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0700)) == 1)){
        perror("problem in file");
        exit(1);
    }

    //readinf from file1
    while((n == read(f1, buff, 50))>0)
    
    //writing into file2
    if(write(f2, buff, n)!=n){
        perror("problem in writing");
        exit(3);
    }

    //if problem in reading the error
    if(n==-1){
        perror("problem in reading");
        exit(2);
    }

    close(f2);
    exit(0);
}