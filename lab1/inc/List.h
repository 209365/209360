/**
*
\file
List.h
*
\brief
Plik zawierający definicje klasy List
*/


#ifndef LIST_H_
#define LIST_H_

#include "Container.h"

/**
\brief
Klasa reprezentująca liste dwukierunkową
*
*
Klasa reprezentuje implementacje listy dwukierunkowej
Dziedziczy po abstrakcyjnym kontenerze Container
Przechowuje dane typu element
*/
template <class T>
class List: Container{
public:
	List();
	virtual ~List();
};

#endif /* LIST_H_ */
