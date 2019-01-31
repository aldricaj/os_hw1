#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int nargs, char *args[]) {
	if (nargs != 2) {
		printf("Please pass only one arg which is a filename");
	}

	if (fork() ==  0) {
		execl("/bin/ls", "-l",NULL);
	}
	else if (fork() == 0) {
		execl("/bin/ps", "-ef", NULL);
	}
	else if (fork() == 0) {
		char cmd[80];
		strcat(cmd, "cat ");
		strcat(cmd, args[1]);
		system(cmd);
	}	
	else {
		printf("Main pid: %i\n", getpid());
		wait(NULL);
		wait(NULL);
		wait(NULL);
		printf("Main process terminiated\n");
	}
}
