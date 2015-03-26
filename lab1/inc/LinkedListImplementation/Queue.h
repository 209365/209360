/**
*
\file
Queue.h
*
\brief
Deklaracja i definicja klasy Queue
*/

#ifndef LIST_QUEUE_H_
#define LIST_QUEUE_H_

#include "List.h"

namespace ListImplementation {
/**
\brief
Klasa reprezentująca podstawy konterner danych kolejke
*
*
Kolejka jest strukturą danych typu typu FIFO, First In, First Out; pierwszy na wejściu, pierwszy na wyjściu
*/
template <class T>
class Queue : List<T>{
public:
	/**
	\brief
	Konstruktor wywołujący konstruktor klasy bazowej List
	*/
	Queue();

	/**
	\brief
	zwraca element z początku kolejki
	*
	*\return element będący na początku kolejki
	*/
	Element<T>* pop();

	/**
	\brief
	dodaje element na koniec kolejki
	*
	*\param elem element umieszczany na końcu
	*/
	void push(Element<T>* elem);
	/**
	\brief
	Wywołuje destruktor klasy bazowej
	*/
	virtual ~Queue(){};
};

}

template <typename T>
ListImplementation::Queue<T>::Queue() :List<T>(){}

template <typename T>
Element<T>* ListImplementation::Queue<T>::pop() {
	return List<T>::pop(ListImplementation::Front);

}

template <typename T>
void ListImplementation::Queue<T>::push(Element<T>* elem) {
	List<T>::push(elem,ListImplementation::Back);

}

#endif /* LIST_QUEUE_H_ */
