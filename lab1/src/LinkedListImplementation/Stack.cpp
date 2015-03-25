/**
*
\file
Stash.cpp
*
\brief
Definicja klasy Stack
*/
#include "../../inc/LinkedListImplementation/Stack.h"


template <typename T>
ListImplementation::Stack<T>::Stack() :List<T>(){}

template <typename T>
Element<T>* ListImplementation::Stack<T>::pop() {
	return List<T>::pop(List<T>::Front);

}

template <typename T>
void ListImplementation::Stack<T>::push(Element<T>* elem) {
	List<T>::push(elem,List<T>::Front);
}
