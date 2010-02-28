#include <stdio.h>

//bool declarations
typedef unsigned char BOOL;
#define YES 1
#define NO  0

//functions
BOOL isPrime(int number);

//settings
#define MAX_PRIMES 10000     //max size of primes array
#define MAX_NUMBER 10000     //max numbers to test
//#define PRINT_FACTORS        //if defined will print all factors

int main (int argc, const char * argv[]) {
	int result = 0;
	long long problem = 600851475143;
	printf("Start: %lld\n", problem);
	
	int i;
	for (i = 5; i < MAX_NUMBER; i+=2) {
		if (isPrime(i)) {
			//printf("%d: %d\n", i, isPrime(i));
			if (problem % i == 0) {
				problem = problem / i;
#ifdef PRINT_FACTORS
				printf("Factor: %d\n", i);
#endif
				if (problem == 1) {
					result = i;
					break;
				}
			}
		}
	}
	
	printf("Result: %d\n", result);
	return 0;
}

int primes[MAX_PRIMES] = {3,0};

BOOL isPrime(int number){
	int isItPrime = NO;
	int i = 0;
	
	//done when we get to the end of filled out numbers
	//		or the end of the array size
	while (primes[i] != 0 && i < MAX_PRIMES) {
		if (number % primes[i] == 0) {
			isItPrime = NO;
			break;
		}
		i++;
	}
	//make sure we arent past the end of the array
	if (i >= MAX_PRIMES) {
		isItPrime = NO;
	}else
	//found a new prime
	if (primes[i] == 0) {
		primes[i] = number;
		isItPrime = YES;
	}
	return isItPrime;
}
