#include<stdio.h>
#include<math.h>

int main(){
	double x1, x2, y1, y2;

	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	
	double x = (x2-x1);
	x *= x;
	double y = (y2-y1);
	y *= y;

	printf("%.4lf\n", sqrt(x+y));
	return 0;
}
