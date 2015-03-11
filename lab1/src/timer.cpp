#include "../inc/timer.h"
#include <iostream>

Timer::Timer(): time_start(0), time_stop(0) {}

void Timer::startTimer() {
	time_start = std::clock();
}

void Timer::stopTimer() {
	time_stop = std::clock();
}

double Timer::diffTimeMs() {
	if(time_stop > time_start) {
	return (time_stop - time_start) / (double)(CLOCKS_PER_SEC / 1000);
	}
	else {
		std::cerr<<"Przed wywolaniem funkcji diffTimeMs nalezy odczytac czas rozpoczecia i zakonczenia pomiaru \n"
				<<"(time_stop <= time_start)";
		return 0;
	}
}
