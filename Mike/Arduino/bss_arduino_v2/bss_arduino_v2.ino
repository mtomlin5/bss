//#include "/home/mike/Documents/projects/repos/bss/Mike/C_v2/bss.h"
//#include "/home/mike/Documents/projects/repos/bss/Mike/C_v2/data.h"

#include "data.hh"
#include "bss.hh"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void print_mat(float x[][3], int N){
  int i,j;
  for (i = 0; i < N; ++i)
  {
    for (j = 0; j < 3; ++j)
    {
      Serial.print(x[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }
  Serial.println();
}

void bss(const float de00[],const float e10[],const float e01[],const int N,float mC[3][3]) {
   float mu = 5e-6;

   //mC = I-C
   

   float s[3] = {0,0,0};
   float e[3];

   int i,c,j;

   for (i = 0; i < 10; ++i)
   {
        Serial.println(i);
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

}

void loop() {
  // put your main code here, to run repeatedly:
  String input = Serial.readString();
  if (input=="go"){
    Serial.println("Starting");
     float mC[3][3] = {
      {  1, -0.1, -0.1},
      {-0.1,   1, -0.1},
      {-0.1, -0.1, 1  }
     };
   Serial.println(N);
   bss(de00,e10, e01,N,mC);
   print_mat(mC, 3);
   Serial.println("Finished");
  }
}
