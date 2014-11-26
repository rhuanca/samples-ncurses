#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include "ncurses_thread.h"
#include "time_utils.h"

int main() {
	int c;
	init_ui();
	while(ui_running()) {
		c = getchar();
		if(c == 'x') {
			stop_ui();
		}
	}
	printf("ui is not working any more....\n");
	return 0;
}
