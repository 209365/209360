/**
*
\file
Container.cpp
*
\brief
Definicje metod klasy Container
*/
 *
 *  Created on: 17-03-2015
 *      Author: mateusz
 */

#include "../inc/Container.h"
#include <stddef.h>

template <typename T>
Container<T>::Container() {
	this->_elem = NULL;
	this->_size = 0;
}

template <typename T>
unsigned int Container<T>::size() {
	return _size;
}

template <typename T>
unsigned short Container<T>::isEmpty() {

	return (this->_size<=0);
}



