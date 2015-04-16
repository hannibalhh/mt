#include <math.h>
#include <chplot.h>
#define h 0.002
#define x_End 120 

double
AbleitungX(double x,
		   double y)
{
  return (-10. * (x - y));
}

double
AbleitungY(double x,
		   double y,
		   double z)
{
  return ((40. - z) * x - y);
}


double
AbleitungY2(double x,
		    double y,
		    double z)
{
  return ((40.000000001 - z) * x - y);
}

double
AbleitungZ(double x,
		   double y,
		   double z)
{
  return (x * y - 2.67 * z);
}

void
rk2(CPlot *plot)
{
  int steps = x_End/h;
  int n;
  double x[steps],
         y[steps],
	  	 z[steps],
  		 t[steps];
  x[0] = 0.01; 
  y[0] = 0.01;
  z[0] = 0.0;
  t[0] = 0.;
  for (n = 0; n < steps-1; n++)
  {
    double k1x,
		   k1y,
		   k1z,
		   k2x,
		   k2y,
		   k2z;

    k1x = h * AbleitungX(x[n], y[n]);
	k1y = h * AbleitungY(x[n], y[n], z[n]);
    k1z = h * AbleitungZ(x[n], y[n], z[n]);

	k2x = h * AbleitungX(x[n] + k1x/2, y[n] + k1y/2);
	k2y = h * AbleitungY(x[n] + k1x/2, y[n] + k1y/2, z[n] + k1z/2);
	k2z = h * AbleitungZ(x[n] + k1x/2, y[n] + k1y/2, z[n] + k1z/2);

	x[n+1] = x[n] + k2x;
	y[n+1] = y[n] + k2y;
	z[n+1] = z[n] + k2z;
	t[n+1] = t[n] + h;
  }
  plot->data2D(t, x);
  plot->data2D(x, z);
}


void
rk22(CPlot *plot)
{
  int steps = x_End/h;
  int n;
  double x[steps],
         y[steps],
	  	 z[steps],
  		 t[steps];
  x[0] = 0.01; 
  y[0] = 0.01;
  z[0] = 0.0;
  t[0] = 0.;
  for (n = 0; n < steps-1; n++)
  {
    double k1x,
		   k1y,
		   k1z,
		   k2x,
		   k2y,
		   k2z;

    k1x = h * AbleitungX(x[n], y[n]);
	k1y = h * AbleitungY2(x[n], y[n], z[n]);
    k1z = h * AbleitungZ(x[n], y[n], z[n]);

	k2x = h * AbleitungX(x[n] + k1x/2, y[n] + k1y/2);
	k2y = h * AbleitungY2(x[n] + k1x/2, y[n] + k1y/2, z[n] + k1z/2);
	k2z = h * AbleitungZ(x[n] + k1x/2, y[n] + k1y/2, z[n] + k1z/2);

	x[n+1] = x[n] + k2x;
	y[n+1] = y[n] + k2y;
	z[n+1] = z[n] + k2z;
	t[n+1] = t[n] + h;
  }
  plot->data2D(t, x);
}


int
main(void)
{
  CPlot plot;
  rk2(&plot);
  //rk22(&plot);
  plot.legend("1", 0);
  plot.legend("2", 1);
  plot.plotting();
  return 0;
}
