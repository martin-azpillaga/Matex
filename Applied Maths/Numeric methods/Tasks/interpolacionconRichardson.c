#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define tol 1e-7

int difdiv(double *x, double *f, int n);
int cambiobase(double *x, double *f, int n);
double trapezis(double a, double b, int n);
double fun(double x);
double richardson(double a,double b, int n, int m);

int main()
{
    
    double x[4] = {0,1,2,3};
    double f[4] = {0,1,4,9};
    int res;
    /*
    res = difdiv(x,f,3);
    res += cambiobase(x,f,3);
    printf("%g %g %g %g %d", f[0],f[1],f[2],f[3],res);
    */
    printf("%g\n", trapezis(0,2,2));
    
    double integral = richardson(0,2,1,3); 
    printf("%g",integral);
    scanf("%lf",&x[1]);
    return 0;
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
       
       double sum = (fun(a) + fun(b))/2;
       
       for( i=1; i <= n-1; i++)
       {
            sum += fun(a+i*h);
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
    
double fun(double x)
{
       return x*x;
}
int cambiobase( double *x, double *f, int n)
{
    int i,j,k;
    
    double* coef = (double*) malloc( n*sizeof(double));
    double* res = (double*) malloc( n*sizeof(double));
    
    coef[0] = 1;
    res[0] = f[0];
    
    for( i = 1; i < n; i++)
    {
         coef[i] = 0;
         res[i] = 0;
    }
    
    for( j = 1; j < n; j++)
    {              
         for( k=j-1; k >=1; k--)
         {
              coef[k] = coef[k]*x[j-1]*(-1) + coef[k-1] ;
              printf("%g %g \n", j,coef[k]);
              res[k] += f[j]*coef[k]; 
         }
         coef[0] = coef[0] * x[j-1]*(-1);
         res[0] += f[j]*coef[0];
         
    }
    
    for( i=0; i<n;i++)
    {
         f[i] = res[i];
    }
    return 0;
}