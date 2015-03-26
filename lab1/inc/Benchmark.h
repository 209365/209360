/*
 * Benchmark.h
 *
 *  Created on: 25-03-2015
 *      Author: mateusz
 */

#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <iostream>
#include <cmath>
#include <iostream>
#include <string>
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
	int _testPower;
	Timer _timer;
	double* _resoults;
	void showResoults(double resoults[], std::string contener_name);
public:
	Benchmark(unsigned int testPower);

	void testList(ArrayImplementation::List<T>* list, ArrayImplementation::Increase inc);
	void testQueue(ArrayImplementation::Queue<T>* queue, ArrayImplementation::Increase inc);
	void testStack(ArrayImplementation::Stack<T>* stack, ArrayImplementation::Increase inc);

	void testList(ListImplementation::List<T>* list);
	void testQueue(ListImplementation::Queue<T>* queue);
	void testStack(ListImplementation::Stack<T>* stack);

};

template <typename T>
Benchmark<T>::Benchmark(unsigned int testPower) {
	_testPower=testPower;
	_resoults = new double[_testPower];

}

template <typename T>
void Benchmark<T>::showResoults(double resoults[], std::string contener_name) {
	std::cout<<contener_name<<"\n";
	for(int i=0;i<_testPower;i++) {
		std::cout<<"10^"<<i<<": "<<resoults[i]<<"	";
	}
	std::cout<<"\n";
}

template <typename T>
void Benchmark<T>::testList(ListImplementation::List<T>* list) {
	int testNumber;
	for(int i=0;i<_testPower;i++) {
		testNumber = pow(10,i);
		_timer.startTimer();
		for(int j=0;j<testNumber;j++) {
			list->push(new Element<T>(new T), ListImplementation::Front);
		}
		_timer.stopTimer();
		_resoults[i]=_timer.diffTimeMs();
		delete list;
		list = new ListImplementation::List<T>();
	}
	showResoults(_resoults, "Lista oparta na wskaźnikach");
}

template <typename T>
void Benchmark<T>::testQueue(ListImplementation::Queue<T>* queue) {
	int testNumber;
	for(int i=0;i<_testPower;i++) {
		testNumber = pow(10,i);
		_timer.startTimer();
		for(int j=0;j<testNumber;j++) {
			queue->push(new Element<T>(new T));
		}
		_timer.stopTimer();
		_resoults[i]=_timer.diffTimeMs();
		delete queue;
		queue = new ListImplementation::Queue<T>();
	}
	showResoults(_resoults, "Kolejka oparta na liscie");
}

template <typename T>
void Benchmark<T>::testStack(ListImplementation::Stack<T>* stack) {
	int testNumber;
	for(int i=0;i<_testPower;i++) {
		testNumber = pow(10,i);
		_timer.startTimer();
		for(int j=0;j<testNumber;j++) {
			stack->push(new Element<T>(new T));
		}
		_timer.stopTimer();
		_resoults[i]=_timer.diffTimeMs();
		delete stack;
		stack = new ListImplementation::Stack<T>();
	}
	showResoults(_resoults, "Stos oparty na liscie");
}

template <typename T>
void Benchmark<T>::testList(ArrayImplementation::List<T>* list, ArrayImplementation::Increase inc) {
	int testNumber;
	for(int i=0;i<_testPower;i++) {
		testNumber = pow(10,i);
		_timer.startTimer();
		for(int j=1;j<testNumber+1;j++) {
			list->push(new T,j, inc);
		}
		_timer.stopTimer();
		_resoults[i]=_timer.diffTimeMs();
		delete list;
		list = new ArrayImplementation::List<T>();
	}
	showResoults(_resoults, "Lista oparta na tablicy");
}

template <typename T>
void Benchmark<T>::testQueue(ArrayImplementation::Queue<T>* queue, ArrayImplementation::Increase inc) {
	int testNumber;
	for(int i=0;i<_testPower;i++) {
		testNumber = pow(10,i);
		_timer.startTimer();
		for(int j=0;j<testNumber;j++) {
			queue->push(new T, inc);
		}
		_timer.stopTimer();
		_resoults[i]=_timer.diffTimeMs();
		delete queue;
		queue = new ArrayImplementation::Queue<T>();
	}
	showResoults(_resoults, "Kolejka oparta na tablicy");
}

template <typename T>
void Benchmark<T>::testStack(ArrayImplementation::Stack<T>* stack, ArrayImplementation::Increase inc) {
	int testNumber;
	for(int i=0;i<_testPower;i++) {
		testNumber = pow(10,i);
		_timer.startTimer();
		for(int j=0;j<testNumber;j++) {
			stack->push(new T, inc);
		}
		_timer.stopTimer();
		_resoults[i]=_timer.diffTimeMs();
		delete stack;
		stack = new ArrayImplementation::Stack<T>();
	}
	showResoults(_resoults, "Stos oparta na tablicy");
}




#endif /* BENCHMARK_H_ */
