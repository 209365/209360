/**
*
\file
Stack.h
*
\brief
Deklaracja i definicja klasy Stack w wersji tablicowej
*/

#ifndef ARRAY_STACK_H_
#define ARRAY_STACK_H_
#define DEFAULT_MAX_SIZE 1
#include "List.h"
#include "../Element.h"
#include "Increase.h"

namespace ArrayImplementation {
/**
\brief
Klasa reprezentująca podstawy konterner danych - stos w implementacji tablicowej
*
*
Stos jest strukturą danych typu typu FIFO, Frist In, First Out; pierwszy na wejściu, pierwszy na wyjściu
*/
template <class T>
class Stack {
private:
	/**
	\brief
	Wskaźnik tablicy przechowującej wskaźniki wskazujące na zawarte elementy
	*/
	T** _elements;
	/**
	\brief
	Indeks elementu będącego na wierzchu stosu
	*/
	int _top;
	/**
	\brief
	Maksymalny rozmiar listy
	*/
	static unsigned int _MAX_SIZE;
public:
	/**
	\brief
	Konstruktor przydzielający pamieć na stos w ilości _MAX_SIZE oraz zerujący szczyt stosu
	*/
	Stack();
	/**
	\brief
	Konstruktor przydzielający pamieć na stos w ilości max_size oraz zerujący szczyt stosu
	\param max_size maksymalna liczba elementów na stosie
	*/
	Stack(int max_size);

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
	*\param inc określa sposób powiększania się stosu w razie braku miejsca
	*/
	void push(T* elem, Increase inc);

	/**
	\brief
	zwraca aktualny rozmiar stosu
	*
	*\return rozmiar stosu
	*/
	int size();

	/**
	\brief
	zwraca 1, gdy stos jest pusty. 0, gdy są jakieś elementy
	*
	*\return zwraca informacje, czy na stosie są jakieś elementy
	*/
	unsigned short isEmpty();

	/**
	\brief
	Destruktor usuwa pamięc po tablicy _elements
	*/
	~Stack();
};

}


template <typename T>
unsigned int ArrayImplementation::Stack<T>::_MAX_SIZE=DEFAULT_MAX_SIZE;

template <typename T>
ArrayImplementation::Stack<T>::Stack() {
	_elements = new T*[_MAX_SIZE];
	_top=0;
}
template <typename T>
ArrayImplementation::Stack<T>::Stack(int max_size){
	_MAX_SIZE=max_size;
	_elements = new T*[_MAX_SIZE];
	_top=0;
}

template <typename T>
Element<T>* ArrayImplementation::Stack<T>::pop() {
	if(_top<0) {
		std::cerr<<"Brak elementow na liscie";
	}
	else {
		return _elements[_top--];
	}
}

template <typename T>
void ArrayImplementation::Stack<T>::push(T* elem, Increase inc) {
	if(_top>=_MAX_SIZE) {
		if(inc == Plus_1) {
				_MAX_SIZE++;
				T** temp = new T*[_MAX_SIZE];
				for(int i=0;i<_top;i++) {
					temp[i]=_elements[i];
				}
				delete[] _elements;
				_elements=temp;
				//std::cerr<<"Stos powiększony o 1 \n";

				}

			if(inc == Double) {
				_MAX_SIZE*=2;
				T** temp = new T*[_MAX_SIZE];
				for(int i=0;i<_top;i++) {
					temp[i]=_elements[i];
				}
				delete[] _elements;
				_elements=temp;
				//std::cerr<<"Stos powiększony dwukrotnie \n";
			}
	}
	_elements[_top++]=elem;
}

template <typename T>
int ArrayImplementation::Stack<T>::size() {
	return (_top+1);
}

template <typename T>
unsigned short ArrayImplementation::Stack<T>::isEmpty() {

	return (this->_top<0);
}

template <typename T>
ArrayImplementation::Stack<T>::~Stack() {
	delete[] _elements;
}


#endif /* ARRAY_STACK_H_ */
