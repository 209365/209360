/**
*
\file
Element.h
*
\brief
Deklaracja i definicja klasy Element
*/

#ifndef ELEMENT_H_
#define ELEMENT_H_
#include <stddef.h>
/**
\brief
Klasa reprezentująca abstrakcyjny "pojemnik na dane"
*
*
Klasa może przechowywać dane zdeterminowane przez typ szablonu, zawiera wskaźnik do kolejnego
i poprzedniego elementu (implementacja elementu listy).
*/
template <class T>
class Element {
private:
	/**
	\brief
	Wskaźnik na daną typu szablonu
	*/
	T* _data;
	/**
	\brief
	Wskaźnik na kolejny element listy
	*/
	Element<T>* _next;
	/**
	\brief
	Wskaźnik na poprzedni element listy
	*/
	Element<T>* _prev;
public:
	/**
	\brief
	Konstruktor zapamiętujący adres przechowywanego obiektu
	*
	*\param data obiekt/zmięnna do przechowania
	*/
	Element(T* data);

	/**
	\brief
	setter do przechowywanej danej
	*
	Metoda do ustawiania danej przechowywanej przez klase
	*
	*\data obiekt/zmięnna, która będzie przechowywana
	*/
	void setData(const T* data);

	/**
	\brief
	getter do przechowywanej danej
	*
	Metoda do pobrania wskaźnka przechowywanego danej
	*
	*\return wskaźnik do zmięnnej przechowywanej przez klase
	*/
	T* getData() const;

	/**
	\brief
	zwraca wskaźnik do kolejnego elementu na liście
	*
	*\return wskaźnik do kolejnego elementu na liście
	*/
	Element<T>* next() const;

	/**
	\brief
	zwraca wskaźnik do poprzedniego elementu na liście
	*
	*\return wskaźnik do poprzedniego elementu na liście
	*/
	Element<T>* prev() const;

	/**
	\brief
	ustawia kolejny element listy
	*
	*\param next kolejny element listy
	*/
	void setNext(Element<T>* next);

	/**
	\brief
	ustawia poprzedni element listy
	*
	*\param prev poprzedni element listy
	*/
	void setPrev(Element<T>* prev);
	/**
	\brief
	*zwalnianie elementu przechowywanego przez klase Element
	*
	*Destruktor zapewniający zwalnianie elementu przechowywanego przez klase Element
	*/
	~Element();
};

template <typename T>
Element<T>::Element(T* data) {
	this->_data=data;
	this->_prev=NULL;
	this->_next=NULL;

}

template <typename T>
void Element<T>::setData(const T* data) {
	this->_data=data;

}

template <typename T>
T* Element<T>::getData() const{
	return _data;

}

template <typename T>
Element<T>* Element<T>::next() const {
	return _next;
}

template <typename T>
Element<T>* Element<T>::prev() const {
	return _prev;
}

template <typename T>
void Element<T>::setNext(Element<T>* next) {
	_next=next;
}

template <typename T>
void Element<T>::setPrev(Element<T>* prev) {
	_prev=prev;
}

template <typename T>
Element<T>::~Element() {
	delete _data;
	_data = NULL;
	_prev = NULL;
	_next = NULL;
}


#endif /* ELEMENT_H_ */
