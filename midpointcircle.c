#include <stdio.h>
#include <graphics.h>

void drawCircle(int x1, int y1, int radius)
{
    int x, y; 
    float d; 

    x = 0; 
    y = radius; 
    
    d = 1.25 - radius; 

    while(x < y)
    {
        putpixel(x+ x1, y + y1, 1);
        putpixel(x+ x1, -y + y1, 1);
        putpixel(-x+ x1, y + y1, 1);
        putpixel(-x+ x1, -y + y1, 1);

          putpixel(y+ x1, x + y1, 1);
        putpixel(y+ x1, -x + y1, 1);
        putpixel(-y+ x1, x + y1, 1);
        putpixel(-y+ x1, -x + y1, 1);

        if(d < 0)
        {
            x++;
            d += ((2 *x) +1);
        }else
        {
            x++;
            y--;
            d += (2 * (x - y) + 1);
        }
    }
}
int main()
{
    int x, y; 
    int radius; 
    int gd, gm; 

    printf("\nEnter X and Y\n");
    scanf("%d %d", &x, &y);

    printf("\nEnter radius\n");
    scanf("%d", &radius);

    initgraph(&gd, &gm, NULL);
    drawCircle(x, y, radius);
    getchar();
    closegraph();
}