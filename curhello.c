#include <curses.h>
#include <string.h>

typedef struct clock_struct {
	char title[50];
	WINDOW *bol_time_win;
} clock;


void init_clock(WINDOW *win, char *title, struct clock_struct *clock) {
	strcpy(clock->title, title);
}

WINDOW *init_newwin(int height, int width, int starty, int startx) {
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);
	wrefresh(local_win);

	return local_win;
}


int main() {
	clock bol_time, usa_est_time;
	WINDOW *bol_time_win, *usa_est_time_win;
	int maxrows, maxcols;
	initscr();
	getmaxyx(stdscr, maxrows, maxcols);

	refresh();

	bol_time_win = init_newwin(maxrows, maxcols / 2, 0, 0);
	usa_est_time_win = init_newwin(maxrows, maxcols / 2 - 1, 0, maxcols / 2 + 1);

	init_clock(bol_time_win, "Bolivia Time", &bol_time);

	mvwprintw(bol_time_win, 1, 1, "%s", bol_time.title );
	//mvwprintw(bol_time_win, 1, 1, " hello again...");
	refresh();
	wrefresh(bol_time_win);
	// printw("Hello World !!! %d %d", maxrows, maxcols); /* Print Hello World              */
	refresh(); /* Print it on to the real screen */
	getch(); /* Wait for user input */
	delwin(bol_time_win);
	delwin(usa_est_time_win);
	endwin(); /* End curses mode                */
	return 0;
}
