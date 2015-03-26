/*
 * Benchmark.h
 *
 *  Created on: 25-03-2015
 *      Author: mateusz
 */

#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <iostream>

#include "../inc/Timer.h"

#include "../inc/LinkedListImplementation/List.h"
#include "../inc/LinkedListImplementation/Queue.h"
#include "../inc/LinkedListImplementation/Stack.h"

#include "../inc/ArrayImplementation/List.h"
#include "../inc/ArrayImplementation/Queue.h"
#include "../inc/ArrayImplementation/Stack.h"

template <class T>
class Benchmark {
private:
	Timer timer;
	int* _resoults;
	void showResoults(int resoults, char* contener_name);
public:
	Benchmark();
	void testLList(ListImplementation::List<T>* list);
	void testLQueque(ListImplementation::Queue<T>* queue);
	void testLStack(ListImplementation::Stack<T>* stack);

	void testAList(ArrayImplementation::List<T>* list);
	void testAQueque(ArrayImplementation::Queue<T>* queue);
	void testAStack(ArrayImplementation::Stack<T>* stack);
};

#endif /* BENCHMARK_H_ */
