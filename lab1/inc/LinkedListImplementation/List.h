/**
*
\file
List.h
*
\brief
Deklaracja klasy List
*/
#ifndef COINTAINER_H_
#define COINTAINER_H_

#include "../Element.h"
#include <iostream>

namespace ListImplementation {
/**
\brief
Klasa reprezentująca podstawy konterner danych z którego korzystają inne - Listę
*
*
Klasa reprezentująca podstawy kontener - listę. Jest to podstawowa implementacja
listy stanowiąca klase bazową dla listy, stosu i kolejki
*/
template <class T>
class List {
private:
	/**
	\brief
	Wskaźnik na pierwszy element listy
	*/
	Element<T>* _head;
	/**
	\brief
	Wskaźnik na ostatni element listy
	*/
	Element<T>* _tail;

	/**
	\brief
	Rozmiar kontenera
	*/
	unsigned int _size;

public:
	/**
	\brief
	Enumerator przekazywany do funckji push w celu określenia, czy umieszczamy element
	na początku lub na końcu listy [na początku (Front), czy na końcu (Back), None - domyślne dla kontenera]
	*/
	enum Direction {Front, Back};
	/**
	\brief
	Konstruktor zerujący pola klasy i przydzielający pamięć na _head i _tail
	*/
	List();

	/**
	\brief
	zwraca element z początku(zależy od użytej struktury danych) listy
	*
	* \param dir określa czy zdjąć element z początku (Front), czy z końca (Back) listy
	*\return element będący na początku/końcu listy
	*/
	Element<T>* pop(Direction dir);

	/**
	\brief
	dodaje element na początek/koniec(zależy od implementacji) listy
	*
	*\param elem element umieszczany na początku/końcu listy
	*\param dir określa czy włożyć element na początek(Front), na koniec (Back) listy
	*/
	void push(Element<T>* elem, Direction dir);

	/**
	\brief
	zwraca rozmiar użytej struktury danych
	*
	*\return rozmiar użytej struktury danych
	*/
	unsigned int size();

	/**
	\brief
	zwraca 1, gdy kontener jest pusty, 0 - gdy jest już jakiś element
	*
	*\return zwraca informacje, czy w kontenerze są już jakieś elementy
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

}

#endif /* COINTAINER_H_ */
