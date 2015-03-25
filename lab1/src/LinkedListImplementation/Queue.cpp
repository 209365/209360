/**
*
\file
Queue.cpp
*
\brief
Definicja klasy Queue
*/
#include "../../inc/LinkedListImplementation/Queue.h"

template <typename T>
ListImplementation::Queue<T>::Queue() :List<T>(){}

template <typename T>
Element<T>* ListImplementation::Queue<T>::pop() {
	return List<T>::pop(List<T>::Front);

}

template <typename T>
void ListImplementation::Queue<T>::push(Element<T>* elem) {
	List<T>::push(elem,List<T>::Back);

}
