#include <curses.h>

WINDOW *init_newwin(int height, int width, int starty, int startx) {
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);
	wrefresh(local_win);

	return local_win;
}

int main() {
	WINDOW *bol_time_win, *usa_est_time_win;
	int maxrows, maxcols;
	initscr();
	getmaxyx(stdscr, maxrows, maxcols);

	refresh();

	bol_time_win = init_newwin(maxrows, maxcols / 2, 0, 0);
	usa_est_time_win = init_newwin(maxrows, maxcols / 2 - 1, 0, maxcols / 2 + 1);


	// printw("Hello World !!! %d %d", maxrows, maxcols); /* Print Hello World              */
	refresh(); /* Print it on to the real screen */
	getch(); /* Wait for user input */
	delwin(bol_time_win);
	delwin(usa_est_time_win);
	endwin(); /* End curses mode                */
	return 0;
}
