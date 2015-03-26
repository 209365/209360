/**
*
\file
Queue.h
*
\brief
Deklaracja i definicja klasy Queue
*/

#ifndef QUEUE_H_
#define QUEUE_H_
#define DEFAULT_MAX_SIZE 1000
#include "../Element.h"

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
	Tablica zawierająca elementy (podstawowe "pojemniki danych")
	*/
	Element<T>* _elements;
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
	Enumerator określający sposób powiększania się kolejki. Określa czy po zapełnieniu kolejki
	jej wielkość powinna zwiększyć się dwukrotnie, czy +1.
	*/
	enum Increase {Plus_1, Double};

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
	Element<T>* pop();

	/**
	\brief
	dodaje element na koniec kolejki
	*
	*\param elem element umieszczany na końcu kolejki
	*\param inc określa sposób powiększania się kolejki w razie braku miejsca
	*/
	void push(Element<T>* elem, Increase inc);

	/**
	\brief
	Destruktor usuwa tablicę przechowującą elementy kolejki
	*/
	~Queue();
};

}

#endif /* QUEUE_H_ */
