/**
*
\file
List.cpp
*
\brief
Definicja klasy List
*/
#include "../../inc/ArrayImplementation/List.h"

template <typename T>
unsigned int ArrayImplementation::List<T>::_MAX_SIZE=DEFAULT_MAX_SIZE;

template <typename T>
ArrayImplementation::List<T>::List() {
	_elements = new Element<T>[_MAX_SIZE];
	_numElements=0;

}
template <typename T>
ArrayImplementation::List<T>::List(unsigned int max_size) {
	List<T>::_MAX_SIZE=max_size;
	_elements = new Element<T>[_MAX_SIZE];
	_numElements=0;

}

template <typename T>
unsigned int ArrayImplementation::List<T>::size() {
	return _numElements;
}

template <typename T>
unsigned short ArrayImplementation::List<T>::isEmpty() {

	return (this->_numElements<=0);
}

template <typename T>
int ArrayImplementation::List<T>::push(Element<T>* elem, unsigned int index) {
	if(_numElements>=_MAX_SIZE) {
		std::cerr<<"Brak pamieci dla kolejnych elementow listy";
		return -1;
	}
	if((index<1) && (index>_numElements)) {
		std::cerr<<"Nieprawidlowy indeks dodawanego elementy do listy";
	}

	for (int pos = _numElements; pos >= index; pos--) {
	          _elements[pos] = _elements[pos-1];
	      }
	      _elements[index-1] = elem;
	      _numElements++;

}

template <typename T>
Element<T>* ArrayImplementation::List<T>::pop(unsigned int index) {
	if((index>=1) && (index<=_numElements) ){
		for (int pos = _numElements; pos >= index; pos--) {
			_elements[pos] = _elements[pos-1];

			  }
	      _numElements--;
		return _elements[index-1];
	}


}

template <typename T>
ArrayImplementation::List<T>::~List() {
	delete[] _elements;
}
