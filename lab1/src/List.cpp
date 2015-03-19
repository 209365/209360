/**
*
\file
List.cpp
*
\brief
Definicje metod klasy List
*/


#include "../inc/List.h"
#include <stddef.h>
#include <iostream>
/*
template <typename T>
List<T>::List() : Container<T>(){
	_head = new Element<T>;
	_tail = new Element<T>;

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
*/
