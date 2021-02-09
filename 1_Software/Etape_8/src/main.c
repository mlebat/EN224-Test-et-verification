#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "assert.h"
#include "time.h"
#include "pgcd.h"

//#include <sys/types.h>
//#include <sys/stat.h>
//#include <unistd.h>
//#include <fcntl.h>
#include <errno.h>

void exit_if(int condition, const char *prefix)
{
    if (condition) {
        perror(prefix);
        exit(1);
    }
}

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");

	char chA[MAX_VALUE] = {};
	char chB[MAX_VALUE] = {};
	char resultat[MAX_VALUE] = {};

	/* File ref_A.txt */
	FILE *file_A = fopen("./src/ref_A.txt", "r");
	exit_if(file_A == NULL, "Error opening ref_A.txt\n");

	int A[MAX_VALUE] = {};

	int n = 0;
	while(fgets(chA, sizeof(chA), file_A)){
		A[n] = atoi(chA);
		printf("%d\n", A[n]);
		n++;
	}

	fclose(file_A);

	/* File ref_B.txt */
	FILE *file_B = fopen("./src/ref_B.txt", "r");
	exit_if(file_B == NULL, "Error opening ref_B.txt\n");

	int B[MAX_VALUE] = {};

	n = 0;
	while(fgets(chB, sizeof(chB), file_B)){
		B[n] = atoi(chB);
		printf("%d\n", B[n]);
		n++;
	}

	fclose(file_B);

	/* File resu_C.txt */
	FILE *file_rC = fopen("./src/resu_C.txt", "w");
	exit_if(file_rC == NULL, "Error opening resu_C.txt\n");

	int rC[MAX_VALUE] = {};

	for(int a = 0; a < MAX_VALUE; a++)
	{
		rC[a] = PGCD(A[a], B[a]);
		printf("%d\n", rC[a]);
		fprintf(file_rC, "%d\n", rC[a]);
	}

	fclose(file_rC);

	printf("(II) End of PGCD program\n");
  return 0;
}
