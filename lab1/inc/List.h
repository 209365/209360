/**
*
\file
List.h
*
\brief
Plik zawierający definicje klasy List
*/


#ifndef LIST_H_
#define LIST_H_

#include "Container.h"
#include "Element.h"
#include <iostream>
/**
\brief
Klasa reprezentująca liste dwukierunkową
*
*
Klasa reprezentuje implementacje listy dwukierunkowej
Dziedziczy po abstrakcyjnym kontenerze Container
Przechowuje dane typu element
*/
template <class T>
class List : public Container<T> {
private:
	/**
	\brief
	Wskaźnik na pierwszy element listy
	*/
	Element<T>* _head;
	/**
	\brief
	Wskaźnik na ostatni element listy
	*/
	Element<T>* _tail;

public:
	/**
	\brief
	Enumerator przekazywany do funckji push w celu określenia, czy umieszczamy elemnt
	na początku lub na końcu listy [na początku (Front), czy na końcu (Back)]
	*/
	enum Direction {Front, Back};

	/**
	\brief
	Konstruktor alokujący pamięć na pola klasy
	*/
	List();

	/**
	\brief
	dodaje element na początek lub koniec listy
	*
	*\param elem element umieszczany w kontenerze
	*\param dir enum określający czy umieśnić elemnt na początku (Front), czy na końcu (Back), NULL, kiedy brak
	*/
	void push(const Element<T>* elem, Direction dir);

	/**
	\brief
	pobiera element z początku lub konica listy
	*
	*\param dir enum określający z zwrócić element z początku (Front), czy z konca (Back) listy, NULL, kiedy brak
	*/
	Element<T>* pop(Direction dir) const;

	/**
	\brief
	*zwalnianie pamięci po elemetach listy
	*
	*Destruktor zapewniający zwalnianie wszystkich elementów przechowywanych przez liste
	*/
	virtual ~List();
};

template <typename T>
List<T>::List() : Container<T>(){
	_head = new Element<T>(NULL);
	_tail = new Element<T>(NULL);

}

template <typename T>
void List<T>::push(const Element<T>* elem, Direction dir) {

	if(dir == Back) {
		if(_tail)
			_tail->_next=elem;
		elem->setNext(NULL);
		elem->setPrev(_tail);
		_tail=elem;
		if(!_head)
			_head=_tail;
		this->_size++;

	}

	else if(dir == Front) {
		elem->setNext(_head);
		elem->setPrev(NULL);
		if(_head)
			_head->setPrev(elem);
		if(!_tail)
			_tail = _head;
		this->_size++;
	}

	else {
		std::cerr<<"Blad zadania miejsca umieszczenia elementu na liscie";
	}

}

template <typename T>
Element<T>* List<T>::pop(Direction dir) const {
	if(dir == Back) {
		Element<T>* elem;
		if(_tail) {
			elem = _tail;
			if(elem == _head)
				_head = _tail = NULL;
			else {
				_tail = _tail->prev();
				_tail->setNext(NULL);
			}
			this->_size--;
			return elem;
		}
		else
			return NULL;
	}

	else if(dir == Front) {
		Element<T>* elem;
		if(_head) {
			elem = _head;
			_head = _head->next();
			if(!_head)
				_tail=NULL;
			else
				_head->setPrev(NULL);
			this->_size--;
			return elem;
		}
		else
			return NULL;
	}

	else {
		std::cerr<<"Blad zadania miejsca pobrania elementu z listy";
	}

}

template <typename T>
List<T>::~List() {
    Element<T>* elem;
	while(_head)
    {
      elem = _head->next;
      delete _head;
      _head = elem;
}
}



#endif /* LIST_H_ */
