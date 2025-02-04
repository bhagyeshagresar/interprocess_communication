#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


//We want to create 1 Parent Process and 3 Children Processes

//main is our parent process



int main(){

    pid_t pid;

    for(int i = 0; i < 3; i++){

        pid = fork();

       
        if(pid == 0){
            printf("This is a child process %d with parent ID %d and child process ID : %d\n", i+1, getppid(), getpid());
            exit(0);
        }
        else if(pid < 0){
            perror("Error using fork() to creat children processes\n");
            exit(1);
        }




        // if(pid == getpid() + 1){
        //     printf("This is a first child process with parent ID %d and child process ID : %d\n", getpid(), getppid());
        //     exit(0);
        // }
        // else if(pid == getpid() + 2){
        //     printf("This is a second child process with parent ID %d and child process ID : %d\n", getpid(), getppid());
        //     exit(0);
        // }
        // else if(pid == getpid() + 3){
        //     printf("This is a third child process with parent ID %d and child process ID : %d\n", getpid(), getppid());
        //     exit(0);
        // }
        // else{
        //     perror("Error using fork() to creat children processes\n");
        //     exit(1);
        // }

    }

    


    return 0;
}