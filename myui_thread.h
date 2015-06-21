/*
 * ncurses_thread.h
 *
 *  Created on: Nov 24, 2014
 *      Author: rhuanca
 */

#ifndef NCURSES_THREAD_H_
#define NCURSES_THREAD_H_

#include <curses.h>

void ui_start(void *(*routine)(void *));
void ui_stop();
int ui_running();

void _ui_run(void *(*__start_routine) (void *));

#endif /* NCURSES_THREAD_H_ */
