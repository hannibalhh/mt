#include <math.h>
#include <chplot.h>
#define h 0.001
#define x_End 31

enum color_t {
  LINE_COLOR_RED=1,
  LINE_COLOR_GREEN,
  LINE_COLOR_BLUE,
  LINE_COLOR_MAGENTA, LINE_COLOR_DARKBLUE, LINE_COLOR_DARKRED, LINE_COLOR_DARKCYAN,
  LINE_COLOR_BLACK,
  LINE_COLOR_GREY51, LINE_COLOR_SPRINGREEN, LINE_COLOR_YELLOW4, LINE_COLOR_DARKMAGENTA, // dark magenta
  LINE_COLOR_GREY76,
  LINE_COLOR_CYAN1,
  LINE_COLOR_YELLOW
};

double Ableitung(double y1, double y2){
	return 6 * (1-pow(y2,2)) * y1 - y2;
}

void eufunc(CPlot *plot){
	int line_width = 1, datasetnum = 0; enum color_t color=LINE_COLOR_RED;
	int steps = x_End/h;
	int i;
	double x[steps],y[steps];
	x[0] = 0; 
	y[0] = 1;
	for(i=0;i<steps-1;i++){
		y[i+1] = y[i] + h*Ableitung(y[i],x[i]);
		x[i+1] = x[i] + h * y[i];
	}
	plot->data2D(x,y); 
	plot->plotType(PLOT_PLOTTYPE_LINES, datasetnum, color, line_width);
}


int main(){	
	CPlot plot;
	eufunc(&plot);
	//(&plot);
	plot.plotting();
}