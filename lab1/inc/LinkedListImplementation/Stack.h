/**
*
\file
Stack.h
*
\brief
Deklaracja i definicja klasy Stack
*/

#ifndef LIST_STACK_H_
#define LIST_STACK_H_

#include "List.h"

namespace ListImplementation {
/**
\brief
Klasa reprezentująca podstawy konterner danych - stos
*
*
Kolejka jest strukturą danych typu typu LIFO, Last In, First Out; ostatni na wejściu, pierwszy na wyjściu
*/
template <class T>
class Stack : List<T>{
public:
	/**
	\brief
	Konstruktor wywołujący konstruktor klasy bazowej List
	*/
	Stack();

	/**
	\brief
	zwraca element z wierzchu stosu
	*
	*\return element będący na wierzchu stosu
	*/
	Element<T>* pop();

	/**
	\brief
	dodaje element na wierzch
	*
	*\param elem element, który zostanie umieszczony na wierzchu stosu
	*/
	void push(Element<T>* elem);

	/**
	\brief
	Wywołuje destruktor klasy bazowej
	*/
	virtual ~Stack(){};
};

}

template <typename T>
ListImplementation::Stack<T>::Stack() :List<T>(){}

template <typename T>
Element<T>* ListImplementation::Stack<T>::pop() {
	return List<T>::pop(ListImplementation::Front);

}

template <typename T>
void ListImplementation::Stack<T>::push(Element<T>* elem) {
	List<T>::push(elem,ListImplementation::Front);
}



#endif /* LIST_STACK_H_*/
