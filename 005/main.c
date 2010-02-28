#include <stdio.h>

//bool declarations
typedef unsigned char BOOL;
#define YES 1
#define NO  0

#define MAX_NUMBER 20

int bruteForce();
int smartAnswer();

int main (int argc, const char * argv[]) {
	int result = 0;

	result = smartAnswer();
	
	printf("Result: %d\n", result);
    return 0;
}

int factors[1000] = {0};
int smartAnswer(){
	int result = 1;
	int i,j;
	int factor;
	
	for (i = 2; i <= MAX_NUMBER; i++) {
		if (result % i != 0) {
			//remove previous factors
			j = 0;
			factor = i;
			while (factors[j] != 0) {
				//if one of its factors is already in the table
				//   divide it out
				if ((factor % factors[j]) == 0) {
					factor /= factors[j];
				}
				j++;
			}
			//add the factor that is missing
			factors[j] = factor;
			//reset the result
			result = 1;
			for (j = 0; factors[j] != 0; j++) {
				result *= factors[j];
			}
		}
	}
	
	return result;
}

int bruteForce(){
	int result = 0;
	int fail;
	int j;
	for (int i = 1; ; i++) {
		fail = NO;
		for (j = MAX_NUMBER; j >= 3; j--) {
			if ((i%j) != 0) {
				fail = YES;
				break;
			}
		}
		if (fail == NO) {
			result = i;
			break;
		}
	}
	return result;
}
