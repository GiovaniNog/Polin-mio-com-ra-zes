#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int grau, i, j, np, ndiv;
double raiz[50], x, xa, xb, h, fx, dfx, deltax, produto;

double px(double x, double raiz[50], int grau);
double dpx(double x, double raiz[50], int grau);

FILE *ent = fopen("pol02.raiz.1","r");
FILE *sai = fopen("pol02.raiz.2","w");

int main()
{
    fscanf(ent,"%d",&grau);

    for(i=1; i<=grau; i++)
    {
        fscanf(ent,"%lf",&raiz[i]);
    }

    fscanf(ent,"%lf",&xa);
    fscanf(ent,"%lf",&xb);
    fscanf(ent,"%d",&np);

    deltax = xb - xa;
    ndiv = np - 1;
    h = deltax / ndiv;

    x = xa;

    fprintf(sai,"     x          f(x)        df(x)\n");

    for(i=1; i<=np; i++)
    {
        fx = px(x, raiz, grau);
        dfx = dpx(x, raiz, grau);

        fprintf(sai,"%10.4f  %10.4f  %10.4f\n",x,fx,dfx);

        x = x + h;
    }

    fclose(ent);
    fclose(sai);

    return 0;
}

double px(double x, double raiz[50], int grau)
{
    double fx = 1.0;
    int i;

    for(i=1; i<=grau; i++)
    {
        fx = fx * (x - raiz[i]);
    }

    return fx;
}

double dpx(double x, double raiz[50], int grau)
{
    double dfx = 0.0;
    int i, j;

    for(i=1; i<=grau; i++)
    {
        produto = 1.0;

        for(j=1; j<=grau; j++)
        {
            if(i != j)
            {
                produto = produto * (x - raiz[j]);
            }
        }

        dfx = dfx + produto;
    }

    return dfx;
}
