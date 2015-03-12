/**
*
\file
doubleNumbers.cpp
*
\brief
Plik zawierający definicje funkcji klasy doubleNumbers.
*/
#include "../inc/doubleNumbers.h"
#include <stdlib.h>
#include <time.h>

doubleNumbers::doubleNumbers(): _size(1000000) {
	_numbers = new unsigned long long[_size];
	srand (time(NULL));
}

doubleNumbers::doubleNumbers(unsigned long long size): _size(size) {
	_numbers = new unsigned long long[_size];
	srand (time(NULL));
}

void doubleNumbers::multiplyByTwo(unsigned long long number) {
	for(unsigned int i=0;i<number;i++) {
		_numbers[i]*=2;
	}
}
void doubleNumbers::loadRandomNumbers() {
	for(unsigned int i=0;i<_size;i++) {
		_numbers[i] = rand();;
	}
}

doubleNumbers::~doubleNumbers() {
	delete[] _numbers;
}
