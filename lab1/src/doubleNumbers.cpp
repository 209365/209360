#include "../inc/doubleNumbers.h"
#include <stdlib.h>
#include <time.h>

doubleNumbers::doubleNumbers(): _size(1000000) {
	_numbers = new long[_size];
	srand (time(NULL));
}

doubleNumbers::doubleNumbers(int size) {
	_size = size;
	_numbers = new long[_size];
	srand (time(NULL));
}

void doubleNumbers::multiplyByTwo(int number) {
	for(int i=0;i<number;i++) {
		_numbers[i]*=2;
	}
}
void doubleNumbers::loadRandomNumbers() {
	for(int i=0;i<_size;i++) {
		_numbers[i] = rand();
	}
}
