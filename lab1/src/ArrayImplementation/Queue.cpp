/**
*
\file
Queue.cpp
*
\brief
Definicja klasy Queue
*/
#include "../../inc/ArrayImplementation/Queue.h"

template <typename T>
unsigned int ArrayImplementation::Queue<T>::_MAX_SIZE=DEFAULT_MAX_SIZE;

template <typename T>
ArrayImplementation::Queue<T>::Queue() {
	_elements = new Element<T>[_MAX_SIZE];
	_top=0;
}

template <typename T>
ArrayImplementation::Queue<T>::Queue(unsigned int max_size){
	_MAX_SIZE=max_size;
	_elements = new Element<T>[_MAX_SIZE];
	_top=0;
}

template <typename T>
Element<T>* ArrayImplementation::Queue<T>::pop() {
	Element<T>* returnElem = _elements[0];
	for (int i=0;i<_top-1;i++)
	     _elements[i]= _elements[i+1];
	     _top--;

}

template <typename T>
void ArrayImplementation::Queue<T>::push(Element<T>* elem) {
	_elements[++_top]=elem;

}

template <typename T>
ArrayImplementation::Queue<T>::~Queue() {
	delete[] _elements;
}


