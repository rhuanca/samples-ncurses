#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <unistd.h>
#include "ncurses_thread.h"

int ui_is_running;
pthread_t ui_thread;
WINDOW *ui_main_win;

void ui_start(void *(*__start_routine) (void *)) {


    FILE *fp = fopen("/home/rhuanca/tmp/ooops3.txt", "w");
    fprintf(fp, "entered...here.\n");
    fflush(fp);

    int r = pthread_create(&ui_thread, NULL, __start_routine, NULL);

    fprintf(fp, "result: %i\n", r);
    fflush(fp);

    _ui_run();

    while (ui_running()) {
        // do nothing
    }

    fclose(fp);
}

void ui_stop() {
    ui_is_running = 0;
}

int ui_running() {
    return ui_is_running;
}

void _ui_run() {
    if ((ui_main_win = initscr()) == NULL) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen("/home/rhuanca/tmp/ooops2.txt", "w");
    fprintf(fp, "entered...here.");
    fflush(fp);

    refresh();
    ui_is_running = 1;
    while (ui_running()) {
    }
    delwin(ui_main_win);
    endwin();
    refresh();
}
