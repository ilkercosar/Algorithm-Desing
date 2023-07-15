#include <stdio.h>
#include <stdlib.h>

size_t vectorSize(float *v1, float *v2)
{
	const size_t sizeV1 = sizeof(v1) / sizeof(v1[0]);
	const size_t sizeV2 = sizeof(v2) / sizeof(v2[0]);
	
	if (sizeV1 == sizeV2) return sizeV1;
	else				  return -1;
}

size_t justOneSize(float* v)
{
	const size_t size = sizeof(v) / sizeof(v[0]);
	return size;
}

float fastSquareRoot(const float val)
{
	union {
		int i;
		float j;
	}w;

	w.j = val;
	w.i = (1 << 29) + (w.i >> 1) - (1 << 22);

	w.j = w.j + val / w.j;
	w.j = 0.25f * w.j + val / w.j;

	return w.j;
}

int fastSquare(int x) {
	int result = x;
	result <<= 1;
	result |= x;
	result <<= 1;
	return result;
}

float vectorAdd(float* v1, float* v2)
{
	const size_t size = vectorSize(v1, v2);

	if (size != -1)
	{
		float* w = (float*)malloc(1 * sizeof(float));
		size_t wSize = 1;

		for (int i = 0; i < size; i++)
		{
			w[i] = v1[i] + v2[i];
			if (size >= wSize)
			{
				wSize++;
				w = (float*)realloc(w, wSize * sizeof(float));
			}
			
		}
		return *w;
	}

	else
	{
		printf("vectors size are not equals");
		return 0;
	}
}

float vectorSub(float* v1, float* v2)
{
	const size_t size = vectorSize(v1, v2);

	if (size != -1)
	{
		float* w = (float*)malloc(1 * sizeof(float));
		size_t wSize = 1;

		for (int i = 0; i < size; i++)
		{
			w[i] = v1[i] - v2[i];
			if (size >= wSize)
			{
				wSize++;
				w = (float*)realloc(w, wSize * sizeof(float));
			}

		}
		return *w;
	}

	else
	{
		printf("vectors size are not equals");
		return 0;
	}
}

float scalarMultiply(float* v1, float scalar)
{
	size_t vSize = justOneSize(v1);
	float* w = (float*)malloc(vSize* sizeof(float));

	for (int i = 0; i < vSize; i++)
	{
		w[i] = v1[i] * scalar;
	}
	return *w;
}

float dotProduct(float* v1, float* v2)
{
	const size_t size = vectorSize(v1, v2);
	if (size != -1)
	{
		float* w = (float*)malloc(size * sizeof(float));
		float sum = 0;
		for (int i = 0; i < size; i++)
		{
			w[i] = v1[i] * v2[i];
			sum += w[i];
		}

		free(w);

		return sum;
	}
	else
	{
		printf("vectors size are not equal");
		return 0;
	}

}

float magnitude(float* v)
{
	const size_t size = justOneSize(v);
	float pop = 0;

	for (int i = 0; i < size; i++)
	{
		pop += fastSquare(v[i]);
	}

	pop = fastSquareRoot(pop);

	return pop;
}

float multiply(float* v1, float* v2)
{
	const size_t size = vectorSize(v1, v2);
	if (size != -1)
	{
		float* w = (float*)malloc(size * sizeof(float));
		for (int i = 0; i < size; i++)
		{
			w[i] = v1[i] * v2[i];
		}

		return *w;
	}

	else 
	{
		printf("vectors are not equal");
		return 0;
	}
}

int main()
{
	float vector1[3] = { 1.3, 2.4, 5.3 };
	float vector2[3] = { 3.1, 6.9, 9.0 };

	printf("vector sum : %2.0f", vectorAdd(vector1, vector2));

	return 0;
}