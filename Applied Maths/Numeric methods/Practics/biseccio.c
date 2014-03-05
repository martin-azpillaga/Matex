#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 0

double f(double x);
double biseccio (double a, double b, double prec);


int main (void){
  double a,b,z;
  double prec= 0.0000001;

  printf("Introdueixi l'inici de l'interval de la funcio (a): ");
  scanf("%lf", &a);

  printf("\n Introdueixi el final de l'interval (b): ");
  scanf("%lf", &b);
  if(f(a)*f(b)>0){
    printf("No es pot assegurar que la funcio tingui 0s en aquest interval");
    return 0;
  }
  z = biseccio(a,b,prec);
  
  printf(" el valor z tal que f(z) = 0 és z=%lf", z);
  return 0; 
}
double biseccio(double a, double b, double prec){
  double c;
  c= (b+a)/2.;
  if ((b-a)<prec){
    return c;
  }else{
    if(f(a)*f(c)<=0){
      return biseccio(a,c,prec);
    }else{
      return biseccio(c,b,prec);
    } 
  }
}

double f(double x){
  return x-sin(x)-M;
}