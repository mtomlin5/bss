#include "atan.h"
#include <stdio.h>

float atan_lookup(float x){
	int i;
	int isNegative;
	if (x < 0){
		isNegative = 1;
		x = x * -1;
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

int main(){
	float x = 5;
	printf("%f\n", x);
	float y;
	y = atan_lookup(x);
	printf("%f\n", y);

	float i = -20.0;
	while (i < 20) {
		y = atan_lookup(i);
		printf("%f\n", y);
		i++;
	}



}

