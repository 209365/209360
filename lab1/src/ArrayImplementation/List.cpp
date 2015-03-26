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
int ArrayImplementation::List<T>::push(Element<T>* elem, unsigned int index, Increase inc) {
	if(_numElements>=_MAX_SIZE) {
		if(inc == Plus_1) {
			_MAX_SIZE++;
			Element<T>* temp = new Element<T>[_MAX_SIZE];
			for(int i=0;i<_numElements;i++) {
				temp[i]=_elements[i];
			}
			delete[] _elements;
			_elements=temp;
			std::cerr<<"Lista powiększona o 1 \n";
		}
		if(inc == Double) {
			_MAX_SIZE*=2;
			Element<T>* temp = new Element<T>[_MAX_SIZE];
			for(int i=0;i<_numElements;i++) {
				temp[i]=_elements[i];
			}
			delete[] _elements;
			_elements=temp;
			std::cerr<<"Lista powiększona dwukrotnie \n";
		}
	}
	if((index<1) && (index>_numElements)) {
		std::cerr<<"Nieprawidlowy indeks dodawanego elementy do listy";
		return -1;
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
