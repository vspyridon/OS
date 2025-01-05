#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    FILE *file; //Don't ask me I don't fully get pointers still
    pid_t pid;

    // Open the file in append mode
    file = fopen("pids.txt", "a"); //This "a" is important since if the file exists, it opens the file for writing at the end if the file does not exist, it creates the file.It stand for "append mode"
    if (file == NULL) {// This checks if fopen operated succesfully since if it doesn't it return a NULL pointer
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }


//The same process again to make a parent and child process using fork


    // This creates the child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        fclose(file); //This is good practice since I have use fopen
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        fprintf(file, "Child PID: %d\nParent PID: %d \n", getpid(), getppid() ); //fprint is used instead of printf beacuse with printf I can direct the output, in this case in the file I have created. With printf what is written goes to the standard output, which isn't what I want.
    } else {
        // Parent process
        fprintf(file, "Parent PID: %d\nChild PID: %d\n", getpid(), pid);
        wait(NULL); // Wait for the child process to finish
    }

    // Close the file
    fclose(file);

    return 0;
}

