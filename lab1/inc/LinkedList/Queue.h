/**
*
\file
Queue.h
*
\brief
Deklaracja i definicja klasy Queue
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include "List.h"

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


template <typename T>
Queue<T>::Queue() :List<T>(){}

template <typename T>
Element<T>* Queue<T>::pop() {
	return List<T>::pop(List<T>::Front);

}

template <typename T>
void Queue<T>::push(Element<T>* elem) {
	List<T>::push(elem,List<T>::Back);

}

/*test*/


#endif /* QUEUE_H_ */
