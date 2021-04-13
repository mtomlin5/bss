#include <stdio.h>
//#include "data.h"
//#include <math.h>
#include "bss.h"
#include "atan.h"

float f(float x){
	return x*x*x;
}

float atan_lookup(float x){
   int i;
   int isNegative;
   if (x < 0){
      isNegative = 1;
      x = x * -1;
   }

   if (x>=128){
      if (isNegative){
         return -1.57;
      }
      else{
         return 1.57;
      }
   }
   while (atan_in[i] < x){
      i++;
   }
   if (i > 0){
      i = i-1;
   }

   if (isNegative) {
      return -1*atan_out[i];
   }
   return atan_out[i];
}

float g(float x){
   //return atan((double)x);
   printf("%f\n", x);
   return atan_lookup(x);
}
// void print_mat(float x[][3], int N){
//    int i,j;
//    for (i = 0; i < N; ++i)
//    {
//       for (j = 0; j < 3; ++j)
//       {
//          printf("%f ", x[i][j]);
//       }
//       printf("\n");
//    }
//    printf("\n");
// }
/*float g(float x){
   int i;
   int isnegative = 0;
   if (x < 0) {
      isnegative = 1;
   }
   if (x > 128){
      if (isnegative){
      return -1.57;
      }
      else {
         return 1.57;
      }
   }
   for (i = 0;i++;i<128){
         if (x<= atan_in[i]){
            break;
         }
      }
   if (isnegative){
      return atan_out[i]*-1.0;
   }
   else {
      return atan_out[i];
   }
}*/

// void print_mat2(float x[][3], int N){
//    int i,j;
//    for (i = 0; i < N; ++i)
//    {
//       for (j = 0; j < 3; ++j)
//       {
//          printf("%f ", x[i][j]);
//       }
//       printf("\n");
//    }
//    printf("\n");
// }

void bss(const float de00[],const float e10[],const float e01[],const int N,float mC[3][3]) {
   float mu = 5e-6;

   //mC = I-C
   
   float s[3] = {0,0,0};
   float e[3];

   int i,c,j;

   for (i = 0; i < N; ++i)
   {
         // if (i < 10){
         //    printf("%d\n", i);
         //    print_mat2(mC,3);
         // }

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

}