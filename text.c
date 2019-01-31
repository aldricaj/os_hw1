#include <unistd.h>
int main (int nargs, char *args[]) {
	execl("/bin/cat", "./hello.txt", NULL);
}
