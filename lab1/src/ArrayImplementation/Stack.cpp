/**
*
\file
Queue.cpp
*
\brief
Definicja klasy Stack
*/
#include "../../inc/ArrayImplementation/Stack.h"

template <typename T>
unsigned int ArrayImplementation::Stack<T>::_MAX_SIZE=DEFAULT_MAX_SIZE;

template <typename T>
ArrayImplementation::Stack<T>::Stack() {
	_elements = new Element<T>[_MAX_SIZE];
	_top=0;
}
template <typename T>
ArrayImplementation::Stack<T>::Stack(int max_size){
	_MAX_SIZE=max_size;
	_elements = new Stack<T>[_MAX_SIZE];
	_top=0;
}

template <typename T>
Element<T>* ArrayImplementation::Stack<T>::pop() {
	if(_top<0) {
		std::cerr<<"Brak elementow na liscie";
	}
	else {
		return _elements[--_top];
	}
}

template <typename T>
void ArrayImplementation::Stack<T>::push(Element<T>* elem) {
	if(_top>=_MAX_SIZE) {
	_elements[++_top]=elem;
	}
	else {
		std::cerr<<"Za mala tablica na dodanie kolejnego elementu do stosu";
	}
}

template <typename T>
int ArrayImplementation::Stack<T>::size() {
	return (_top+1);
}

template <typename T>
unsigned short ArrayImplementation::Stack<T>::isEmpty() {

	return (this->_top<0);
}

template <typename T>
ArrayImplementation::Stack<T>::~Stack() {
	delete[] _elements;
}
