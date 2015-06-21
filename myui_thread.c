#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <unistd.h>
#include "myui_thread.h"

int _ui_is_running;
pthread_t ui_thread;
WINDOW *ui_main_win;

void ui_start(void *(*__start_routine)(void *)) {
    _ui_run(__start_routine);
}

void ui_stop() {
    _ui_is_running = 0;
}

int ui_running() {
    return _ui_is_running;
}

void _ui_run(void *(*__start_routine)(void *)) {
    if ((ui_main_win = initscr()) == NULL) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }
    refresh();
    _ui_is_running = 1;

    if( pthread_create(&ui_thread, NULL, __start_routine, NULL) != 0) {
        fprintf(stderr, "Unable to start routine.\n");
        exit(EXIT_FAILURE);
    }

    while (ui_running());
    delwin(ui_main_win);
    endwin();
    refresh();
}
