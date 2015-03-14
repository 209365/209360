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
Czas wykonywania algorytmu wykonującego podstawową operacje arytmetyczną.
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
 zachowuję w bardzo dużym przybliżeniu liniowy kształt. Na wykresie odzwierciedla to linia kreskowana,
 która jest linią trendu. Na tej podstawie możemy
 stwierdzić, że jest to algorytm o złożoności 0(n), co było proste do przewidzenia
 z powodu jednej, podstawowej operacji arytmetycznej powtarzanej w pętli n razy. Mnożenie przez dwa jest szczególnie szybką
 operacją dla procesora z powodu możliwości jej optymalizacji za pomocą przesunięcia bitowego
 w lewo. Największy istotny przyrost czasu można zauważyć przy
 liczbie danych wejściowych większych od 1 000 000. Sprawdzanie złożoności algorytmu metodą mierzenia
 czasu ma podstawową wadę: czas zależy od użytego sprzętu i obiążenia komputera w danym momencie.
 W związku z tym taki pomiar nie jest obiektytwny w sensie ilościowym.
 Z drugiej jednak strony metoda ta jest znaczenie prostsza od liczenia podstawowych operacji wykonywanych przez procesor
 oraz pozwala przewidzieć zachowanie funkcji tempa wzrostu w zależności od ilości danych wejściowych.
 \newline
 Dla zwiększenia wiarygodności pomiary zostały wykonane 10 razy i uśrednione.
 \newline
 Wyniki otrzymane na moim komputerze:
 \begin{equation}
 10^{0}: 0.0008
\end{equation}
\begin{equation}
 10^{1}: 0.0004
 \end{equation}
\begin{equation}
 10^{2}: 0.0007
 \end{equation}
\begin{equation}
 10^{3}: 0.003
 \end{equation}
\begin{equation}
 10^{4}: 0.026
 \end{equation}
\begin{equation}
 10^{5}: 0.255
 \end{equation}
\begin{equation}
 10^{6}: 2.5345
 \end{equation}
 \begin{equation}
 10^{7}: 25.4004
 \end{equation}
 \end{flushleft}
 \endlatexonly
*/

#include <iostream>
#include "../inc/timer.h"
#include <math.h>

using namespace std;


int main() {

}

