#include <stdio.h>
#include <graphics.h>

int sign(int n)
{
    if(n < 0)
        return -1;
    if(n > 0)
        return 1; 
    
    return 0;
}

int main()
{
    int x1, y1, x2, y2;
    int dx, dy; 
    int steps; 
    int x, y; 
    
    printf("\nEnter X1, Y1 \n");
    scanf("%d %d", &x1, &y1);

    printf("\nEnter X2, Y2 \n");
    scanf("%d %d", &x2, &y2);

    dx = (x2 - x1);
    dy = (y2 - y1);

    if(dx > dy)
        steps = dx; 
    else 
        steps = dy; 

    dx = dx/steps; 
    dy = dy/ steps; 

    x = x1 + (0.5 * sign(dx));
    y = x2  + (0.5 * sign(dy));

    int gd, gm; 
    initgraph(&gd, &gm, NULL);
    for(int i =0; i<=steps; i++)
    {
        putpixel(x, y, 1);
        x += dx; 
        y += dy;
    }
    getchar(); 
    closegraph();

}