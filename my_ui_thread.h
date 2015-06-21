/*
 * ncurses_thread.h
 *
 *  Created on: Nov 24, 2014
 *      Author: rhuanca
 */

#ifndef NCURSES_THREAD_H_
#define NCURSES_THREAD_H_

#include <curses.h>

void my_ui_stop();
int my_ui_is_running();
void my_ui_start(void *(*__start_routine)(void *));
void my_ui_update(void *(_sub_routine)(void *));

#endif /* NCURSES_THREAD_H_ */
