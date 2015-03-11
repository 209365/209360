#include <iostream>
#include "../inc/timer.h"
#include "../inc/doubleNumbers.h"
#include <math.h>

using namespace std;


int main() {
	unsigned int pow_problem_size = 8;
	unsigned long long int max_tab_size = pow(10, pow_problem_size);
	unsigned long long test_numbers[pow_problem_size];

	for(unsigned int i=0;i<pow_problem_size;i++) {
		test_numbers[i] = pow(10, i);
	}

	double results[pow_problem_size];
	cout<<"problem size:"<<pow_problem_size<<"\n";

	Timer timer;
	doubleNumbers numb(max_tab_size);
	numb.loadRandomNumbers();

	for(unsigned int i=0; i< pow_problem_size; i++) {

	timer.startTimer();
	numb.multiplyByTwo(test_numbers[i]);
	timer.stopTimer();

	results[i] = timer.diffTimeMs();

	}

	for(unsigned int i=0;i<pow_problem_size;i++) {
		cout<<i+1<<". "<<results[i]<<"\n";
	}

}
