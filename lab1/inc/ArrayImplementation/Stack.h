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
#define DEFAULT_MAX_SIZE 1000
#include "List.h"
#include "../Element.h"

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
	Wskaźnik tablicy przechowującej elementy zawarte w stosie
	*/
	Element<T>* _elements;
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
	Enumerator określający sposób powiększania się stosu. Określa czy po zapełnieniu stosu
	jej wielkość powinna zwiększyć się dwukrotnie, czy +1.
	*/
	enum Increase {Plus_1, Double};
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
	void push(Element<T>* elem, Increase inc);

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


#endif /* ARRAY_STACK_H_ */
