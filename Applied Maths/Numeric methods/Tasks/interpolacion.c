#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define tol 1e-7

int difdiv(double *x, double *f, int n);
double trapezis(double a, double b, int n);
double richardson(double a,double b, int n, int m);
double biseccio( double a ,double b, double precision );
double f( double x );
int difdivherm(double *x, double *f, int n);
double horner(double z, double *x, double *c, int n);

int main()
{

}

int difdiv(double *x, double *f, int n)
{
    int i,k;
    
    for( k = 1; k <= n; k++)
    {
         for( i = n; i >= k; i--)
         {
              double den = (x[i] - x[i-k]);
              printf("%g\n",den);
              if( fabs(den) > tol )
              {
                  f[i] = (f[i]-f[i-1]) / den;
              }
              else
              {
                  return 1;
              }  
         }
    }
    
    return 0;
}

double trapezis(double a, double b, int n)
{
       int i;
       
       double h = (b-a)/n;
       
       double sum = (f(a) + f(b))/2;
       
       for( i=1; i <= n-1; i++)
       {
            sum += f(a+i*h);
       }
       
       return h*sum;
}

double richardson(double a,double b, int n, int m)
{
       double* aprox = (double*) malloc( (m+1)*sizeof(double) );
       
       int k,i;
       
       for( i =0 ; i <= m; i++)
       {
            aprox[i] = trapezis(a,b,pow(2,i)*n);
            if( i > 0 && fabs(aprox[i]-aprox[i-1]) < tol )
            {
                return aprox[i];
            }
            printf("%d %d %e\n", 0, i, aprox[i]);
       }
       for( k=1; k <=m ; k++)
       {
            for( i = m; i >=k; i--)
            {
                 aprox[i] = aprox[i] + 1/(pow(4,k)-1)*(aprox[i]-aprox[i-1]);
                 printf("%d %d %e\n", k, i, aprox[i]);
                 if( i < m && fabs(aprox[i]-aprox[i+1]) < tol )
                 {
                     printf("fin");
                     return aprox[i];
                 }
            }
       }
       
       printf("se ha llegado al maximo de iteraciones");
       return 1;
}

double biseccio( double a , double b , double precision)
{
       double c;
       
       while( fabs(b-a) > precision )
       {
              c = (a+b)/2;
              
              if( f(c) * f(a) <= 0 )
              {
                  b = c;
              }
              else
              {
                  a = c;
              }
       }
       
       return c;
}
              
double f( double x )
{
       return x*x*x+1;
}

int difdivherm(double *x, double *f, int n){

	int i, k, m;
	m = 2*n + 1;
	

	for(i = m-1; i>=2; i = i - 2){
			if((x[i]-x[i-1])<PRE){
                return  -1;
				
			}
			f[i] = (f[i]-f[i-2])/(x[i]-x[i-1]);
	}

	for(k = 2; k < m+1; k++){
		for(i = m; i >= k; i--){
			if((x[i]-x[i-k])<PRE){
				return  -1;
			}
			f[i] = (f[i]-f[i-1])/(x[i]-x[i-k]);
		}
	}
	return 0;

}

double horner (double z, double *x, double *c, int n){
  double p;
  int i;
  p = c[n];

  for(i = n-1; i >= 0; i--) {
    p = p*(z - x[i]) + c[i];
  }
	
  return p;



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
