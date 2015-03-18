/**
*
\file
Container.h
*
\brief
Deklaracja klasy Cointainer
*/
#ifndef COINTAINER_H_
#define COINTAINER_H_

#include "Element.h"
/**
\brief
Klasa reprezentująca podstawy, abstrakcyjny konterner danych
*
*
Klasa reprezentująca podstawy, abstrakcyjny konterner danych. Jest to podstawowa implementacja
listy stanowiąca klase bazową dla listy, stosu i kolejki
*/
template <class T>
class Container {
private:
	/**
	\brief
	Wskaźnik na podstawowy pojemnik na dane typu T
	*/
	Element<T>* _elem;

	/**
	\brief
	Rozmiar kontenera
	*/
	unsigned int _size;
public:
	/**
	\brief
	Konstruktor zerujący pola klasy
	*/
	Container();

	/**
	\brief
	zwraca element z początku(zależy od użytej struktury danych) kontenera
	*
	* Metoda wirtualna - narzuca interfejs
	*\return element będący na początku kontenera danych
	*/
	virtual Element<T>* pop()=0;

	/**
	\brief
	dodaje element na początek(zalęży od implementacji) kontenera
	*
	* Metoda wirtualna - narzuca interfejs
	*\param element umieszczany na początku kontenera
	*/
	virtual Element<T>* push()=0;

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
	*wirtualny destruktor (w przypadku użycia szablonu, nie można zrobić jego implementacji)
	*/
	virtual ~Container();
};

#endif /* COINTAINER_H_ */
