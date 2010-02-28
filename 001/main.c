#include <stdio.h>

int main (int argc, const char * argv[]) {
	int result;
	int i;
	for (i=0; i<1000; i++) {
		if((i%3 == 0) || (i%5 == 0))
			result += i;
	}
	printf("Result: %d\n", result);
	return 0;
}
