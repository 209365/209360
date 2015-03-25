/**
*
\file
List.h
*
\brief
Deklaracja klasy Lista (w implementacji opartej na tablicy)
*/
#ifndef COINTAINER_H_
#define COINTAINER_H_

#include "../Element.h"
#include <iostream>

/**
\brief
Klasa reprezentująca podstawy konterner danych z którego korzystają inne - Listę zaimplementowaną na tablicy
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
	Wskaźnik tablicy przechowującej elementy zawarte w liście
	*/
	Element* _elements;
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
	List<T>::List(unsigned int max_size);

	/**
	\brief
	zwraca element o indeksie określonej przez parametr index (równocześnie usuwając go z listy)
	*
	* \param index określa indeks elementu znajdującego się na liście, który zostanie zwrócony
	*\return element listy o pozycji index
	*/
	Element<T>* pop(unsigned int index);

	/**
	\brief
	dodaje element o indkesie index do listy
	*\pre Indeksowanie zaczyna się od 1
	*\param elem element umieszczany do listy
	*\param index określa pozycję na liście dodawanego elementu (numeracja od 1!)
	*/
	int push(Element<T>* elem, unsigned int index);

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
	*wirtualny destruktor czyszczący liste
	*
	*Destruktor usuwawa wszystkie elementy z listy
	*/
	virtual ~List();
};
template <typename T>
static unsigned int List<T>::_MAX_SIZE=1000000;

template <typename T>
List<T>::List() {
	_elements = new Element[_MAX_SIZE];
	_numElements=0;

}
template <typename T>
List<T>::List(unsigned int max_size) {
	List<T>::_MAX_SIZE=max_size;
	_elements = new Element[_MAX_SIZE];
	_numElements=0;

}

template <typename T>
unsigned int List<T>::size() {
	return _numElements;
}

template <typename T>
unsigned short List<T>::isEmpty() {

	return (this->_numElements<=0);
}

template <typename T>
int List<T>::push(Element<T>* elem, unsigned int index) {
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
Element<T>* List<T>::pop(unsigned int index) {
	if((index>=1) && (index<=_numElements) ){
		for (int pos = _numElements; pos >= index; pos--) {
			_elements[pos] = _elements[pos-1];

			  }
	      _numElements--;
		return _elements[index-1];
	}


}

template <typename T>
List<T>::~List() {
	for(int i=0;i<_numElements;i++) {
		delete _elements[i];
	}
	delete[] _elements;
}
/*test*/


#endif /* COINTAINER_H_ */
