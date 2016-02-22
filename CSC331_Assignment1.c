/**
 * Outputs the Collatz sequence in the child process.
 * Exercise 3.21, Page 155.
 * Author: Teddy Segal
 * Date: 10/18/16
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t pid;
    int n;

	if (argc == 1) {
		fprintf(stderr,"Usage: ./a.out <starting value>\n");
		
		return -1;
	}

	n = atoi(argv[1]);
   
    //fill in the blank here
    //Create a process
    //Output the Collatz conjecture sequence in the child process
    // --If n is even, n = n/2
    // --If n is odd, n = n*3+1
    // --Stop when n = 1

	printf ("%s %d \n", "Starting Value: ", n);

	if (n <= 0) {
		printf ("Error: Starting value must be greater than '0'\n");
		return -2;
	}

	pid = fork();
	if (pid < 0) {	//error
		fprintf(stderr, "Fork Failed");
		exit(-1);
	} else if (pid == 0) { //Child process
		do {
			if (n % 2 == 0) {
				n = n/2;
			} else if (n % 2 != 0) {
				n = (n * 3) + 1;
			}
			printf("%d \n", n);
		} while (n != 1);
	} else {	//Parent process. Will wait for child to complete
		wait(NULL);
		printf("Parant Process ID: %d \n", pid);
		exit(0);
	}

	return 0;
}
