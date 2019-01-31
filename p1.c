#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void exitWithError() {
	printf("You must pass exactly one variable and it must be a non-zero integer");
	exit(1);

}


void subroutine(int n) {
	for (int i = 0; i < n; i++) {
		printf("This is a child process. My pid is %i. My parent's pid is %i\n",
			getpid(), getppid());
		sleep(2);
	}
}

void forkProgram(int n) {
	int parentPid = getpid();
	if (fork() == 0) {
		subroutine(n);
	}
	else {
		if (fork() == 0) {
			subroutine(n);
		}
		else {
			if (fork() == 0) {
				subroutine(n);
			}
			else {
				for (int i = 0; i < n; i++) {
					printf("I'm the parent and my pid is %i.\n", getpid());
					sleep(2);
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2 || argc > 2) {
		exitWithError();
	}

	int n = atoi(argv[1]);
	if (n <= 0) {
		exitWithError();
	}
	forkProgram(n);
}
