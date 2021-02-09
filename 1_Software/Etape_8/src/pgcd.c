#include "pgcd.h"

int PGCD(int A, int B)
{

	assert(A >= 0 && A <= MAX_VALUE);
	assert(B >= 0 && B <= MAX_VALUE);

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
