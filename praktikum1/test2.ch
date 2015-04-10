  #include <math.h>
    #include <chplot.h>
    int main() {
        int numpoints = 36;
        array double x[numpoints], y[numpoints];
        class CPlot plot;

        lindata(0, 360, x, 36);
        y = sin(x*M_PI/180);
        plotxy(x, y, "Ch plot", "xlabel", "ylabel", &plot);

        /* create a postscript file */
        plot.outputType(PLOT_OUTPUTTYPE_FILE, "postscript eps", "demo.eps");
        plot.plotting();

        /* create a png file */
        plot.outputType(PLOT_OUTPUTTYPE_FILE, "png color", "demo.png");
        plot.plotting();
    }