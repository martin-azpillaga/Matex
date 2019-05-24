#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int interprecurr(double *x, double *f, double *c, int n);


int main (void){
  double *x, *f, *c;
  int n, i;
  n=3;
  x=(double*)malloc(sizeof(double)*n);
  f=(double*)malloc(sizeof(double)*n);
  c=(double*)malloc(sizeof(double)*n);
  
  x[0]=-1;
  x[1]=1;
  x[2]=2;
  x[3]=2.5;
  f[0]=-10;
  f[1]=4;
  f[2]=0.5;
  f[3]=-1.25;
  interprecurr(x, f, c, n);
  for (i=0; i<=n; i++){
    printf("%lf ", c[i]);
  }
  return 0;
}

int interprecurr(double *x, double *f, double *c, int n){
  
  int i, j;
  double aux, aux2;
  
  c[0]=f[0];
  c[1]=(f[1]-c[0])/(x[1]-x[0]);

  for (i=2; i<=n; i++){
    aux=1;
    aux2=c[0];
    for (j=1; j<=i-1; j++){
      aux*=(x[i]-x[j-1]);
      aux2+=(c[j]*aux);
    }
    c[i]=(f[i]-aux2)/(aux*(x[i]-x[i-1]));
  }
  return 0;
}