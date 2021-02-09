#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "assert.h"
#include "time.h"

#define MAX_VALUE	65536
#define MAX_TEST	2000

int PGCD(int A, int B)
{

	assert(A >= 0 && A <= MAX_VALUE);
	assert(B >= 0 && B <= MAX_VALUE);

	if(A == 0)
	{
		printf("PGCD between A and B is %d\n", B);
		return B;
	}

	if(B == 0)
	{
		printf("PGCD between A and B is %d\n", A);
		return A;
	}

	while(A != B){
		if(A > B){
			A = A - B;
		}
		else
		B = B - A;
	}
	printf("PGCD between A and B is %d\n", A);

	return A;
}

int RandA()
{
	int value = rand() % MAX_VALUE;
	printf("Random A is %d\n", value);
	return value;
}

int RandB()
{
	int value = rand() % MAX_VALUE;
	printf("Random B is %d\n", value);
	return value;
}

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");

	srand(time(NULL));

	for(int nb_test = 0; nb_test < MAX_TEST; nb_test++)
	{
		int A = RandA();
		int B = RandB();
		int pgcd = PGCD(A, B);

		assert(pgcd > 0);
		assert(pgcd <= A && pgcd <= B);
	}

	printf("(II) End of PGCD program\n");
  return 0;
}
