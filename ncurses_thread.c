#include <stdio.h>
#include <pthread.h>
#include "time_utils.h"

int run;
pthread_t t;

void *run_ui(void *p) {
	int c = 0;
	while (run) {
		printf("hello it is running...:) %d\n", c++);
		delay(1000);
	}
}

void init_ui() {
	run = 1;
	pthread_create(&t, NULL, run_ui, NULL);
}

void stop_ui() {
	run = 0;
}


int ui_running() {
	return run;
}



