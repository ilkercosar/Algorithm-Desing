#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int points[2][2];
int counter = 0;


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

float computeDistance() 
{
    float distance = 0;
    float dX = 0;
    float dY = 0;

    dX = points[1][0] - points[0][0];
    dX *= dX;

    dY = points[1][1] - points[0][1];
    dY *= dY;

    distance = dX + dY;
    fastSquareRoot(distance);
    
    return (distance);
}
int main(int argc, char* argv)
{
 
    while (1)
    {
        if (GetAsyncKeyState(VK_LBUTTON)) 
        {
            POINT p;
            GetCursorPos(&p);
            printf("Left mouse button pressed at x=%d, y=%d\n", p.x, p.y);
            
            if (counter == 0)
            {
                points[0][0] = p.x;
                points[0][1] = p.y;
            }

            if (counter == 1)
            {
                points[1][0] = p.x;
                points[1][1] = p.y;
                
                counter = 0;

                printf("Distance : %f", computeDistance());

                break;
            }  
            counter++;
           
        }        
    }
    
	return 0;
}