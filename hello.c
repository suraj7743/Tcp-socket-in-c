#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int id = fork();
    int count ;
    if (id ==0){
        sleep(2);
        printf("i am child process %d and my parent id is %d \n", getpid(), getppid());
        count =1;
    }else{
        printf("i am parent process %d and my parent is %d\n", getpid(),getppid());
        count =6;
        return 0;
    }
    int i ;
    if (id !=0){
        wait(NULL);
    }
    for ( i =count ;i<count+5;i++){
        printf("%d ", i);
        fflush(stdout);
    }
    if (id !=0){
        printf("\n");
    }
    return 0;


};