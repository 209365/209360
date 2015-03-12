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
Czas wykonywania algorytmu
*
Program realizuje mnożenie określonej liczby elementów tablicy przez dwa
i wyznacza czas tej operacji.
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

 \latexonly
 \newpage
 \section{Wykres przyrostu czasu od ilości danych wejściowych}
 \begin{center}
 \includegraphics[scale=0.7]{wykres.png}
  \end{center}
  \begin{flushleft}
 Przebieg zależności czasu wykonywania programu od ilości danych wejściowych n
 zachowuję się w bardzo dużym przybliżeniu liniowy kształt. Na tej podstawie możemy
 stwierdzić, że jest to algorytm o złożoności 0(n), co było proste do przewidzenia
 z powodu jednej operacji arytmetycznej w pętli. Mnożenie przez dwa jest szczególnie podstawową
 operacją dla procesora z powodu możliwości jej optymalizacji za pomocą przesunięcia bitowego
 w lewo. Największy istotny przyrost czasu można zauważyć przy
 liczbie danych wejściowych większych od 1 000 000. Na tej podstawie można stwierdzić, że należy unikać
 tego typu rozwiązań w programach nawet dla problemów o złożoności O(n).

 Otrzymane wyniki:
 \begin{equation}
 10^{1} :0.0004
\end{equation}
\begin{equation}
 10^{2} :0.0007
 \end{equation}
\begin{equation}
 10^{3} :0.003
 \end{equation}
\begin{equation}
 10^{4} :0.026
 \end{equation}
\begin{equation}
 10^{5} :0.255
 \end{equation}
\begin{equation}
 10^{6} :2.5345
 \end{equation}
\begin{equation}
 10^{7} :25.4004
 \end{equation}
 \end{flushleft}
 \endlatexonly
*/

#include <iostream>
#include "../inc/timer.h"
#include "../inc/doubleNumbers.h"
#include <math.h>

using namespace std;


int main() {
	/**
	\brief
	liczba określająca z jakiej liczby pomiarów będzie brana średnia
	*/
	unsigned int average = 10;
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

	for(unsigned int i=0;i<pow_problem_size;i++) {
		results[i]=0; //zerowanie tablicy
	}

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

	for(unsigned int j=0;j<average;j++) { // dla dokładności wyników obliczana jest średnia wyników

	for(unsigned int i=0; i< pow_problem_size; i++) {

	timer.startTimer();
	numb.multiplyByTwo(test_numbers[i]);
	timer.stopTimer();

	results[i] += timer.diffTimeMs();

		}
	}

	for(unsigned int i=0;i<average;i++) {
		results[i]/=average;
	}

	cout<<"Sredni czas wykonania operacji dla tablic o rozmiarach 10^(0...7) w ms: \n";
	for(unsigned int i=0;i<pow_problem_size;i++) {
		cout<<"10^"<<i<<" :"<<results[i]<<"\n"; // wyświetlenie czasów
	}

}

