#include <math.h>
#include <chplot.h>
#define h 0.001
#define x_End 31 

double
Ableitung1(double y1,
		   double y2)
{
  return 6 *(1 - y2 * y2) * y1 - y2;
}

double
Ableitung2(double y1)
{
  return y1;
}

void 
eu(CPlot *plot)
{
  int steps = x_End/h;
  int n;
  double x[steps],
         y1[steps],
		 y2[steps];
  x[0] = 0; 
  y1[0] = 1;
  y2[0] = 0;
  for (n = 0; n < steps-1; n++)
  {
	y1[n+1] = y1[n] + h * Ableitung1(y1[n], y2[n]);
	y2[n+1] = y2[n] + h * Ableitung2(y1[n]);
	x[n+1] = x[n] + h;
  }
  plot->data2D(x, y2);
}

void
rk2(CPlot *plot)
{

  int steps = x_End/h;
  int n;
  double x[steps],
         y1[steps],
	  	 y2[steps];
  x[0] = 0; 
  y1[0] = 1;
  y2[0] = 0;
  for (n = 0; n < steps-1; n++)
  {
    double k1,
		   k2,
		   l1,
		   l2;

    k1 = h * Ableitung1(y1[n], y2[n]);
    l1 = h * Ableitung2(y1[n]);
	k2 = h * Ableitung1(y1[n] + l1/2, y2[n] + l1/2);
	l2 = h * Ableitung2(y1[n] + k1/2);

	y1[n+1] = y1[n] + k2;
	y2[n+1] = y2[n] + l2;
	x[n+1] = x[n] + h;
  }
  plot->data2D(x, y2);
}

int
main(void)
{
  CPlot plot;
  eu(&plot);
  plot.legend("Euler", 0);
  rk2(&plot);
  plot.legend("RK2", 1);
  plot.plotting();
  return 0;
}
