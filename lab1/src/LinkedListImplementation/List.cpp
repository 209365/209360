/**
*
\file
List.cpp
*
\brief
Definicja klasy List
*/
#include "../../inc/LinkedListImplementation/List.h"

template <typename T>
ListImplementation::List<T>::List() {
	this->_size = 0;
	_head = new Element<T>(NULL);
	_tail = new Element<T>(NULL);
}

template <typename T>
unsigned int ListImplementation::List<T>::size() {
	return _size;
}

template <typename T>
unsigned short ListImplementation::List<T>::isEmpty() {

	return (this->_size<=0);
}

template <typename T>
void ListImplementation::List<T>::push(Element<T>* elem, Direction dir) {

	if(dir == Back) {
		if(_tail)
			_tail->setNext(elem);
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
Element<T>* ListImplementation::List<T>::pop(Direction dir) {
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
ListImplementation::List<T>::~List() {
    Element<T>* elem;
	while(_head)
    {
      elem = (Element<T>*)_head->next();
      delete _head;
      _head = elem;
    }
}
