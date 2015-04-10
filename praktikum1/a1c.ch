#include <math.h>
#include <chplot.h>
#define h 0.001
#define x_End 0.2

double Ableitung(double x, double y){
	return 10-500*y+5000*x;
}

int main(){
	int steps = x_End/h;
	int i;
	double x[steps],y[steps];
	x[0] = 0; 
	y[0] = 1;
	for(i=0;i<steps-1;i++){
		double k1 = h * Ableitung(x[i],y[i]);
		double k2 = h * Ableitung(x[i]+h/2,y[i]+k1/2);
		y[i+1] = y[i] + k2;
		x[i+1] = x[i] + h;
	}
	class CPlot plot;
	plot.data2D(x,y);
	plot.plotting();
}