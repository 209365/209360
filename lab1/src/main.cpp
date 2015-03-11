#include <iostream>
#include "../inc/timer.h"
#include "../inc/doubleNumbers.h"
using namespace std;

static int size = 10^9;


int main() {
	int test_numbers[] = {10^0, 10^1, 10^2, 10^3, 10^4, 10^5, 10^6, 10^7, 10^8, 10^9, 10^12, 10^15 };
	unsigned short problem_size = sizeof(test_numbers)/sizeof(int);
	double results[problem_size];
	cout<<"problem size:"<<problem_size<<"\n";
	Timer timer;
	doubleNumbers numb(size);
	numb.loadRandomNumbers();

	for(unsigned int i=0; i< problem_size; i++) {

	timer.startTimer();
	numb.multiplyByTwo(test_numbers[i]);
	timer.stopTimer();

	results[i] = timer.diffTimeMs();

	}

	for(unsigned int i=0;i<problem_size;i++) {
		cout<<i+1<<". "<<results[i]<<"\n";
	}
}
