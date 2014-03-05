#include <stdlib.h>	
#include <stdio.h>
#include <math.h>

double trapezis(double a, double b, int n);

double fun(double x);




int main(void){

  double a, b;
  int i;

  printf("Introdueixi l'inici de l'interval de la funcio (a): ");
  scanf("%lf", &a);

  printf("\n Introdueixi el final de l'interval (b): ");
  scanf("%lf", &b);

  for (i=1; i<=1000; i+=10){
    printf("\n Per a n=%d I=%lf", i, trapezis(a, b, i));
  }
return 0;
}


double trapezis(double a, double b, int n){
  double h, sum, x, resultat;
  int j;

  h=(b-a)/n;
  sum=0;
  x=a;

  for (j=1; j<n; j++){
    x+=h;
    sum+=fun(x);
  }

  resultat= h*(0.5*fun(a)+sum+0.5*fun(b));

  return resultat;
}

double fun(double x){
  return sqrt(x);
}