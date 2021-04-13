#include <stdio.h>
#include "data.h"
#include "bss.h"

//Update to use pointers instead of hardcoding 3?
void print_mat(float x[][3], int N){
	int i,j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			printf("%f ", x[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
   //mC = I-C
   float mC[3][3] = {
    {  1, -0.1, -0.1},
    {-0.1,   1, -0.1},
    {-0.1, -0.1, 1  }
   };

   bss(de00,e10, e01,N,mC);
   print_mat(mC, 3);
   

   return 0;
}