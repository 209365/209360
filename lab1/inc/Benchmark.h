/*
 * Benchmark.h
 *
 *  Created on: 25-03-2015
 *      Author: mateusz
 */

#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <iostream>

#include "Timer.h"

#include "LinkedListImplementation/List.h"
#include "LinkedListImplementation/Queue.h"
#include "LinkedListImplementation/Stack.h"

#include "ArrayImplementation/List.h"
#include "ArrayImplementation/Queue.h"
#include "ArrayImplementation/Stack.h"

template <class T>
class Benchmark {
private:
	Timer timer;
	int* _resoults;
	void showResoults(int resoults, char* contener_name);
public:
	Benchmark();
	void testList(ArrayImplementation::List<T>* list);
	void testQueque(ArrayImplementation::Queue<T>* queue);
	void testStack(ArrayImplementation::Stack<T>* stack);

	void testList(ListImplementation::List<T>* list);
	void testQueque(ListImplementation::Queue<T>* queue);
	void testStack(ListImplementation::Stack<T>* stack);

};

#endif /* BENCHMARK_H_ */
