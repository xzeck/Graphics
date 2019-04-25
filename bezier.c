#include <graphics.h>
#include <stdio.h>
#include <math.h>


void drawBezierCurve(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3)
{
    double u  = 0.0001; 
    double steps = 0.00001; 
    float x, y;
    for(float i = 0.0001; i<=steps; i++)
    {
         x = (pow((1-u), 3) * x0) + (3 * pow((1-u),2) * u * x1) + (3 * (1-u) * pow(u, 2) *x2) + (pow(u,3) * x3);
         y =  (pow((1-u), 3) * y0) + (3 * pow((1-u),2) * u * y1) + (3 * (1-u) * pow(u, 2) *y2) + ( pow(u,3) * y3);

        putpixel(x, y, 1);
    }
}

int main()
{
    int gd, gm; 
    float x0, y0, x1, y1, x2, y2, x3, y3; 

    printf("\nEnter X0 X1");
    scanf("%f%f", &x0, &y0);

    printf("\nEnter X1 X1");
    scanf("%f%f", &x1, &y1);

    printf("\nEnter X1 X2");
    scanf("%f%f", &x2, &y2);

    printf("\nEnter X3 X3");
    scanf("%f%f", &x3,  &y3);

    initgraph(&gd, &gm, "");
    drawBezierCurve(x0, y0, x1, y1, x2, y2, x3, y3);

    getchar();
    closegraph();
}