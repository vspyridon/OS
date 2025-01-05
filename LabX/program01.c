#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

pid_t pid1,pid2,pid3;

//The first fork

pid1=fork();
if (pid1<0) { //In case of Error in fork
	perror("\nfork failed\n");
	exit(EXIT_FAILURE);
}
else if (pid1==0) { //This is the first child process
  printf("\n This is the first child proccess : PID = %d , parent PID = %d\n",getpid() , getppid() ); 
  return 0; // Exits the child procces
}

//In the Lab example there is another "else" which I haven't put. All it's there for is for reasons of clarity. it is not needed , the fork stil runs properly

wait(NULL); //This makes the parent process wait for the first child. Apperntly it's good practice fo synchronisation

//The second fork

pid2=fork();
if (pid2<0) { //In case of Error in fork
	perror("\nfork failed\n");
	exit(EXIT_FAILURE);
}
else if (pid2==0) { //This is the second child process
  printf("\n This is the second child proccess : PID = %d , parent PID = %d\n",getpid() , getppid() ); 
  return 0; // Exits the child procces
}

wait(NULL); //This makes the parent process wait for the second child

//The third fork

pid3=fork();
if (pid3<0) {//In case of Error in fork
	perror("fork failed");
	exit(EXIT_FAILURE);
}
else if (pid3==0) {//This is the second child process
  printf("\n This is the third child proccess : PID = %d , parent PID = %d\n ",getpid() , getppid() ); 
  return 0; // Exits the child procces
}

wait(NULL); //This makes the parent process wait for the third child

return 0;

}
