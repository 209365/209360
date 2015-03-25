/**
*
\file
Stack.h
*
\brief
Deklaracja i definicja klasy Stack
*/

#ifndef Stack_H_
#define Stack_H_

#include "List.h"
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

template <typename T>
Stack<T>::Stack() :List<T>(){}

template <typename T>
Element<T>* Stack<T>::pop() {
	return List<T>::pop(List<T>::Front);

}

template <typename T>
void Stack<T>::push(Element<T>* elem) {
	List<T>::push(elem,List<T>::Front);
}
/*test*/

#endif /* Stack_H_ */
