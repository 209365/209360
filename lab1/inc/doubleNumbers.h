#ifndef DOUBLENUMBERS_H_
#define DOUBLENUMBERS_H_

#include <vector>

class doubleNumbers {
private:
	unsigned long long _size;
	unsigned long long* _numbers;
public:
	doubleNumbers();
	doubleNumbers(unsigned long long size);
	void multiplyByTwo(unsigned long long number);
	void loadRandomNumbers();
};




#endif /* DOUBLENUMBERS_H_ */
