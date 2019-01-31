#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void exitWithError() {
	printf("You must pass exactly one variable and it must be a non-zero integer");
	exit(1);

}

void forkProgram(int n) {
	int parentPid = getpid();
	pid_t pid = fork();
	if (pid != 0) {
		pid = fork();
		if (pid != 0) pid = fork();
	}
	for (int i = 0; i < n; i++) {
		if (getpid() == parentPid) {
			printf("I am the parent and my pid is %i\n", getpid());
		}
		else {
			printf("I am the child and my pid is %i. My parents pid is %i\n", 
				getpid(), parentPid);
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
