#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include <unistd.h>

/*
 * Function to handle SIGIO.
 */
static void sig_io(int signo)
{
	printf("wait_io:  got sigio\n");
	exit(0);
}

/*
 * This program waits either for a SIGIO signal, or will time out. The
 * exit status is 'good' on the SIGIO receive, 'bad' on the timeout.
 */
int main(int argc, char **argv)
{

	struct sigaction siga;

	/*
	 * Set up signal handler for SIGIO.
	 */
	siga.sa_handler = sig_io;
	sigemptyset(&siga.sa_mask);
	siga.sa_flags = 0;
	sigaction(SIGIO, &siga, NULL);
	sleep(5);
	printf("wait_io:  exiting without receiving sigio\n");
	exit(1);

}
