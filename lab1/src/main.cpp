/**
*
\file
main.cpp
*
\brief
Plik zawierający sekwencje operacji do mierzenia czasu operacji mnożenia elementów tablicy przez 2.
*/
/**
*
\mainpage
*
\par
Czas wykonywania algorytmu
*
Program realizuje mnożenie określonej liczby elementów tablicy przez dwa
i wyznacza czas tej operacji
*
\author
Mateusz
Bencer
*
\date
2015.03.12
*
\version
1.0
*
\par
Mail:
*
\a
209360@pwr.wroc.edu.pl
*/

#include <iostream>
#include "../inc/timer.h"
#include "../inc/doubleNumbers.h"
#include <math.h>

using namespace std;


int main() {
	/**
	\brief
	Wykładnik rozmiaru problemu
	*/
	unsigned int pow_problem_size = 8;

	/**
	\brief
	Maksymalny rozmiar tablicy do testów
	*/
	unsigned long long int max_tab_size = pow(10, pow_problem_size);

	/**
	\brief
	Wielkości rozmiarów tablic, dla kórych trzeba zmierzyć czas obliczeń
	*/
	unsigned long long test_numbers[pow_problem_size];

	for(unsigned int i=0;i<pow_problem_size;i++) {
		test_numbers[i] = pow(10, i); // przygotowanie wielkosci tablic do wykonania obliczen testowych
	}

	/**
	\brief
	Czasy wykonania obliczeń dla danych wielkości tablicy.
	*/
	double results[pow_problem_size];

	/**
	\brief
	Obiekt do pamiaru różnicy czasu.
	*/
	Timer timer;
	/**
	\brief
	Obiekt do wykonywania operacji mnożenia tablicy przez 2.
	*/
	doubleNumbers numb(max_tab_size);
	numb.loadRandomNumbers();

	for(unsigned int i=0; i< pow_problem_size; i++) {

	timer.startTimer();
	numb.multiplyByTwo(test_numbers[i]);
	timer.stopTimer();

	results[i] = timer.diffTimeMs();

	}

	cout<<"Czas wykonania operacji dla tablic o rozmiarach 10^(1...8) w ms: \n";
	for(unsigned int i=0;i<pow_problem_size;i++) {
		cout<<i+1<<". "<<results[i]<<"\n"; // wyświetlenie czasów
	}

}
