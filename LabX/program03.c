
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Signal handler for SIGUSR1 in the child process
void sigusr1_handler(int sig) {
    if (sig == SIGUSR1) { // In the lab there isn't an if statement , there is only a printf, and he implements the check in the child process. I wanted to do  it in the fucntion, I think its better?
        printf("Child received SIGUSR1 signal from parent!\n");
        exit(0); // Exit after handling the signal
    }
}

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();
    
    
    //Same logic as before
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // This is the child process
        //In the Lab example he prints the PIDs of the processes , I am not doing that since that is not what is asked of me
        printf("\n Child process started, waiting for signal...\n");

        // Set up the signal handler for SIGUSR1
        signal(SIGUSR1, sigusr1_handler);

        // Wait indefinitely for a signal
        while (1) {
            pause(); // Suspend the process. Wait for signals
        }
    } else {
        // This is the parent process
        printf("\n Parent process sending SIGUSR1 to child (PID: %d)\n", pid);

        // Sleep for 3 seconds  to ensure the child process is ready
        sleep(3);

        // Send SIGUSR1 signal to the child process
        printf("\n Parent sending SUGUSR1 to child process\n");
        if (kill(pid, SIGUSR1) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }

        // Wait for the child process to terminate
        wait(NULL);
        printf("\n Parent process exiting.\n");
    }

    return 0;
}
