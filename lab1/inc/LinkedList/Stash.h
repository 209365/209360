/**
*
\file
Stash.h
*
\brief
Deklaracja i definicja klasy Stash
*/

#ifndef STASH_H_
#define STASH_H_

#include "List.h"
/**
\brief
Klasa reprezentująca podstawy konterner danych - stos
*
*
Kolejka jest strukturą danych typu typu LIFO, Last In, First Out; ostatni na wejściu, pierwszy na wyjściu
*/
template <class T>
class Stash : List<T>{
public:
	/**
	\brief
	Konstruktor wywołujący konstruktor klasy bazowej List
	*/
	Stash();

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
	virtual ~Stash(){};
};

template <typename T>
Stash<T>::Stash() :List<T>(){}

template <typename T>
Element<T>* Stash<T>::pop() {
	return List<T>::pop(List<T>::Front);

}

template <typename T>
void Stash<T>::push(Element<T>* elem) {
	List<T>::push(elem,List<T>::Front);
}
/*test*/

#endif /* STASH_H_ */
