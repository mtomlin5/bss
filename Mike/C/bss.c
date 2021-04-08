#include <stdio.h>
#include "data.h"
#include <math.h>

float f(float x){
	return x*x*x;
}

float g(float x){
	return atan((double) x);
}

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
   float mu = 5e-6;

   //mC = I-C
   float mC[3][3] = {
    {  1, -0.1, -0.1},
    {-0.1,   1, -0.1},
    {-0.1, -0.1, 1  }
   };

   float s[3] = {0,0,0};
   float e[3];

   int i,c,j;

   for (i = 0; i < N; ++i)
   {
   		printf("iter %d\n", i);
   		print_mat(mC, 3);


   		e[0] = de00[i];
   		e[1] = e10[i];
   		e[2] = e01[i];

   		for (c = 0; c < 3; ++c)
   		{
   			s[c] = mC[c][0] * e[0] + mC[c][1] * e[1] + mC[c][2] * e[2];
   		}

   		for (c = 0; c < 3; ++c)
   		{
   			for (j = 0; j < 3; ++j)
   			{
   				if (c != j) 
   				{
   					mC[c][j] = mC[c][j] - (mu * f(s[c]) * g(s[j]));
   				}
   			}
   		}

   }





   return 0;
}