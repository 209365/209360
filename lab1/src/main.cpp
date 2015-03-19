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
Czas wykonywania algorytmu wykonującego dodawanie elementów do podatawowych struktour danych
*
Program realizuje operacje dodawania n liczby elementów do listy, kolejki i stosu i mierzy czas tych operacji
*
\author
Mateusz
Bencer
*
\date
2015.03.19
*
\version
1.0
*
\par
Mail:
*
\a
209360@pwr.wroc.edu.pl

 \latexonly
 \newpage
  \begin{flushleft}
Wszystkie wykorzystane przeze mnie struktury danych, tj. kolejka oraz stos opierały się na implementacji listy
po której dziedziczyły. Wynikało to z uniwersalności listy dwukierunkowej dającej możliwość
dodawanie/ściągania elementów z początku oraz końca listy. W związku z takim podejściem
wyniki czasowe dodawania elementów (przyjąłem inty) do struktur są bardzo podobne,
co potwiedził dobitnie pomiar czasu. Wszystkie zaimplementowane przeze mnie struktury danych
są bardzo ogólne (oparte na szablonach i dziedziczeniu) w związku z czym mają szeroką gamme zastosowań.
Dla ilości danych powyżej 10 do pot. 7 terminal ubuntu automatycznie zabijał proces.
 \newline
 Wyniki otrzymane na moim komputerze:
 \newline
Lista:
 \begin{equation}
10^2: 0.046 ms
\end{equation}
 \begin{equation}
10^3: 0.558 ms
\end{equation}
 \begin{equation}
10^6: 142.849 ms
\end{equation}
 \begin{equation}
10^7: 1341.57 ms
\end{equation}

Kolejka:
 \begin{equation}
10^2: 0.037 ms
\end{equation}
 \begin{equation}
10^3: 0.572 ms
\end{equation}
 \begin{equation}
10^6: 136.441 ms
\end{equation}
 \begin{equation}
10^7: 1359.62 ms
\end{equation}

Stos:
 \begin{equation}
10^2: 0.031 ms
\end{equation}
 \begin{equation}
10^3: 0.525 ms
\end{equation}
 \begin{equation}
10^6: 133.504 ms
\end{equation}
 \begin{equation}
10^7: 1332.96 ms
\end{equation}
 \end{flushleft}
 \endlatexonly
*/

#include <iostream>
#include "../inc/Timer.h"
#include "../inc/List.h"
#include "../inc/Queue.h"
#include "../inc/Stash.h"
#include "../inc/Element.h"
#include <math.h>

using namespace std;

int main() {
	/**
	\brief
	liczba określająca wykładnik liczby elementów, które umieścimy w danej strukturze danych
	*/
	int n[] = {2,3, 6, 7};

	/**
	\brief
	ilość testowanych wielkości strukur danych
	*/
	int n_size = 4;

	/**
	\brief
	* reprezentacja (obiekt) listy przechowujący int'y
	*/
	List<int>* list = new List<int>();

	/**
	\brief
	* reprezentacja (obiekt) kolejki przechowujący int'y
	*/
	Queue<int>* queue = new Queue<int>();

	/**
	\brief
	* reprezentacja (obiekt) stosu przechowujący int'y
	*/
	Stash<int>* stash = new Stash<int>();

	/**
	\brief
	* wyniki pomiarów czasu dla listy
	*/
	double list_resoults[n_size];

	/**
	\brief
	* wyniki pomiarów czasu dla kolejki
	*/
	double queue_resoults[n_size];

	/**
	\brief
	* wyniki pomiarów czasu dla stosu
	*/
	double stash_resoults[n_size];

	/**
	\brief
	* czasomierz użyty do mierzenia czasu wypełniania struktur
	*/
	Timer timer;


		for(int j=0;j<n_size;j++) {
			timer.startTimer();
			for(int k=0;k<pow(10,n[j]);k++) {
				list->push(new Element<int>(new int), List<int>::Front);
			}
			timer.stopTimer();
			list_resoults[j]=timer.diffTimeMs();

			timer.startTimer();
			for(int k=0;k<pow(10,n[j]);k++) {
				queue->push(new Element<int>(new int));
			}
			timer.stopTimer();
			queue_resoults[j]=timer.diffTimeMs();

			timer.startTimer();
			for(int k=0;k<pow(10,n[j]);k++) {
				stash->push(new Element<int>(new int));
			}
			timer.stopTimer();
			stash_resoults[j]=timer.diffTimeMs();

		}

		cout<<"Wyniki: \n";
		cout<<"Lista: \n";
		for(int i=0;i<n_size;i++) {
			cout<<"10^"<<n[i]<<": "<<list_resoults[i]<<" ms \n";
		}
		cout<<"\n";
		cout<<"Kolejka: \n";
		for(int i=0;i<n_size;i++) {
			cout<<"10^"<<n[i]<<": "<<queue_resoults[i]<<" ms \n";
		}
		cout<<"\n";
		cout<<"Stos: \n";
		for(int i=0;i<n_size;i++) {
			cout<<"10^"<<n[i]<<": "<<stash_resoults[i]<<" ms \n";
		}


	return 0;
}

