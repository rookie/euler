#include <stdio.h>

int main (int argc, const char * argv[]) {
	int result = 0;
	
	int prev2 = 0;
	int prev1 = 1;
	int cur  = 1;
	
	while (cur < 4000000) {
		if (cur % 2 == 0) {
			result += cur;
		}
		//printf("%d\n", cur);
		prev2 = prev1;
		prev1 = cur;
		cur = prev1 + prev2;
	}
	
	printf("Result: %d\n", result);
    return 0;
}
