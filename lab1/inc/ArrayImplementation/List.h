/**
*
\file
List.h
*
\brief
Deklaracja klasy Lista (w implementacji opartej na tablicy)
*/
#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_
#define DEFAULT_MAX_SIZE 1
#include "../Element.h"
#include "Increase.h"
#include <iostream>

namespace ArrayImplementation {
/**
\brief
Klasa reprezentująca podstawy konterner danych - Listę zaimplementowaną na tablicy
*
*
Klasa reprezentująca podstawy kontener - listę. Jest to implemetacja listy oparta na tablicy.
*/
template <class T>
class List {
private:
	/**
	\brief
	Maksymalny rozmiar listy
	*/
	static unsigned int _MAX_SIZE;
	/**
	\brief
	Wskaźnik do wskaźników przechowujących elementy listy
	*/
	T** _elements;
	/**
	\brief
	Aktualna liczba elementów w liście
	*/
	unsigned int _numElements;

public:
	/**
	\brief
	Konstruktor zerujący aktualny rozmiar i przydzielający pamięć tablicy przechowującej dane
	w ilości _MAX_SIZE
	*/
	List();

	/**
	\brief
	Konstruktor zerujący rozmiar i przydzielający pamięć tablicy przechowującej dane
	w ilości określonej przez parametr max_size
	\param max_size maksymalna liczba elementów w liście
	*/
	List(unsigned int max_size);

	/**
	\brief
	zwraca element o indeksie określonej przez parametr index (równocześnie usuwając go z listy)
	*
	* \param index określa indeks elementu znajdującego się na liście, który zostanie zwrócony
	*\return element listy o pozycji index
	*/
	T* pop(unsigned int index);

	/**
	\brief
	dodaje element o indkesie index do listy
	*\pre Indeksowanie zaczyna się od 1
	*\param elem element umieszczany do listy
	*\param index określa pozycję na liście dodawanego elementu (numeracja od 1!)
	*\param inc określa sposób powiększania się listy w razie braku miejsca
	*/
	void push(T* elem, unsigned int index, Increase inc);

	/**
	\brief
	zwraca aktualny rozmiar listy
	*
	*\return rozmiar listy
	*/
	unsigned int size();

	/**
	\brief
	zwraca 1, gdy lista jest pusta. 0, gdy są jakieś elementy
	*
	*\return zwraca informacje, czy w liście są jakieś elementy
	*/
	unsigned short isEmpty();

	/**
	\brief
	*destruktor czyszczący liste
	*
	*Destruktor usuwawa wszystkie elementy z listy
	*/
	~List();
};

}

template <typename T>
unsigned int ArrayImplementation::List<T>::_MAX_SIZE=DEFAULT_MAX_SIZE;

template <typename T>
ArrayImplementation::List<T>::List() {
	_elements = new T*[_MAX_SIZE];
	_numElements=0;

}
template <typename T>
ArrayImplementation::List<T>::List(unsigned int max_size) {
	List<T>::_MAX_SIZE=max_size;
	_elements = new T[_MAX_SIZE];
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
void ArrayImplementation::List<T>::push(T* elem, unsigned int index, Increase inc) {
	if(_numElements>=_MAX_SIZE) {
		if(inc == Plus_1) {
			_MAX_SIZE++;
			T** temp = new T*[_MAX_SIZE];
			for(int i=0;i<_numElements;i++) {
				temp[i]=_elements[i];
			}
			delete[] _elements;
			_elements=temp;
			//std::cerr<<"Lista powiększona o 1 \n";
		}
		if(inc == Double) {
			_MAX_SIZE*=2;
			T** temp = new T*[_MAX_SIZE];
			for(int i=0;i<_numElements;i++) {
				temp[i]=_elements[i];
			}
			delete[] _elements;
			_elements=temp;
			//std::cerr<<"Lista powiększona dwukrotnie \n";
		}
	}
	for (int pos = _numElements; pos >= index; pos--) {
	          _elements[pos] = _elements[pos-1];
	      }
	      _elements[index-1] = elem;
	      _numElements++;

}

template <typename T>
T* ArrayImplementation::List<T>::pop(unsigned int index) {
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



#endif /* ARRAY_LIST_H_*/
