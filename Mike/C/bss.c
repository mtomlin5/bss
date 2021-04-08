#include <stdio.h>
#include "data.h"
#include <math.h>

float f(float x){
	return x*x*x;
}

float g(float x){
	return tanh((double) x);
}

void print_max(float x[][], int N){
	int i,j;
	for (int i = 0; i < N; ++i)
	{
		for (int c = 0; c < N; ++c)
		{
			/* code */
		}
	}
}

int main() {
   float mu = 5e-6;

   float mC[3][3] = {
    {  0, -0.1, -0.1},
    {-0.1,   0, -0.1},
    {-0.1, -0.1, 1  }
   };

   float s[3] = {0,0,0};
   float e[3];

   int i,c,j;

   for (i = 0; i < 2; ++i)
   {
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