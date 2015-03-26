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
#define DEFAULT_MAX_SIZE 1000
#include "../Element.h"
#include <iostream>

namespace ArrayImplementation {
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
	Element<T>* _elements;
	/**
	\brief
	Aktualna liczba elementów w liście
	*/
	unsigned int _numElements;

public:
	/**
	\brief
	Enumerator określający sposób powiększania się listy. Określa czy po zapełnieniu listy
	jej wielkość powinna zwiększyć się dwukrotnie, czy +1.
	*/
	enum Increase {Plus_1, Double};

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
	Element<T>* pop(unsigned int index);

	/**
	\brief
	dodaje element o indkesie index do listy
	*\pre Indeksowanie zaczyna się od 1
	*\param elem element umieszczany do listy
	*\param index określa pozycję na liście dodawanego elementu (numeracja od 1!)
	*\param inc określa sposób powiększania się listy w razie braku miejsca
	*\return zwraca -1 gdy operacja się niepowiodła
	*/
	int push(Element<T>* elem, unsigned int index, Increase inc);

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

}


#endif /* ARRAY_LIST_H_*/
