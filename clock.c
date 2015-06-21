#include <stdio.h>
#include <time.h>
#include <curses.h>
#include "my_ui_thread.h"
#include "time_utils.h"

void *main_routine(void *arg) {
    time_t t = NULL;
    char str_time[100];
    while (1) {
        t = time(NULL);
        sprintf(str_time, "%s", ctime(&t));
        //update_ui(&str_time);
        mvaddstr(1, 1, str_time);
        delay(30);
    }
}

int main() {
    my_ui_start(&main_routine);
    return 0;
}
