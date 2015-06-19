#include <stdio.h>
#include <pthread.h>
#include "time_utils.h"

int ui_run;
pthread_t ui_thread;

void *run_ui(void *p) {
	int c = 0;

	while (ui_run) {
		printf("hello it is running...:) %d\n", c++);
		delay(1000);
	}
}

void init_ui() {
	ui_run = 1;
	pthread_create(&ui_thread, NULL, run_ui, NULL);
}

void stop_ui() {
	ui_run = 0;
}


int ui_running() {
	return ui_run;
}



