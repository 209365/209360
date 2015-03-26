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
test
\end{flushleft}
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
	unsigned int problem_size_power = 8;

	Benchmark<int> bench(problem_size_power);

	ListImplementation::List<int>* list = new ListImplementation::List<int>();
	ListImplementation::Queue<int>* list_queue = new ListImplementation::Queue<int>();
	ListImplementation::Stack<int>* list_stack = new ListImplementation::Stack<int>();

	ArrayImplementation::List<int>* array_list_x2 = new ArrayImplementation::List<int>();
	ArrayImplementation::Queue<int>* array_queue_x2 = new ArrayImplementation::Queue<int>();
	ArrayImplementation::Stack<int>* array_stack_x2 = new ArrayImplementation::Stack<int>();

	ArrayImplementation::List<int>* array_list_1 = new ArrayImplementation::List<int>();
	ArrayImplementation::Queue<int>* array_queue_1 = new ArrayImplementation::Queue<int>();
	ArrayImplementation::Stack<int>* array_stack_1 = new ArrayImplementation::Stack<int>();

	bench.testList(list);
	bench.testList(array_list_x2, ArrayImplementation::Double);
	bench.testList(array_list_1, ArrayImplementation::Plus_1);

	bench.testQueue(list_queue);
	bench.testQueue(array_queue_x2, ArrayImplementation::Double);
	bench.testQueue(array_queue_1, ArrayImplementation::Plus_1);

	bench.testStack(list_stack);
	bench.testStack(array_stack_x2, ArrayImplementation::Double);
	bench.testStack(array_stack_1, ArrayImplementation::Plus_1);


	return 0;
}
/*test*/

