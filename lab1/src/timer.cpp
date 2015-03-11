#include "../inc/timer.h"
#include <iostream>

Timer::Timer(): _time_start(0), _time_stop(0) {}

void Timer::startTimer() {
	_time_start = std::clock();
}

void Timer::stopTimer() {
	_time_stop = std::clock();
}

double Timer::diffTimeMs() {
	if((double)_time_stop >= (double)_time_start) {
	return (_time_stop - _time_start) / (double)(CLOCKS_PER_SEC/1000);
	}
	else {
		std::cerr<<"Przed wywolaniem funkcji diffTimeMs nalezy odczytac czas rozpoczecia i zakonczenia pomiaru \n"
				<<"(time_stop < time_start)";
		return 0;
	}
}
