#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

const int focalAngle = 60;

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

int main(int argc, char* argvc)
{

    const int width = GetSystemMetrics(SM_CXSCREEN);
    const int height = GetSystemMetrics(SM_CYSCREEN);

    printf("Screen width: %d\n", width);
    printf("Screen height: %d\n", height);

    const int cW = width / 2;
    const int cH = height / 2;

    const float pixelToAngle = focalAngle / fastSquareRoot(fastSquare (width) + fastSquare(height));

    while (1)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            volatile POINT p;
            GetCursorPos(&p);
            printf("Left mouse button pressed at x=%d, y=%d\n", p.x, p.y);
            float xAngle = (p.x - cW) * pixelToAngle;
            float yAngle = (p.y - cH) * pixelToAngle;

            print("X and Y angles are x = %d, y=%d\n", xAngle, yAngle);
        }
    }

	return 0;
}