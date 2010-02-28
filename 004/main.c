#include <stdio.h>

typedef unsigned char BOOL;
#define YES 1
#define NO  0

BOOL isPalindrome(int number);

int main (int argc, const char * argv[]) {
	int result = 0;
	int potential = 0;
	
	int x = 999;
	int y = 999;
	
	for (x = 999; x>0; x--) {
		for (y = 999; y>=0; y--) {
			potential = x*y;		
			if (isPalindrome(potential)) {
				if (potential > result) {
					result = potential;
				}
			}
		}
	}
	printf("Result: %d\n", result);
	return 0;
}


int numberOfDigits(int number){
	int digits = 1;
	
	if (number == 0) {
		digits = 0;
	}else
	while (number /= 10) {
		digits++;
	}
	
	return digits;
}

BOOL isPalindrome(int number){
	int multiplier = 1;
	int digits;
	BOOL palindrome;
	
	//get number of digits to calculate initial multiplier
	digits = numberOfDigits(number);
	for (int i = 1; i<digits; i++) {
		multiplier *= 10;
	}
	palindrome = YES;
	while (digits > 2){
		//check if high digit and low digit are same
		if (number/multiplier != number%10) {
			palindrome = NO;
			break;
		}
		digits -= 2;			 //remove 2 matching new digits
		multiplier /= 100;		 //calc new multiplier
		number /= 10;			 //shift out low digit
		number %= multiplier*10; //cut off high digit
	};
	
	//check that last two digits are the same
	if (digits == 2) {
		if ((number % 10) == (number / 10)) {
			palindrome = YES;
		}else {
			palindrome = NO;
		}
	}
	
	return palindrome;
}








