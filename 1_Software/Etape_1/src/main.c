#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "assert.h"

int PGCD(int A, int B)
{
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

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");

	PGCD(65535, 1);				// valeurs de saturation
	PGCD(1, 65535);
	PGCD(65534, 65535);
	PGCD(7, 13);					// nombres premiers
	PGCD(26, 8080);				// nombres pairs
	PGCD(25, 7101);				// nombres impaires
	PGCD(42, 42);					// nombres identiques
	PGCD(24000, 700);			// différentes valeurs de PGCD
	PGCD(59605, 20);
	PGCD(4, 60004);
	PGCD(8888, 8);

	printf("(II) End of PGCD program\n");
  return 0;
}
