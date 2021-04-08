#include <stdio.h>
#include "data.h"
#include <math.h>

float f(float x){
	return x*x*x;
}

float g(float x){
	return tanh((double) x);
}

float mat_sub()

int main() {
   float mu = 5e-6;

   float C[3][3] = {
    {  0, 0.1, 0.1},
    {0.1,   0, 0.1},
    {0.1, 0.1, 0  }
   };

   float dC[3][3] = {
    {  0, 0.1, 0.1},
    {0.1,   0, 0.1},
    {0.1, 0.1, 0  }
   };

   float I[3][3] = {
    {  1, 0, 0},
    {0,   1, 0},
    {0, 0, 1}
   };



   float S[1][3] = {0,0,0};

   for (int i = 0; i < N; ++i)
   {
   	
   }





   return 0;
}