/**
*
\file
doubleNumbers.cpp
*
\brief
Plik zawierający definicje funkcji klasy doubleNumbers.
*/
#include "../inc/DoubleNumbers.h"
#include <stdlib.h>
#include <time.h>

DoubleNumbers::DoubleNumbers(): _size(1000000) {
	_numbers = new unsigned long long[_size];
	srand (time(NULL));
}

DoubleNumbers::DoubleNumbers(unsigned long long size): _size(size) {
	_numbers = new unsigned long long[_size];
	srand (time(NULL));
}

void DoubleNumbers::multiplyByTwo(unsigned long long number) {
	for(unsigned int i=0;i<number;i++) {
		_numbers[i]*=2;
	}
}
void DoubleNumbers::loadRandomNumbers() {
	for(unsigned int i=0;i<_size;i++) {
		_numbers[i] = rand();;
	}
}

DoubleNumbers::~DoubleNumbers() {
	delete[] _numbers;
}
