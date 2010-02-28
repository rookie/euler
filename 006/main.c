#include <stdio.h>

#define NUMBERS 100

int main (int argc, const char * argv[]) {
	int result;
	int sumOfSquare = 0;
	int squareOfSum = 0;
	
	for (int i = 1; i <= NUMBERS; i++) {
		sumOfSquare += i*i;
		squareOfSum += i;
	}
	//square the sum
	squareOfSum *= squareOfSum;
	
	result = squareOfSum - sumOfSquare;
	
	printf("Result: %d\n", result);
    return 0;
}
