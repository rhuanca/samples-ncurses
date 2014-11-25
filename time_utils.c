#include <sys/time.h>
#include <time.h>

void delay(int millis) {
	clock_t t1, t2;
	double elapsed;
	int clocks_per_millisec = CLOCKS_PER_SEC / 1000;
	t1 = clock();
	do {
		t2 = clock();
		elapsed = ((double) (t2 - t1)) / clocks_per_millisec;
	} while (elapsed < millis);
}

