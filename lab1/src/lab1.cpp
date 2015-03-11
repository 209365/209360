#include <iostream>
#include "../inc/timer.h"
using namespace std;
long j=0;
int main() {
	Timer timer;
	timer.startTimer();
	for(long i=0;i<100000;i++) {
		j++;
	}
	timer.stopTimer();

	cout << "czas:"<<timer.diffTimeMs() << endl; // prints !!!Hello World!!!
	return 0;
}
