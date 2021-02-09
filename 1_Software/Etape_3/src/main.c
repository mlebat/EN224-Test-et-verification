#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "assert.h"
#include "time.h"

#define MAX_VALUE	65536
#define MAX_TEST	(MAX_VALUE - 1)

int PGCD(int A, int B)
{
	if(A == 0)
	{
		//printf("PGCD between A and B is %d\n", B);
		return B;
	}

	if(B == 0)
	{
		//printf("PGCD between A and B is %d\n", A);
		return A;
	}

	while(A != B){
		if(A > B){
			A = A - B;
		}
		else
		B = B - A;
	}
	//printf("PGCD between A and B is %d\n", A);
	return A;
}

int PGCD_TEST(int A, int B)
{
    while (B != 0)
    {
        const int T = B;
        B = A%B;
        A = T;
    }
    return A;
}

int RandA()
{
	int value = rand() % MAX_VALUE;
	//printf("Random A is %d\n", value);
	return value;
}

int RandB()
{
	int value = rand() % MAX_VALUE;
	//printf("Random B is %d\n", value);
	return value;
}

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");

	srand(time(NULL));

	for(int nb_test = 0; nb_test < MAX_TEST; nb_test++)
	{
		int A = RandA();
		int B = RandB();

		int pgcd1 = PGCD(A, B);
		int pgcd2 = PGCD_TEST(A, B);

		if(pgcd1 != pgcd2)
		{
			printf("error\n");
		}

	}

	printf("(II) End of PGCD program\n");
  return 0;
}
