//#include <stdio.h>
//#include "data.h"
//#include <math.h>
#include "bss.hh"
#include "atan.hh"

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
