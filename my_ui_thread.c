#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <unistd.h>
#include "my_ui_thread.h"

int _my_ui_is_running;
pthread_t _my_ui_thread;
WINDOW *_my_ui_main_win;

//int _my_ui_routines_to_execute;
//void *(*_my_ui_routines[10])(void *);
//int _my_ui_routines_length;

void my_ui_stop() {
    _my_ui_is_running = 0;
}

int my_ui_is_running() {
    return _my_ui_is_running;
}

void my_ui_start(void *(*__start_routine)(void *)) {
    if ((_my_ui_main_win = initscr()) == NULL) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }
    refresh();
    _my_ui_is_running = 1;

    if( pthread_create(&_my_ui_thread, NULL, __start_routine, NULL) != 0) {
        fprintf(stderr, "Unable to start routine.\n");
        exit(EXIT_FAILURE);
    }

//    _my_ui_routines_length = 0;
//    _my_ui_routines_to_execute = 0;
    while (my_ui_is_running()) {
//        if(_my_ui_routines_to_execute) {
//            refresh();
//        }
    }
    delwin(_my_ui_main_win);
    endwin();
    refresh();
}

void my_ui_update(void *(_sub_routine)(void *)) {
//    _my_ui_routines[_my_ui_routines_length] = _sub_routine;
//    _sub_routine ++;
}

