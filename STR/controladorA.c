/**********************************************************
 *  INCLUDES
 *********************************************************/
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ioLib.h>
#include "displayA.h"

/**********************************************************
 *  Constants
 **********************************************************/
#define DEV_NAME "/tyCo/1"
#define BAUDS 9600

/**********************************************************
 *  Global Variables 
 *********************************************************/
int fdSerie;



/**********************************************************
 *  Function: init_serial
 *********************************************************/
int init_serial(char *devName, int bauds)
{
	int fd_serie;
	int ret;
	/* Open serial port */
	printf("open serial device %s \n",devName);
	fd_serie = open (devName, O_RDWR|O_NONBLOCK, 0644);
	if (fd_serie < 0) {
		printf("open: error opening serial\n");
		return -1;
	}

	/* Establish baud rate */
	ret = ioctl (fd_serie, FIOBAUDRATE, bauds);
	printf ("ioctl: FIOBAUDRATE (%d): ret = %d\n",bauds,ret);
	
	return fd_serie;
}

/**********************************************************
 *  Function: controller
 *********************************************************/
void *controller(void *arg)
{    
	float speed = 0.0;
	char request[10];
	char answer[10];
	
	
    // Endless loop
	memset(request,'\0',10);
	memset(answer,'\0',10);
    while(1) {
	
		// read speed and draw it
		strcpy(request,"SPD: REQ\n");
		simulator(request, answer);
		// uncomment to access arduino
		//write(fdSerie, request, 9);
		//read (fdSerie, answer, 9);
		if (1 == sscanf (answer,"SPD:%f\n",&speed)) {
			displaySpeed(speed);  
		}
		
		// read slope and draw it
		strcpy(request,"SLP: REQ\n");
		simulator(request, answer);
        if (0 == strcmp(answer,"SLP:DOWN\n")) displaySlope(-1);	
        if (0 == strcmp(answer,"SLP:FLAT\n")) displaySlope(0);	
        if (0 == strcmp(answer,"SLP:  UP\n")) displaySlope(1);
				
    }
    //return (0);
}

/**********************************************************
 *  Function: main
 *********************************************************/
int main ()
{
    pthread_t thread_ctrl;
	sigset_t alarm_sig;
	int i;

	/* Block all real time signals so they can be used for the timers.
	   Note: this has to be done in main() before any threads are created
	   so they all inherit the same mask. Doing it later is subject to
	   race conditions */
	sigemptyset (&alarm_sig);
	for (i = SIGRTMIN; i <= SIGRTMAX; i++) {
		sigaddset (&alarm_sig, i);
	}
	sigprocmask (SIG_BLOCK, &alarm_sig, NULL);

    // init display
	displayInit(SIGRTMAX);
	
	// init Serial, uncomment to plug in arduino
	// fdSerie = init_serial(DEV_NAME, BAUDS);

    /* Create first thread */
    pthread_create (&thread_ctrl, NULL, controller, NULL);
    pthread_join (thread_ctrl, NULL);
    return (0);
}
    
