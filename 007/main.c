#include <stdio.h>

//bool declarations
typedef unsigned char BOOL;
#define YES 1
#define NO  0

BOOL isPrime(int number);
int primeAtIndex(int index);


#define MAX_PRIMES 10001     //max size of primes array


int main (int argc, const char * argv[]) {
	int result = 0;
	
	for (int i = 3; ; i+=2) {
		isPrime(i);
		if (primeAtIndex(MAX_PRIMES-1) != 0) {
			break;
		}
	}
	
	result = primeAtIndex(MAX_PRIMES-1);
	
	printf("Result: %d\n", result);
    return 0;
}


int primes[MAX_PRIMES] = {2,0};

int primeAtIndex(int index){
	int prime = 0;
	if (index < sizeof(primes)) {
		prime = primes[index];
	}
	return prime;
}

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