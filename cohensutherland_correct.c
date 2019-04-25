#include<stdio.h>
#include<graphics.h>
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int vxmin, vymin, vxmax, vymax;

int regionCode(int x, int y){
	int code = INSIDE;
	if(x < vxmin)
    	code |= LEFT;
	if(x > vxmax)
    	code |= RIGHT;
	if(y < vymin)
    	code |= BOTTOM;
	if(y > vymax)
    	code |= TOP;
	return code;
}
void clip(int x1, int y1, int x2, int y2){
	int code1, code2, accept = 0, code;
	float x, y, m;
	int gd = DETECT, gm;
	code1 = regionCode(x1, y1);
	code2 = regionCode(x2, y2);
	m = (float)(y2 - y1) / (x2 - x1);
	while(1){
    	if(code1 == 0 && code2 == 0){
        	accept = 1;
        	break;
    	}else if(code1 & code2)
        	break;
    	else{
        	if(code1)
            	code = code1;
        	else
            	code = code2;
        	if(code & LEFT){
            	y = (m * (vxmin - x1)) + y1;
            	x = vxmin;
        	}else if(code & RIGHT){
            	y = (m * (vxmax - x1)) + y1;
            	x = vxmax;
        	}else if(code & TOP){
            	x = ((vymax - y1) / m) + x1;
            	y = vymax;
        	}else if(code & BOTTOM){
            	x = ((vymin - y1) / m) + x1;
            	y = vymin;
        	}
        	if(code == code1){
            	x1 = x;
            	y1 = y;
            	code1 = regionCode(x1, y1);
        	}else{
            	x2 = x;
            	y2 = y;
            	code2 = regionCode(x2, y2);
        	}
    	}
	}
	initgraph(&gd, &gm, NULL);
	rectangle(vxmin, vymin, vxmax, vymax);
	if(accept)
    	line(x1, y1, x2, y2);
	getch();
	closegraph();
}
int main(){
	int x1, x2, y1, y2;
	
	printf("Enter Coordinates of 1st point: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter Coordinates of 2nd point: ");
	scanf("%d %d", &x2, &y2);
	printf("Enter Diagonally Opposite Corner points: ");
	scanf("%d %d %d %d", &vxmin, &vymin, &vxmax, &vymax);
	clip(x1, y1, x2, y2);
	return 0;
}