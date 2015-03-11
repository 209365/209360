#ifndef DOUBLENUMBERS_H_
#define DOUBLENUMBERS_H_

class doubleNumbers {
private:
	int _size;
	long* _numbers;
public:
	doubleNumbers();
	doubleNumbers(int size);
	void multiplyByTwo(int number);
	void loadRandomNumbers();
};




#endif /* DOUBLENUMBERS_H_ */
