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

int swap_data(int *a, int *b)
{
    int temp  = *a; 
    *a = *b;
    *b = temp;
}

int main()
{
    int x1, y1, x2, y2; 
    int dx, dy;
    int swap = 0;
    int s1, s2; 
    int x, y;
    int gd, gm;  
    int e;

    printf("\nEnter X1 and Y1");
    scanf("%d%d", &x1, &y1);

    printf("\nEnter X2 and Y2");
    scanf("%d%d", &x2, &y2);

    dx = abs(x2 - x1); 
    dy = abs(y2 - y1); 

    s1 = sign(x2 - x1);
    s2 = sign(y2 - y1);

    x=x1; 
    y=y1; 

    if(dy > dx)
    {
        swap_data(&dx, &dy);
        swap = 1;
    }
    
    e = (2 * dx) -dy;

    initgraph(&gd, &gm, "");

    for(int i =0; i<dx; i++)
    {
        putpixel(x, y, 1);
        while(e <= 0)
        {
            if(swap)
                x +=s1; 
            else 
                y += s2; 

            e = 2 *dx; 
        }
        if(swap)
            y+=s2; 
        else
            x += s1; 
        e =2 * dy;
    }

    getchar();
    closegraph();
}