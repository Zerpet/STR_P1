/**********************************************************
 *  INCLUDES
 *********************************************************/
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ioLib.h>
#include "displayB.h"

/**********************************************************
 *  Constants
 **********************************************************/
#define DEV_NAME "/tyCo/1"
#define BAUDS 9600
#define TIME_SEC_CYCLE_SECONDS 5
#define TIME_SEC_CYCLE_NANOSECONDS 5000000000
#define TOTAL_SEC_CYCLES 2

/**********************************************************
 *  Global Variables 
 *********************************************************/
int fdSerie;

float CURRENT_SPEED;
time_t TIME_LAST_CHANGE_MIXER;
int MIXER_STATE;
int IS_DARK;


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


/**
 * Leer pendiente. Esta tarea recive como parámetros dos buffers, el primero 
 * lo usa para escribir el contenido de la request. El segundo lo hace
 * para guardar la respuesta del servidor de comunicaciones.
 * 
 * Esta funcion devuelve un entero en funcion de la pendiente. 1 si es subida,
 * 0 si es plano, -1 si es bajada, 2 si el servidor devolvio error.
 */
int read_slope(char * request_buf, char * answer_buf) {
	
	strcpy(request_buf,"SLP: REQ\n");
	simulator(request_buf, answer_buf);
	int ret;
	
	if (0 == strcmp(answer_buf,"SLP:DOWN\n")) { 
		displaySlope(-1);
		ret = -1;
	} else if (0 == strcmp(answer_buf,"SLP:FLAT\n")) { 
		displaySlope(0);
		ret = 0;
	} else if (0 == strcmp(answer_buf,"SLP:  UP\n")) { 
		displaySlope(1);
		ret = 1;
	} else {	//Error
		ret = 2;
	}
	
	return ret;
}

/*
 * Leer velocidad. Esta tarea recive como parámetros dos buffers, el primero 
 * lo usa para escribir el contenido de la request. El segundo lo hace
 * para guardar la respuesta del servidor de comunicaciones.
 * 
 * Esta funcion devuelve la velocidad actual de la carreta o -1.0 si obtuvo un error
 */
float read_speed(char * request_buf, char * answer_buf) {
	strcpy(request_buf,"SPD: REQ\n");
	simulator(request_buf, answer_buf);
	
	if (1 == sscanf (answer_buf,"SPD:%f\n",&CURRENT_SPEED)) {
		displaySpeed(CURRENT_SPEED);  
	} else {
		CURRENT_SPEED = -1.0;	//Server returned error 
	}	//TODO remove this for final version
	
	return CURRENT_SPEED;
}

/*
 * Funcion para controlar la aceleracion de la carretilla. La funcion envia
 * un mensaje de activacion del acelerador si la velocidad es menor o igual
 * a 55; si es mayor de 55, envia un mensaje de desactivacion.
 * 
 * La funcion devuelve 0 si el servidor respondio con un OK. Si respondio
 * con un error, devolvera cualquier otro numero.
 */
int gas_turn(char * request_buf, char * answer_buf) {
	
	if(CURRENT_SPEED <= 55.0) {
		strcpy(request_buf, "GAS: SET\n");
		simulator(request_buf, answer_buf);
		displayGas(1);
	} else {
		strcpy(request_buf, "GAS: CLR\n");
		simulator(request_buf, answer_buf);
		displayGas(0);
	}
	
	return strcmp(answer_buf,"GAS:  OK\n");
}

/*
 * Funcion para controlar el frenado de la carretilla. La funcion envia
 * un mensaje de activacion del freno si la velocidad es mayor a 55; 
 * si es menor o igual a 55, envia un mensaje de desactivacion.
 * 
 * La funcion devuelve 0 si el servidor respondio con un OK. Si respondio
 * con un error, devolvera cualquier otro numero.
 */
int break_turn(char * request_buf, char * answer_buf) {
	
	if(CURRENT_SPEED <= 55.0) {
		strcpy(request_buf, "BRK: CLR\n");
		simulator(request_buf, answer_buf);
		displayBrake(0);
	} else {
		strcpy(request_buf, "BRK: SET\n");
		simulator(request_buf, answer_buf);
		displayBrake(1);
	}
	
	return strcmp(answer_buf,"BRK:  OK\n");
}

/*
 * Funcion para poner en marcha o parar el mezclador. La funcion
 * devuelve 0 en caso de exito, cualquier otro numero en case
 * de error.
 */
int mixer_turn(char * request_buf, char * answer_buf) {
	
	time_t current = time(NULL);
	double lapse = difftime(current, TIME_LAST_CHANGE_MIXER);
	
	if(lapse > 30.0) {
		if(MIXER_STATE) {
			strcpy(request_buf, "MIX: CLR\n");
			simulator(request_buf, answer_buf);
			MIXER_STATE = 0;
		} else {
			strcpy(request_buf, "MIX: SET\n");
			simulator(request_buf, answer_buf);
			MIXER_STATE = 1;
		}
		
		int ret = strcmp(answer_buf,"MIX:  OK\n"); 
		if(ret == 0) {
			displayMix(MIXER_STATE);
			
			TIME_LAST_CHANGE_MIXER = current;
			
			return ret;
		} else {
			//Error
			return 1;
		}
	}
	return 0;
}

/*
 * Funcion para leer el sensor de luz. Determina si estamos a
 * oscuras. 
 * 
 * Devuelve 1 si estamos a oscuras; 0 si no esta oscuro; -1 en
 * caso de error.
 */
int read_light_sensor(char * request_buf, char * answer_buf) {
	
	strcpy(request_buf, "LIT: REQ\n");
	simulator(request_buf, answer_buf);
	
	int light;
	if(sscanf(answer_buf,"LIT:%d\n",&light) == 1) {
		
		IS_DARK = light < 50 ? 1 : 0;
		displayLightSensor(IS_DARK);
		
	} else {
		//Error
		return -1;
	}
	
	return light;
}

/*
 * Funcion para encender/apagar los focos de la carretilla.
 * La funcion devuelve 0 en caso de exito, cualquier otro
 * numero en caso de error.
 */
int lights_turn(char * request_buf, char * answer_buf) {
	
	if(IS_DARK) {
		strcpy(request_buf, "LAM: SET\n");
		simulator(request_buf, answer_buf);
	} else {
		strcpy(request_buf, "LAM: CLR\n");
		simulator(request_buf, answer_buf);
	}
	
	int ret = strcmp(answer_buf,"LAM:  OK\n");
	displayLamps(IS_DARK);
	
	return ret;
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
	
	struct timespec timeInit, timeEnd, timeDiff, timePeriod;
	timePeriod.tv_sec = (time_t) TIME_SEC_CYCLE_SECONDS;
	timePeriod.tv_nsec = (long) TIME_SEC_CYCLE_NANOSECONDS;
	
	clock_gettime(CLOCK_REALTIME, &timeInit);
	int sec_cycle = 0;
	
    while(1) {
		
    	switch(sec_cycle) {
    	case 0:
    		//Read light sensor
    		read_light_sensor(request, answer);
    		
    		//Turn lights
    		lights_turn(request, answer);
    		
    		//Read slope
    		read_slope(request, answer);
    		
    		//Turn mixer
    		mixer_turn(request, answer);
    		
    		break;
    	case 1:
    		//Read light sensor
			read_light_sensor(request, answer);
			
			//Turn lights
			lights_turn(request, answer);
    		
    		//Read speed
			read_speed(request, answer);
			
			//Turn gas
			gas_turn(request, answer);
			
			//Turn brake
			break_turn(request, answer);
			
    		break;
    	}
    	
    	sec_cycle = (sec_cycle + 1) % TOTAL_SEC_CYCLES;
    	clock_gettime(CLOCK_REALTIME, &timeEnd);
    	
    	diffTime(timeEnd, timeInit, &timeDiff);
    	diffTime(timePeriod, timeDiff, &timeDiff);
    	nanosleep(&timeDiff, NULL);
		addTime(timeInit, timePeriod, &timeInit);
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
    
