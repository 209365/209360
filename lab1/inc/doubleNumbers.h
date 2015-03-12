/**
*
\file
doubleNumbers.h
*
\brief
Plik zawierający deklaracje klasy doubleNumbers.
*/
#ifndef DOUBLENUMBERS_H_
#define DOUBLENUMBERS_H_

/**
\brief
Klasa do wykonania testowych obliczeń mnożenia elemetów tablicy przez 2.
*
*
Klasa pozwala na wylosowanie zadanej ilości liczb oraz pomnożenie przez 2 danej części z nich.
*/
class doubleNumbers {
private:
	/**
	\brief
	Maksymalny rozmiar tablicy.
	*/
	unsigned long long _size;

	/**
	\brief
	Wskaźnik do tablicy na której elementach będzie przeprowadzana operacja mnożenia przez 2.
	*/
	unsigned long long* _numbers;
public:
	/**
	\brief
	Konstruktor domyślny ustawiający maksymalną liczbę tablicy na 10^6
	oraz wczytujacy czas systemowy potrzeby do losowania liczb.
	*/
	doubleNumbers();

	/**
	\brief
	Konstruktor przyjmujący maksymalną wielkość tablicy
	oraz wczytujacy czas systemowy potrzeby do losowania liczb.
	*
	\param size maksymalny rozmiar tablicy
	*/
	doubleNumbers(unsigned long long size);

	/**
	\brief
	Metoda wykonująca operacje mnożenia przez 2 dla określonej liczby elementów tablicy.
	*
	Liczba mnożonych elementów tablicy jest determinowana przez parametr number.
	*
	\param number określa cześć tablicy poddanej operacji mnożenia przez 2.
	*/
	void multiplyByTwo(unsigned long long number);

	/**
	 \brief
	 Metoda wczytująca losowe liczby do tablicy
	 *
	 \pre Konieczna do poprawnego działania metody instrukcja srand jest zawarta w konstruktorze.
	 */
	void loadRandomNumbers();

	/**
	 \brief
	 Destruktor zwalniający pamięć to tablicy _numbers.
	 */
	~doubleNumbers();
};




#endif /* DOUBLENUMBERS_H_ */
