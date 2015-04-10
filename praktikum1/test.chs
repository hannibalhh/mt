#include <math.h>
#include <chplot.h>
#define h 0.02
#define x_End 1

double Ableitung(double x, double y){
	return -x/y;
}

int main(){
	int steps = x_End/h;
	int i;
	double x[steps],y[steps];
	x[0] = 0; 
	y[0] = 1;
	for(i=0;i<steps-1;i++){
		y[i+1] = y[i] + h*Ableitung(x[i],y[i]);
		x[i+1] = x[i] + h;
	}

	class CPlot plot = new CPlot;
	plot.data2D(x,y);
	plot.plotting();
  	getchar(); // needed for windows only 
}