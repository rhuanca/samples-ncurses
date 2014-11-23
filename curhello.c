#include <curses.h>
#include <pthread.h>
#include <string.h>

struct clock_struct {
	pthread_t tid;
	char title[50];
	WINDOW *win;
};

void init_clock(WINDOW *win, char *title, struct clock_struct *clock) {
	clock->win = win;
	strcpy(clock->title, title);
}

WINDOW *init_newwin(int height, int width, int starty, int startx) {
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);
	wrefresh(local_win);
	return local_win;
}

void *clock_work(void *p) {
	struct clock_struct *cs = p;
	refresh();

	mvwprintw(cs->win, 1,1, "%s", cs->title);

	wrefresh(cs->win);
	refresh();


//	mvwprintw(bol_time.win, 1, 1, "%s", bol_time.title);
//	refresh();
//	wrefresh(bol_time_win);
}

void start_clock(struct clock_struct *c) {
	pthread_t t;
	int tid;
	if (pthread_create(&t, NULL, clock_work, c) != 0) {
		mvwprintw(c->win, 1, 1, "Unable to start clock: %s", c->title);
		refresh();
		c->tid = -1;
		return;
	}
	c->tid = t;
}

int main() {
	struct clock_struct bol_time, usa_est_time;
	WINDOW *bol_time_win, *usa_est_time_win;
	int maxrows, maxcols;

	initscr();
	getmaxyx(stdscr, maxrows, maxcols);
	refresh();

	// create clock windows
	bol_time_win = newwin(maxrows, maxcols / 2, 0, 0);
	usa_est_time_win = newwin(maxrows, maxcols / 2 - 1, 0, maxcols / 2 + 1);

	// start clocks
	init_clock(bol_time_win, "La Paz Time", &bol_time);
	start_clock(&bol_time);

	init_clock(usa_est_time_win, "Germantown Time", &usa_est_time);
	start_clock(&usa_est_time);

	// wait for a key
	getch();

//	if (bol_time.tid > 0) {
//		pthread_join(bol_time.tid, NULL);
//	}
//
//	if (bol_time.tid > 0) {
//		pthread_join(usa_est_time.tid, NULL);
//	}

	delwin(bol_time.win);
	delwin(usa_est_time.win);
	endwin();
	return 0;
}
