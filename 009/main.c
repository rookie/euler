#include <stdio.h>

#define NUMBER 1000

int main (int argc, const char * argv[]) {
	int result = 0;
	int a,b,c;
	
	for (a=1; a<NUMBER/3+1; a++) {
		for (b=a+1; b<NUMBER-a+1; b++) {
			for (c=b+1; c<NUMBER-a-b+1; c++) {
				if (a+c+b == NUMBER) {
					if (a*a+b*b==c*c) {
						printf("%d, %d, %d\n", a,b,c);
						result = a*b*c;
						break;
					}
				}
			}
			if (result != 0)
				break;
		}
		if (result != 0)
			break;
	}
	
	printf("Result: %d\n", result);
    return 0;
}