#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

//We want to create 1 Parent Process and 3 Children Processes

//main is our parent process

//getppid() : returns the process ID of the parent of the calling process
// getppid() returns the process ID of the parent of the  current process. It never throws any error
//therefore, it is always successful.


//getpid(): returns the process ID of current process. It never thrwos and it is always successful


int main(){


    for(int i = 0; i < 3; ++i){
        pid_t pid = fork();

        if(pid < 0){
            perror("Fork failed\n");
            exit(EXIT_FAILURE);
        }
        else if(pid > 0){
            //Termiante the zombie
            wait(NULL);
            printf("This is parent process with process ID %d \n", getpid());
            
        }
        else{

            printf("This is a child process with process ID %d \n", getpid());
            exit(EXIT_SUCCESS);
            //Process becomes a zombie

        }
    }

    

    return 0;
}