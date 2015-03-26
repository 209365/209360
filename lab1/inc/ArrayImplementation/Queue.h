/**
*
\file
Queue.h
*
\brief
Deklaracja i definicja klasy Queue
*/

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_
#define DEFAULT_MAX_SIZE 1
#include "../Element.h"
#include "Increase.h"

namespace ArrayImplementation {
/**
\brief
Klasa reprezentująca podstawy konterner danych kolejke zaimplementowaną na tablicy
*
*
Kolejka jest strukturą danych typu typu FIFO, First In, First Out; pierwszy na wejściu, pierwszy na wyjściu
*/
template <class T>
class Queue {
private:
	/**
	\brief
	Tablica wskaźników przechowująca wskaźniki na przechowywane dane
	*/
	T** _elements;
	/**
	\brief
	Indeks elementu na początku kolejki
	*/
	int _top;
	/**
	\brief
	Maksymalny rozmiar tablicy przechowującej elementy
	*/
	static unsigned int _MAX_SIZE;

public:
	/**
	\brief
	Konstruktor alokujący pamięć na kolejkę oraz zerujący indeks elementu na końcu kolejki
	*/
	Queue();

	/**
	\brief
	Konstruktor alokujący pamięć na kolejkę w ilości max_size oraz zerujący indeks elementu na końcu kolejki
	\param max_size maksymalna liczba elementów w kolejce
	*/
	Queue(unsigned int max_size);

	/**
	\brief
	zwraca element z początku kolejki
	*
	*\return element będący na początku kolejki
	*/
	T* pop();

	/**
	\brief
	dodaje element na koniec kolejki
	*
	*\param elem element umieszczany na końcu kolejki
	*\param inc określa sposób powiększania się kolejki w razie braku miejsca
	*/
	void push(T* elem, Increase inc);

	/**
	\brief
	Destruktor usuwa tablicę przechowującą elementy kolejki
	*/
	~Queue();
};

}


template <typename T>
unsigned int ArrayImplementation::Queue<T>::_MAX_SIZE=DEFAULT_MAX_SIZE;

template <typename T>
ArrayImplementation::Queue<T>::Queue() {
	_elements = new T*[_MAX_SIZE];
	_top=0;
}

template <typename T>
ArrayImplementation::Queue<T>::Queue(unsigned int max_size){
	_MAX_SIZE=max_size;
	_elements = new T*[_MAX_SIZE];
	_top=0;
}

template <typename T>
T* ArrayImplementation::Queue<T>::pop() {
	T* elem= _elements[0];
	for (int i=0;i<_top-1;i++)
	     _elements[i]= _elements[i+1];
	     _top--;
return elem;
}

template <typename T>
void ArrayImplementation::Queue<T>::push(T* elem, Increase inc) {
	if(_top>=_MAX_SIZE) {
		if(inc == Plus_1) {
		_MAX_SIZE++;
		T** temp = new T*[_MAX_SIZE];
		for(int i=0;i<_top;i++) {
			temp[i]=_elements[i];
		}
		delete[] _elements;
		_elements=temp;
		//std::cerr<<"Kolejka powiększona o 1 \n";

		}

	if(inc == Double) {
		_MAX_SIZE*=2;
		T** temp = new T*[_MAX_SIZE];
		for(int i=0;i<_top;i++) {
			temp[i]=_elements[i];
		}
		delete[] _elements;
		_elements=temp;
		//std::cerr<<"Lista powiększona dwukrotnie \n";
	}
	}
	_elements[_top++]=elem;

}

template <typename T>
ArrayImplementation::Queue<T>::~Queue() {
	delete[] _elements;
}

#endif /* ARRAY_QUEUE_H_ */
