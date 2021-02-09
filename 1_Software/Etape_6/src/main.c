#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "assert.h"
#include "time.h"
#include "pgcd.h"

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

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");

	srand(time(NULL));

	for(int nb_test = 0; nb_test < MAX_TEST; nb_test++)
	{
		int A = RandA();
		int B = RandB();

		assert(PGCD(A, B) == PGCD_TEST(A, B));
		assert(PGCD(A, B) > 0 && PGCD_TEST(A, B) > 0);
		assert(PGCD(A, B) <= A && PGCD(A, B) <= B);
		assert(PGCD_TEST(A, B) <= A && PGCD_TEST(A, B) <= B);
	}

	printf("(II) End of PGCD program\n");
  return 0;
}
