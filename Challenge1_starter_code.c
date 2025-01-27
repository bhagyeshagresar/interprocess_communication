#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

//Function that handles a SIGINT signal
void handler_sigint(int signum);


int score = 0;

void end_game() {

   printf("\nFinal score: %d\n", score);
   exit(0); 
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

int main() {

   srand (time(0));

   //Function Pointer
   void(*sigHandlerReturn)(int);

   //Use the signal function to catch the signals
   sigHandlerReturn = signal(SIGINT, handler_sigint);

   if(sigHandlerReturn == SIG_ERR){
      perror("Signal Error: ");
      return 1;
   }
   
   while(1) {
      int a = rand() % 11;
      int b = rand() % 11;

      char txt[4];
    
      printf("\nWhat is %d times %d: ", a, b);
      fgets(txt, 4, stdin);

      int answer = atoi(txt);

      if(answer == a * b)
         score++;
      else
         printf("\nWrong! Score: %d\n", score);
    }

    return 0;
} 


void handler_sigint(int signum){

   if(signum == SIGINT){
      printf("Received SIGINT Error or Ctrl - C signal\n");
      exit(0);
   }
   else{
      printf("Received %d Signal\n", signum);
   }


}
