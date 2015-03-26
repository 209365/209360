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

 \endlatexonly
*/

#include <iostream>
#include "../inc/LinkedListImplementation/List.h"
#include "../inc/LinkedListImplementation/Queue.h"
#include "../inc/LinkedListImplementation/Stack.h"

#include "../inc/ArrayImplementation/List.h"
#include "../inc/ArrayImplementation/Queue.h"
#include "../inc/ArrayImplementation/Stack.h"
#include "../inc/Benchmark.h"

using namespace std;

int main() {
	Benchmark<int> bench(2);
	//ListImplementation::List<int>* list = new ListImplementation::List<int>();
	//ListImplementation::Queue<int>* queue = new ListImplementation::Queue<int>();
	//ListImplementation::Stack<int>* stack = new ListImplementation::Stack<int>();
	//ArrayImplementation::List<int>* list = new ArrayImplementation::List<int>();
	//ArrayImplementation::Queue<int>* list = new ArrayImplementation::Queue<int>();
	ArrayImplementation::Stack<int>* stack = new ArrayImplementation::Stack<int>();
	bench.testStack(stack, ArrayImplementation::Double);

	return 0;
}
/*test*/

