#include <stdio.h>

#define NUMBER_CONSECUTIVE 5

int numAtIndex(int index);
int bigNumberSize();

int main (int argc, const char * argv[]) {
	int result = 0;					//return max product
	int currentValue=1;				//current product
	int beg = 0;					//index of beginning of series
	int end = NUMBER_CONSECUTIVE-1; //index of end
	int zeros = 0;					//number of zeros in current series
	int begValue, endValue;			//actual values of beg and end
	
	//get initial product
	for (int i = 0; i <= end; i++) {
		if (numAtIndex(i) != 0) {
			currentValue *= numAtIndex(i);
		}else {
			zeros++;
		}
	}
	if (zeros == 0) {
		result = currentValue;
	}

	//iterate through rest of array
	//end is always one ahead of where it should be
	end++;
	for (end; end < bigNumberSize(); beg++, end++) {
		begValue = numAtIndex(beg);
		endValue = numAtIndex(end);
		
		if (begValue != 0) {
			currentValue /= begValue;
		}else {
			zeros--;
		}
		if (endValue != 0) {
			currentValue *= endValue;
		}else {
			zeros++;
		}

		if (currentValue > result && zeros == 0) {
			result = currentValue;
		}
	}
	printf("Result: %d\n", result);
    return 0;
}

unsigned char bigNumber[] = "\
73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";

int bigNumberSize(){
	return sizeof(bigNumber);
}

int numAtIndex(int index){
	int number;
	if (index >= sizeof(bigNumber)){
		return 0;
	}
	number = bigNumber[index] - '0';
	
	return number;
}




