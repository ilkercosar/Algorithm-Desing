#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>


float randomValue(void)
{
	return (float)rand() / (float) RAND_MAX;
}

typedef struct pedometer
{
	float aX;
	float aY;
	float aZ;
	float v;
	uint16_t threshold;
}pedometer;

void initPedometer(struct pedometer P)
{
	P.aX = 0;
	P.aY = 0;
	P.aZ = 0;
	P.threshold = 1000;
	P.v = 0;
}

float getMagnitude(struct pedometer P)
{
	P.v = sqrtf(P.aX * P.aX + P.aY * P.aY + P.aZ * P.aZ);
	return P.v;
}

typedef struct gaussFilter
{
	float gauss;
	float sigma;
}gaussFitler;


void filterInit(struct gaussFilter F)
{
	F.sigma = 1.0;
	F.gauss = 0.0;
}

float filter(struct gaussFilter F, float data)
{
	F.gauss = 1.0 * exp(((pow(data, 2)) / ((2 * pow(F.sigma, 2)))) * (-1));
	return F.gauss;
}




int main(int* argc, char* argv[])
{
	struct pedometer Pedometer = { 0 };
	struct gaussFilter Filter = { 0 }; 

	uint16_t counting = 0;

	initPedometer(Pedometer);
	
	float x = Pedometer.aX;
	float y = Pedometer.aY;
	float z = Pedometer.aZ;

	float magnitude = getMagnitude(Pedometer);

	x = filter(Filter, x);
	y = filter(Filter, y);
	z = filter(Filter, z);
	magnitude = filter(Filter, magnitude);

	if (magnitude >= Pedometer.threshold)
	{
		counting++;
		printf("step : %d", counting);
	}

	return 1;

}