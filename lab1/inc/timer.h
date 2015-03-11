#ifndef TIMER_H_
#define TIMER_H_

#include <ctime>

class Timer {
	private:
		std::clock_t time_start;
		std::clock_t time_stop;
	public:
		Timer();
		void startTimer();
		void stopTimer();
		double diffTimeMs();
};




#endif /* TIMER_H_ */
