#include <stdio.h>
#include "myui_thread.h"

void *main_routine(void *arg)
{
    FILE *fp = fopen("/home/rhuanca/tmp/ooops.txt", "w");
    fprintf(fp, "entered...here\n.");
    fflush(fp);
}

int main() {
    ui_start(&main_routine);
	return 0;
}
